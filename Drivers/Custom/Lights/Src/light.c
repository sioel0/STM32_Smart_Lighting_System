/*
 * light.c
 *
 *  Created on: Jul 26, 2024
 *      Author: leoni
 */

#include "light_i2c.h"
#include "light.h"
#include "main.h"
#include "sensors_light_sensor.h"
#include "sensors_movement_sensor.h"
#include "stm32f4xx_hal.h"
#include <string.h>

extern TIM_HandleTypeDef htim4;
extern TIM_HandleTypeDef htim9;

static uint8_t all_on[18] = {
		0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF,
		0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF,
};

static uint8_t all_off[18] = {
		0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
		0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
};

static uint8_t light_on = 0;
static uint8_t check_light_level = 0;

void light_power_on() {
	if(light_i2c_write_single_register(MATRIX_FUNCTION_REGISTER, SHUTDOWN_REGISTER, TURN_ON) == HAL_BUSY) {
		Error_Handler();
	}
}

void light_shutdown() {
	if(light_i2c_write_single_register(MATRIX_FUNCTION_REGISTER, SHUTDOWN_REGISTER, SHUTDOWN) == HAL_BUSY) {
		Error_Handler();
	}
}

void light_default_state(uint8_t intensity) {
	if (light_i2c_write_single_register(MATRIX_FUNCTION_REGISTER,
			CONFIGURATION_REGISTER, PICTURE_MODE) == HAL_BUSY) {
		Error_Handler();
	}
	if (light_i2c_write_single_register(MATRIX_FUNCTION_REGISTER,
			PICTURE_DISPLAY_REGISTER, MATRIX_FRAME1) == HAL_BUSY) {
		Error_Handler();
	}
	if (light_i2c_write_single_register(MATRIX_FUNCTION_REGISTER,
			DISPLAY_OPTION_REGISTER,
			DISPLAY_OPTIONS(INDEPENDENT_INTENSITY, BLINK_DISABLED, 0))
			== HAL_BUSY) {
		Error_Handler();
	}
	// setup frame1 to be all on but without outputting light
	light_turn_on_frame(MATRIX_FRAME1);
	light_set_intensity(MATRIX_FRAME1, intensity);
}

void light_init() {
	light_default_state(DEFAULT_LIGHT_INTENSITY);
	light_turn_off_frame(MATRIX_FRAME1);

	// initialize frames 2-8 to have a smooth transition when someone is passing by
	light_turn_on_frame(MATRIX_FRAME2);
	light_turn_on_frame(MATRIX_FRAME3);
	light_turn_on_frame(MATRIX_FRAME4);
	light_turn_on_frame(MATRIX_FRAME5);
	light_turn_on_frame(MATRIX_FRAME6);
	light_turn_on_frame(MATRIX_FRAME7);
	light_turn_on_frame(MATRIX_FRAME8);
	light_set_intensity(MATRIX_FRAME2, 105);
	light_set_intensity(MATRIX_FRAME3, 130);
	light_set_intensity(MATRIX_FRAME4, 155);
	light_set_intensity(MATRIX_FRAME5, 180);
	light_set_intensity(MATRIX_FRAME6, 205);
	light_set_intensity(MATRIX_FRAME7, 230);
	light_set_intensity(MATRIX_FRAME8, MAX_LIGHT_INTENSITY);
	light_power_on();
}

void light_turn_on_frame(uint8_t frame) {
	if(light_i2c_send_data(frame, LED_CONTROL_START, all_on, sizeof(all_on)) == HAL_BUSY) {
			Error_Handler();
	}
}

void light_turn_off_frame(uint8_t frame) {
	if(light_i2c_send_data(MATRIX_FRAME1, LED_CONTROL_START, all_off, sizeof(all_off)) == HAL_BUSY) {
		Error_Handler();
	}
}

void light_set_intensity(uint8_t frame, uint8_t intensity) {
	if(intensity <= MAX_LIGHT_INTENSITY) {
		uint8_t pwm[144];
		memset(pwm, intensity, 144);
		light_i2c_send_data(frame, PWM_CONTROL_START, pwm, sizeof(pwm));
	}
}

void light_transition_to_max() {
	light_shutdown();
	// enable auto play mode
	if(light_i2c_write_single_register(MATRIX_FUNCTION_REGISTER, CONFIGURATION_REGISTER, AUTOPLAY_MODE(AUTOFRAME_MODE, MATRIX_FRAME1)) == HAL_BUSY) {
		Error_Handler();
	}
	// set number of loops
	if(light_i2c_write_single_register(MATRIX_FUNCTION_REGISTER, AUTOPLAY_CONTROL_REGISTER1, AUTOPLAY_MODE_CONFIG(LOOPS_FRAMES1, LOOPS_FRAMES7)) == HAL_BUSY) {
		Error_Handler();
	}
	// setup loop delay
	if(light_i2c_write_single_register(MATRIX_FUNCTION_REGISTER, AUTOPLAY_CONTROL_REGISTER2, AUTOPLAY_DELAY_CONFIG(30)) == HAL_BUSY) { // ~330 ms per step
		Error_Handler();
	}
	light_power_on();
}

uint8_t light_is_on() {
	return light_on;
}

void light_activate() {
	light_on = 1;
	sensors_light_sensor_start();
	check_light_level = 1;
	htim4.Instance->SR &= ~TIM_SR_UIF;
	HAL_TIM_Base_Start_IT(&htim4);
}

void light_deactivate() {
	light_on = 0;
	HAL_TIM_Base_Stop_IT(&htim4);
}

void light_level_check() {
	check_light_level = 1;
}

void light_main() {
	static uint8_t default_state = 1;
	static uint8_t current_light = 0;
	static uint8_t movement_detection_reacted = 0;
	if(light_on) {
		if(sensors_movement_is_detected()) {
			if(!movement_detection_reacted) {
				light_transition_to_max();
				movement_detection_reacted = 1;
				htim9.Instance->SR &= ~TIM_SR_UIF;
				HAL_TIM_Base_Start_IT(&htim9);
			} else { // reset the timer
				HAL_TIM_Base_Stop_IT(&htim9);
				htim9.Instance->SR &= ~TIM_SR_UIF;
				HAL_TIM_Base_Start_IT(&htim9);
			}
			default_state = 0;
		} else {
			if(check_light_level){
				uint32_t ambient_light = sensors_light_get_ambient_light_level();
				if(ambient_light <= 500) {
					current_light = DEFAULT_LIGHT_INTENSITY;
				} else if (ambient_light <= 1000) {
					current_light = 80;
				} else if (ambient_light <= 1500) {
					current_light = 60;
				} else if (ambient_light <= 2000) {
					current_light = 40;
				} else if (ambient_light <= 2500) {
					current_light = 20;
				} else {
					current_light = 10;
				}
				check_light_level = 0;
			}
			if(!default_state) {
				light_default_state(current_light);
				default_state = 1;
			} else {
				light_set_current_intensity(current_light);
			}
			movement_detection_reacted = 0;
		}
	}
}
