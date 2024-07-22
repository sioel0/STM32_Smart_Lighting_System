/*
 * movement_sensor.c
 *
 *  Created on: Jul 22, 2024
 *      Author: leoni
 */

#include <stdint.h>
#include "sensors_movement_sensor.h"

uint8_t movement_sensor_detected = 0;

void sensors_movement_detected() {
	movement_sensor_detected = 1;
}
