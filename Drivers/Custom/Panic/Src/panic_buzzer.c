/*
 * panic_buzzer.c
 *
 *  Created on: Jul 17, 2024
 *      Author: leoni
 */

#include "panic_buzzer.h"
#include "stm32f4xx_hal.h"
#include <stdint.h>


uint8_t panic_buzzer_active = 0; /** Panic buzzer status */
uint8_t panic_buzzer_counter = 0; /** Used to keep count of how many times the buzzer has been turned on */

/*
 * @brief Starts the panic buzzer
 * This function is used to turn on the panic buzzer and make it sound
 * @retval None
 */
void panic_buzzer_start() {
	HAL_GPIO_WritePin(PANIC_BUZZER, GPIO_PIN_SET);
	panic_buzzer_active = 1;
	panic_buzzer_counter++;
}

/*
 * @brief Stops the panic buzzer
 * This function is used to stop any sound make by the panic buzzer
 * @retval None
 */
void panic_buzzer_stop() {
	HAL_GPIO_WritePin(PANIC_BUZZER, GPIO_PIN_RESET);
	panic_buzzer_active = 0;
}

/*
 * @brief Yells the panic buzzer status
 * This function is a getter for the panic_buzzer_active variable
 * @retval the panic_buzzer_active current value
 */
uint8_t panic_buzzer_is_active() {
	return panic_buzzer_active;
}

/*
 * @brief Yells how many times the buzzer has been activated
 * This function is a getter for the panic_buzzer_counter variable
 * @retval the panic_buzzer_counter current value
 */
uint8_t panic_buzzer_get_counter() {
	return panic_buzzer_counter;
}

/*
 * @brief Sets the panic buzzer counter to 0
 * This function resets the panic_buzzer_counter to zero, this is used to restart the emergency sound sequence
 * a complete sequence lasts 5 sounds.
 * @retval None
 */
void panic_buzzer_reset_counter() {
	panic_buzzer_counter = 0;
}
