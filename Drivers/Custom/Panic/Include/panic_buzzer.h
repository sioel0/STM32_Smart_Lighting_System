/*
 * panic_buzzer.h
 *
 *  Created on: Jul 17, 2024
 *      Author: leoni
 */

#include "stm32f4xx_hal.h"
#include <stdint.h>

#ifndef CUSTOM_PANIC_INCLUDE_PANIC_BUZZER_H_
#define CUSTOM_PANIC_INCLUDE_PANIC_BUZZER_H_

/* -------- Defines -------- */
#define PANIC_BUZZER_PIN GPIO_PIN_7
#define PANIC_BUZZER_GPIO GPIOE
#define PANIC_BUZZER PANIC_BUZZER_GPIO, PANIC_BUZZER_PIN

/* -------- Functions -------- */
void panic_buzzer_start();
void panic_buzzer_stop();
uint8_t panic_buzzer_is_active();
uint8_t panic_buzzer_get_counter();
void panic_buzzer_reset_counter();

#endif /* CUSTOM_PANIC_INCLUDE_PANIC_BUZZER_H_ */
