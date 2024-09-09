/*
 * movement_sensor.c
 *
 *  Created on: Jul 22, 2024
 *      Author: leoni
 */

#include <stdint.h>
#include "sensors_movement_sensor.h"
#include "stm32f4xx_hal.h"

uint8_t movement_sensor_detected = 0;


void sensors_movement_detected() {
	movement_sensor_detected = 1;
}

uint8_t sensors_movement_is_detected() {
	return movement_sensor_detected;
}

/*
 * @brief Resets movement_sensor_detected to 0
 * This function is used to tell that the interrupt has been correctly served
 * by resetting the associated variable
 * @retval None
 */
void sensors_movement_detected_reset() {
	movement_sensor_detected = 0;
}

/*
 * @brief Enable movement sensor interrupt detection
 * @retval None
 */
void sensors_movement_sensor_on() {
	HAL_NVIC_SetPriority(EXTI9_5_IRQn, 0, 0);
	HAL_NVIC_EnableIRQ(EXTI9_5_IRQn);
}

/*
 * @brief Disable movement sensor interrupt detection
 * @retval None
 */
void sensors_movement_sensor_off() {
	HAL_NVIC_DisableIRQ(EXTI9_5_IRQn);
}
