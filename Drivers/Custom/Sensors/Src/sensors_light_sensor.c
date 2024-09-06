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
	uint32_t ambient_light = SENSORS_LIGHT_SENSOR_INACTIVE;
	if(light_sensor_active) {
		HAL_ADC_Start(SENSORS_LIGHT_SENSOR_ADC);
		if(HAL_ADC_PollForConversion(SENSORS_LIGHT_SENSOR_ADC, 10) == HAL_OK) {
			ambient_light = HAL_ADC_GetValue(SENSORS_LIGHT_SENSOR_ADC);
			HAL_ADC_Stop(SENSORS_LIGHT_SENSOR_ADC);
		}
	}
	return ambient_light;
}

/*
 * @brief Sets the light_sensor_active variable to 1 telling that it is possible to check the light intensity value
 * @retval None
 */
void sensors_light_sensor_start() {
	light_sensor_active = 1;
}

/*
 * @brief Sets the light_sensor_active variable to 0 telling that it is not possible to check the light intensity value
 * @retval None
 */
void sensors_light_sensor_stop() {
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
