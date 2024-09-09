/**
 * @file sensors_movement_sensor.h
 * @author sioel0
 * @brief This file contains all the functions used to interact with the device ambient light detection sensor
 */

#include "stm32f4xx_hal.h"
#include <stdint.h>

#ifndef CUSTOM_SENSORS_INCLUDE_MOVEMENT_SENSOR_H_
#define CUSTOM_SENSORS_INCLUDE_MOVEMENT_SENSOR_H_

#define MOVEMENT_SENSOR_GPIO GPIOC
#define MOVEMENT_SENSOR_PIN GPIO_PIN_9
#define MOVEMENT_SENSOR MOVEMENT_SENSOR_GPIO, MOVEMENT_SENSOR_PIN
/**
 * @brief This function is used to tell that some movement has been detected
 */
void sensors_movement_detected();
/**
 * @brief This function is used to acknowledge if any movement has been detected
 * @return 1 if movement has been detected 0 otherwise
 */
uint8_t sensors_movement_is_detected();
/**
 * @brief This function is used to reset the movement detection state after a proper reaction has been triggered
 */
void sensors_movement_detected_reset();
/**
 * @brief This function is used to turn on the movement detection sensor
 */
void sensors_movement_sensor_on();
/**
 * @brief This function is used to turn off the movement detection sensor
 */
void sensors_movement_sensor_off();

#endif /* CUSTOM_SENSORS_INCLUDE_MOVEMENT_SENSOR_H_ */
