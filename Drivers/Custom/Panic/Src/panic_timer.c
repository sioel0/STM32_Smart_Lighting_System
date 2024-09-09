/*
 * panic_timer.c
 *
 *  Created on: Jul 18, 2024
 *      Author: leoni
 */

#include "stm32f4xx_hal.h"
#include "panic_buzzer.h"
#include "panic_timer.h"
#include <stdint.h>

static uint8_t timer_active = 0; /** Panic timer activation status */
static uint8_t timer_elapsed = 0; /** Panic timer elapsed event interrupt request triggered */

void panic_timer_start() {
	HAL_TIM_Base_Start_IT(PANIC_TIMER);
	timer_active = 1;
	panic_buzzer_reset_counter();
}

void panic_timer_stop() {
	HAL_TIM_Base_Stop_IT(PANIC_TIMER);
	timer_active = 0;
	panic_buzzer_reset_counter();
}

uint8_t panic_timer_is_active() {
	return timer_active;
}

uint8_t panic_timer_is_elapsed() {
	return timer_elapsed;
}

void panic_timer_elapsed() {
	timer_elapsed = 1;
}

void panic_timer_is_elapsed_reset() {
	timer_elapsed = 0;
}
