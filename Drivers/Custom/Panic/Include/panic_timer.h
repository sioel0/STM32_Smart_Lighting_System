/**
 * @file panic_timer.h
 * @author sioel0
 * @brief This file contains all the necessary functions to interact with the timer which is used by the panic module to trigger buzzer sounds
 */
#ifndef CUSTOM_PANIC_INCLUDE_PANIC_TIMER_H_
#define CUSTOM_PANIC_INCLUDE_PANIC_TIMER_H_

#include "stm32f4xx_hal.h"
#include <stdint.h>

extern TIM_HandleTypeDef htim3;

#define PANIC_TIMER &htim3 /** Panic timer id */

/**
 * @brief Make the panic timer start
 */
void panic_timer_start();
/**
 * @brief Turn off the panic timer
 */
void panic_timer_stop();
/**
 * @brief This function is used to acknowledge if the panic timer is currently running
 * @return 1 if it is running 0 otherwise
 */
uint8_t panic_timer_is_active();
/**
 * @brief This function is used to check if the timer is elapsed
 * @return 1 if the timer is elapsed 0 otherwise
 */
uint8_t panic_timer_is_elapsed();
/**
 * @brief This function is used to tell that the panic timer is elapsed
 */
void panic_timer_elapsed();
/**
 * @brief This timer is used to reset the elapsed variable after a proper reaction has been triggered
 */
void panic_timer_is_elapsed_reset();

#endif /* CUSTOM_PANIC_INCLUDE_PANIC_TIMER_H_ */
