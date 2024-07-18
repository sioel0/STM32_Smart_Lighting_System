/*
 * panic_timer.h
 *
 *  Created on: Jul 17, 2024
 *      Author: leoni
 */

#ifndef CUSTOM_PANIC_INCLUDE_PANIC_TIMER_H_
#define CUSTOM_PANIC_INCLUDE_PANIC_TIMER_H_

#include "stm32f4xx_hal.h"

extern TIM_HandleTypeDef htim3;

#define PANIC_TIMER &htim3

void panic_timer_start();
void panic_timer_stop();

#endif /* CUSTOM_PANIC_INCLUDE_PANIC_TIMER_H_ */
