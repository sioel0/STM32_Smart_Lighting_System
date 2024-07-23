/*
 * panic_timer.c
 *
 *  Created on: Jul 18, 2024
 *      Author: leoni
 */

#include "stm32f4xx_hal.h"
#include "panic_buzzer.h"
#include "panic_timer.h"
#include <stdint.h>

uint8_t panic_timer_active = 0; /** Panic timer activation status */
uint8_t panic_timer_elapsed = 0; /** Panic timer elapsed event interrupt request triggered */

/*
 * @brief This function make the panic timer start
 * All this function does is making the panic timer start and activate its interrupt triggering
 * @retval None
 */
void panic_timer_start() {
	HAL_TIM_Base_Start_IT(PANIC_TIMER);
	panic_timer_active = 1;
	panic_buzzer_reset_counter();
}

/*
 * @brief This function makes the panic timer stop
 * All this function does is making the panic timer stop and deactivates timer's interrupt triggering
 * @retval None
 */
void panic_timer_stop() {
	HAL_TIM_Base_Stop_IT(PANIC_TIMER);
	panic_timer_active = 0;
	panic_buzzer_reset_counter();
}

/*
 * @brief This function is the callback triggered when timer elapsed interrupt is managed
 * Inside this function the panic_timer_elapsed variable is set to 1 to request the interrupt management
 * @retval None
 */
void HAL_TIM_PeriodElapsedCallback(TIM_HandleTypeDef *htim) {
	panic_timer_elapsed = 1;
}

/*
 * @brief Yells if the panic timer is active
 * @retval panic_timer_active variable value
 */
uint8_t panic_timer_is_active() {
	return panic_timer_active;
}

/*
 * @brief Tells if a interrupt request has been triggered by timer elapsed event
 * @retval panic_timer_elapsed variable value
 */
uint8_t panic_timer_is_elapsed() {
	return panic_timer_elapsed;
}

/*
 * @brief Resets the panic_timer_elapsed variable
 * This function sets panic_timer_elapsed variable back to 0 meaning that the interrupt request has been managed
 * @retval None
 */
void panic_timer_is_elapsed_reset() {
	panic_timer_elapsed = 0;
}
