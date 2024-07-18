/*
 * panic_timer.c
 *
 *  Created on: Jul 18, 2024
 *      Author: leoni
 */

#include "stm32f4xx_hal.h"
#include "panic_timer.h"
#include <stdint.h>

uint8_t panic_timer_active = 0;
uint8_t timer_elapsed = 0;
extern uint8_t panic_buzzer_counter;

void panic_timer_start() {
	HAL_TIM_Base_Start_IT(PANIC_TIMER);
	panic_timer_active = 1;
}

void panic_timer_stop() {
	HAL_TIM_Base_Stop_IT(PANIC_TIMER);
	panic_timer_active = 0;
	panic_buzzer_counter = 0;
}

void HAL_TIM_PeriodElapsedCallback(TIM_HandleTypeDef *htim) {
	timer_elapsed = 1;
}
