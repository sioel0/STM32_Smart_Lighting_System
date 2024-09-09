/*
 * panic.c
 *
 *  Created on: Jul 17, 2024
 *      Author: leoni
 */

#include "panic_button.h"
#include "panic_buzzer.h"
#include "panic.h"
#include "stm32f4xx_hal.h"
#include <stdint.h>

static uint8_t panic_on = 0;

uint8_t panic_is_active() {
	return panic_on;
}

void panic_activate() {
	panic_on = 1;
	HAL_NVIC_SetPriority(EXTI0_IRQn, 0, 0);
	HAL_NVIC_EnableIRQ(EXTI0_IRQn);
}

void panic_deactivate() {
	panic_on = 0;
	HAL_NVIC_DisableIRQ(EXTI0_IRQn);
}

void panic_init() {
	panic_activate();
}

void panic_main() {
	if(panic_on) {
		if(panic_button_is_pressed()) {
			if(panic_buzzer_is_active()) { // panic_button pressed with buzzer active
				panic_buzzer_stop();
				panic_timer_stop();
			} else if(panic_timer_is_active()) { // panic_button pressed with timer active but buzzer inactive
				panic_timer_stop();
			} else { // panic_button pressed for the first time
				panic_timer_start();
				panic_buzzer_start();
				panic_button_reset();
			}
		} else if(panic_timer_is_active()) { // turn on and off the buzzer (normal mode)
			if(panic_timer_is_elapsed()) {
				if(panic_buzzer_is_active()) {
					panic_buzzer_stop();
				} else {
					if(panic_buzzer_get_counter() == 5) {
						panic_timer_stop();
					} else {
						panic_buzzer_start();
					}
				}
				panic_timer_is_elapsed_reset();
			}
		} else {
			// do nothing
		}
	} else {
		// do nothing
	}
}

