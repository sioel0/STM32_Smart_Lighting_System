/*
 * panic_button.c
 *
 *  Created on: Jul 17, 2024
 *      Author: sioel0
 */

#include <stdint.h>
#include "panic_button.h"
#include "stm32f4xx_hal.h"

/* -------- Global variables -------- */
uint8_t panic_button_pressed = 0;

/* -------- Functions -------- */

/*
 * @brief This function reacts to button press
 * All this function does is setting the button_pressed global
 * variable to true to trigger the reaction of the other modules
 * that need this information
 * @retval None
 */
void panic_button_set() {
	panic_button_pressed = 1;
}

/*
 * @brief Called to reset the panic button_pressed status
 * This function resets the button_pressed global variable to stop
 * the panic procedure execution
 * @retval None
 */
void panic_button_reset() {
	panic_button_pressed = 0;
}

/**
  * @brief  EXTI line detection callbacks.
  * @param  GPIO_Pin Specifies the pins connected EXTI line
  * @retval None
  */
void HAL_GPIO_EXTI_Callback(uint16_t GPIO_Pin) {
	if(GPIO_Pin == PANIC_BUTTON_PIN) {
		panic_button_set();
	}
}
