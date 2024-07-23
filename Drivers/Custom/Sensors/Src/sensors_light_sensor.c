/*
 * sensors_light_sensor.c
 *
 *  Created on: Jul 23, 2024
 *      Author: leoni
 */

#include "sensors_light_sensor.h"
#include <stdint.h>
#include "stm32f4xx_hal.h"

uint8_t light_sensor_active = 0;

/*
 * @brief Reads current ambient light level from the sensor
 * @retval current ambient light level
 */
uint32_t sensors_light_get_ambient_light_level() {
	return light_sensor_active ?
			HAL_ADC_GetValue(SENSORS_LIGHT_SENSOR_ADC) :
			SENSOR_LIGHT_SENSOR_INACTIVE;
}

/*
 * @brief Starts the ADC interface to make it possible to read ambient light level
 * @retval None
 */
void sensors_light_sensor_start() {
	HAL_ADC_Start(SENSORS_LIGHT_SENSOR_ADC);
	light_sensor_active = 1;
}

/*
 * @brief Stops the ADC interface
 * This function stops the ADC interface sampling, this way it is possible
 * to reduce the power consumption.
 * @retval None
 */
void sensors_light_sensor_stop() {
	HAL_ADC_Stop(SENSORS_LIGHT_SENSOR_ADC);
	light_sensor_active = 0;
}

/*
 * @brief Getter for the light_sensor_active variable
 * This function is used to check if the ADC is active and it is possible
 * to get ambient light level
 * @retval light_sensor_active current value
 */
uint8_t sensor_light_sensor_is_active() {
	return light_sensor_active;
}
