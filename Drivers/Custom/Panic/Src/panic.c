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

extern uint8_t panic_button_pressed;
extern uint8_t panic_buzzer_active;
extern uint8_t panic_timer_active;
extern uint8_t panic_buzzer_counter;
extern uint8_t timer_elapsed;

void panic_main() {
	if(panic_button_pressed) {
		if(panic_buzzer_active) { // panic_button pressed with buzzer active
			panic_buzzer_stop();
			panic_timer_stop();
		} else if(panic_timer_active) { // panic_button pressed with timer active but buzzer inactive
			panic_timer_stop();
		} else { // panic_button pressed for the first time
			panic_timer_start();
			panic_buzzer_start();
			panic_button_reset();
		}
	} else if(panic_timer_active) { // turn on and off the buzzer (normal mode)
		if(timer_elapsed) {
			if(panic_buzzer_active) {
				panic_buzzer_stop();
			} else {
				if(panic_buzzer_counter == 5) {
					panic_timer_stop();
				} else {
					panic_buzzer_start();
				}
			}
			timer_elapsed = 0;
		}
	} else {
		// do nothing
	}
}

