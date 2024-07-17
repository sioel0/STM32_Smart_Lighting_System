/*
 * panic_buzzer.c
 *
 *  Created on: Jul 17, 2024
 *      Author: leoni
 */

#include "panic_buzzer.h"
#include "stm32f4xx_hal.h"

void panic_buzzer_start() {
	HAL_GPIO_WritePin(PANIC_BUZZER_GPIO, PANIC_BUZZER_PIN, GPIO_PIN_SET);
}

void panic_buzzer_stop() {
	HAL_GPIO_WritePin(PANIC_BUZZER_GPIO, PANIC_BUZZER_PIN, GPIO_PIN_RESET);
}
