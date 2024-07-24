/*
 * sensors_light_sensor.h
 *
 *  Created on: Jul 23, 2024
 *      Author: leoni
 */

#include <stdint.h>
#include "stm32f4xx_hal.h"

extern ADC_HandleTypeDef hadc1;

#ifndef CUSTOM_SENSORS_INCLUDE_SENSORS_LIGHT_SENSOR_H_
#define CUSTOM_SENSORS_INCLUDE_SENSORS_LIGHT_SENSOR_H_

#define SENSORS_LIGHT_SENSOR_ADC &hadc1
#define SENSORS_LIGHT_SENSOR_INACTIVE 0x11111111 // max uint32_t value

uint32_t sensors_light_get_ambient_light_level();
void sensors_light_sensor_start();
void sensors_light_sensor_stop();
uint8_t sensors_light_sensor_is_active();

#endif /* CUSTOM_SENSORS_INCLUDE_SENSORS_LIGHT_SENSOR_H_ */
