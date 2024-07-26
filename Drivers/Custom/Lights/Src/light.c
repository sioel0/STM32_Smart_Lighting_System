/*
 * light.c
 *
 *  Created on: Jul 26, 2024
 *      Author: leoni
 */

#include "light_i2c.h"
#include "light.h"
#include "main.h"
#include <string.h>

static uint8_t all_on[18] = {
		0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF,
		0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF,
};

static uint8_t all_off[18] = {
		0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
		0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
};

void light_power_on() {
	if(light_i2c_write_single_register(MATRIX_PG9, SHUTDOWN_REGISTER, TURN_ON) == HAL_BUSY) {
		Error_Handler();
	}
}

void light_shutdown() {
	if(light_i2c_write_single_register(MATRIX_PG9, SHUTDOWN_REGISTER, SHUTDOWN) == HAL_BUSY) {
		Error_Handler();
	}
}

void light_init() {
	light_power_on();
	HAL_Delay(100);
	if(light_i2c_write_single_register(MATRIX_PG9, CONFIGURATION_REGISTER, PICTURE_MODE) == HAL_BUSY) {
		Error_Handler();
	}
	HAL_Delay(100);
	if(light_i2c_write_single_register(MATRIX_PG9, PICTURE_DISPLAY_REGISTER, FRAME1) == HAL_BUSY) {
		Error_Handler();
	}
	HAL_Delay(100);
	if(light_i2c_write_single_register(MATRIX_PG9, DISPLAY_OPTION_REGISTER, DISPLAY_OPTIONS(INDEPENDENT_INTENSITY,BLINK_DISABLED,0)) == HAL_BUSY) {
		Error_Handler();
	}
}

void light_turn_on() {
	if(light_i2c_send_data(MATRIX_PG1, LED_CONTROL_START, all_on, sizeof(all_on)) == HAL_BUSY) {
			Error_Handler();
	}
	//light_i2c_send_data(MATRIX_PAGE2, LED_CONTROL_START, all_on, sizeof(all_on));
	//light_i2c_send_data(MATRIX_PAGE3, LED_CONTROL_START, all_on, sizeof(all_on));
	//light_i2c_send_data(MATRIX_PAGE4, LED_CONTROL_START, all_on, sizeof(all_on));
	//light_i2c_send_data(MATRIX_PAGE5, LED_CONTROL_START, all_on, sizeof(all_on));
	//light_i2c_send_data(MATRIX_PAGE6, LED_CONTROL_START, all_on, sizeof(all_on));
	//light_i2c_send_data(MATRIX_PAGE7, LED_CONTROL_START, all_on, sizeof(all_on));
	//light_i2c_send_data(MATRIX_PAGE8, LED_CONTROL_START, all_on, sizeof(all_on));
}

void light_turn_off() {
	if(light_i2c_send_data(MATRIX_PG1, LED_CONTROL_START, all_off, sizeof(all_off)) == HAL_BUSY) {
		Error_Handler();
	}
}

void light_set_intensity(uint8_t intensity) {
	uint8_t pwm[144];
	memset(pwm, intensity, 144);
	light_i2c_send_data(MATRIX_PG1, PWM_CONTROL_START, pwm, sizeof(pwm));
}
