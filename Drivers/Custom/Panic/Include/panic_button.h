/*
 * panic_button.h
 *
 *  Created on: Jul 17, 2024
 *      Author: sioel0
 */


#include "stm32f4xx_hal.h"
#include <stdint.h>

#ifndef CUSTOM_PANIC_INCLUDE_PANIC_BUTTON_H_
#define CUSTOM_PANIC_INCLUDE_PANIC_BUTTON_H_

/* -------- Defines -------- */
// to be defined based on pinout configuration
#define PANIC_BUTTON_GPIO GPIOD
#define PANIC_BUTTON_PIN GPIO_PIN_0

/* -------- Functions -------- */
void panic_button_set();
void panic_button_reset();

#endif /* CUSTOM_PANIC_INCLUDE_PANIC_BUTTON_H_ */
