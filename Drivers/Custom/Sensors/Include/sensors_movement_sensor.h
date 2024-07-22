/*
 * movement_sensor.h
 *
 *  Created on: Jul 22, 2024
 *      Author: leoni
 */

#include "stm32f4xx_hal.h"

#ifndef CUSTOM_SENSORS_INCLUDE_MOVEMENT_SENSOR_H_
#define CUSTOM_SENSORS_INCLUDE_MOVEMENT_SENSOR_H_

#define MOVEMENT_SENSOR_GPIO GPIOC
#define MOVEMENT_SENSOR_PIN GPIO_PIN_9
#define MOVEMENT_SENSOR MOVEMENT_SENSOR_GPIO, MOVEMENT_SENSOR_PIN

void sensors_movement_detected();

#endif /* CUSTOM_SENSORS_INCLUDE_MOVEMENT_SENSOR_H_ */
