/**
 * @file panic_button.h
 * @author sioel0
 * @brief This file contains all the necessary functions to make the panic button work
 */

#ifndef CUSTOM_PANIC_INCLUDE_PANIC_BUTTON_H_
#define CUSTOM_PANIC_INCLUDE_PANIC_BUTTON_H_

#include "stm32f4xx_hal.h"
#include <stdint.h>

#define PANIC_BUTTON_GPIO GPIOD /** Panic button gpio interface */
#define PANIC_BUTTON_PIN GPIO_PIN_0 /** Panic button pin */

/**
 * @brief This function is used to indicate that the button has been pressed
 */
void panic_button_set();
/**
 * @brief This function is used to indicate that all the necessary reactions has been triggered after button press
 */
void panic_button_reset();
/**
 * @brief This function is used to acknowledge if the button has been pressed
 * @return 1 if the button has been pressed 0 otherwise
 */
uint8_t panic_button_is_pressed();

#endif /* CUSTOM_PANIC_INCLUDE_PANIC_BUTTON_H_ */
