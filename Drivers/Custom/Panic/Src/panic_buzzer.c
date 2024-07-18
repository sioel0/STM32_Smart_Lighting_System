/*
 * panic_buzzer.c
 *
 *  Created on: Jul 17, 2024
 *      Author: leoni
 */

#include "panic_buzzer.h"
#include "stm32f4xx_hal.h"
#include <stdint.h>

uint8_t panic_buzzer_active = 0;
uint8_t panic_buzzer_counter = 0;

void panic_buzzer_start() {
	HAL_GPIO_WritePin(PANIC_BUZZER, GPIO_PIN_SET);
	panic_buzzer_active = 1;
	panic_buzzer_counter++;
}

void panic_buzzer_stop() {
	HAL_GPIO_WritePin(PANIC_BUZZER, GPIO_PIN_RESET);
	panic_buzzer_active = 0;
}
