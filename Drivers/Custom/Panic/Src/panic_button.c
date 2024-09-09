/*
 * panic_button.c
 *
 *  Created on: Jul 17, 2024
 *      Author: sioel0
 */

#include <stdint.h>
#include "panic_button.h"
#include "stm32f4xx_hal.h"

uint8_t panic_button_pressed = 0;

void panic_button_set() {
	panic_button_pressed = 1;
}

void panic_button_reset() {
	panic_button_pressed = 0;
}

uint8_t panic_button_is_pressed() {
	return panic_button_pressed;
}
