/**
 * @file sensors_light_sensor.h
 * @author sioel0
 * @brief This file contains all the necessary functions to make the ambient light sensor work
 */
#ifndef CUSTOM_SENSORS_INCLUDE_SENSORS_LIGHT_SENSOR_H_
#define CUSTOM_SENSORS_INCLUDE_SENSORS_LIGHT_SENSOR_H_

#include <stdint.h>
#include "stm32f4xx_hal.h"

extern ADC_HandleTypeDef hadc1;

#define SENSORS_LIGHT_SENSOR_ADC &hadc1 /** ADC interface that is used to get ambient light level */
#define SENSORS_LIGHT_SENSOR_INACTIVE 0x11111111 /** Light level returned if the light sensors is inactive */

/*
 * @brief Reads current ambient light level from the sensor
 * return current ambient light level
 */
uint32_t sensors_light_get_ambient_light_level();
/*
 * @brief Sets the light_sensor_active variable to 1 telling that it is possible to check the light intensity value
 */
void sensors_light_sensor_start();
/*
 * @brief Sets the light_sensor_active variable to 0 telling that it is not possible to check the light intensity value
 */
void sensors_light_sensor_stop();

/*
 * @brief This fucntion is used to acknowledge if the ambient sensor is currently working
 * @return 1 if it is active 0 otherwise
 */
uint8_t sensors_light_sensor_is_active();

#endif /* CUSTOM_SENSORS_INCLUDE_SENSORS_LIGHT_SENSOR_H_ */
