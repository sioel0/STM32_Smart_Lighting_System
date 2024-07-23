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
uint8_t panic_button_pressed = 0; /** Used to store the interrupt request status by the panic button */

/* -------- Functions -------- */

/*
 * @brief This function is used to point out that an interrupt request has been triggered by a button press
 * All this function does is setting the button_pressed global
 * variable to true to trigger the reaction of the other modules
 * that need this information
 * @retval None
 */
void panic_button_set() {
	panic_button_pressed = 1;
}

/*
 * @brief This function is used to reset the panic button interrupt request variable, this means that the interrupt has been managed
 * This function resets the button_pressed global variable to stop
 * the panic procedure execution
 * @retval None
 */
void panic_button_reset() {
	panic_button_pressed = 0;
}

/*
 * @brief This function is used to check if an panic button interrupt has been triggered
 * @retval panic_button_pressed variable value which tells if an interrupt on button's EXTI line has been triggered
 */
uint8_t panic_button_is_pressed() {
	return panic_button_pressed;
}
