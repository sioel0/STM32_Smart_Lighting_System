/**
 * @file panic_buzzer.h
 * @author sioel0
 * @brief This file contains all the necessary functions to make the panic buzzer work
 */

#ifndef CUSTOM_PANIC_INCLUDE_PANIC_BUZZER_H_
#define CUSTOM_PANIC_INCLUDE_PANIC_BUZZER_H_

#include "stm32f4xx_hal.h"
#include <stdint.h>

#define PANIC_BUZZER_PIN GPIO_PIN_7 /** Panic buzzer pin */
#define PANIC_BUZZER_GPIO GPIOE /** Panic buzzer gpio port */
#define PANIC_BUZZER PANIC_BUZZER_GPIO, PANIC_BUZZER_PIN /** Panic buzzer identifier, this can be used in HAL function as GPIO, PIN */

/**
 * @brief Make the panic buzzer start making noise
 */
void panic_buzzer_start();
/**
 * @brief Make the panic buzzer stop making noise
 */
void panic_buzzer_stop();
/**
 * @brief This function is used to acknowledge if the panic buzzer is currently making noise
 * @return 1 if it is making noise 0 otherwise
 */
uint8_t panic_buzzer_is_active();
/**
 * @brief Returns how many times the panic buzzer has emitted some noise, this value is in [0-5]
 */
uint8_t panic_buzzer_get_counter();
/**
 * @brief This function is used to set the buzzer counter back to 0
 */
void panic_buzzer_reset_counter();

#endif /* CUSTOM_PANIC_INCLUDE_PANIC_BUZZER_H_ */
