/*
 * panic_timer.h
 *
 *  Created on: Jul 17, 2024
 *      Author: leoni
 */

#include "stm32f4xx_hal.h"
#include <stdint.h>

extern TIM_HandleTypeDef htim3;

#ifndef CUSTOM_PANIC_INCLUDE_PANIC_TIMER_H_
#define CUSTOM_PANIC_INCLUDE_PANIC_TIMER_H_

#define PANIC_TIMER &htim3

void panic_timer_start();
void panic_timer_stop();
uint8_t panic_timer_is_active();
uint8_t panic_timer_is_elapsed();
void panic_timer_elapsed();
void panic_timer_is_elapsed_reset();

#endif /* CUSTOM_PANIC_INCLUDE_PANIC_TIMER_H_ */
