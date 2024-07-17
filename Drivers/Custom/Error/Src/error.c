/*
 * error.c
 *
 *  Created on: Jul 16, 2024
 *      Author: sioel0
 */

#include <stdint.h>
#include "error.h"
#include "stm32f4xx_hal.h"

// errors and motivations variables
uint8_t motivation = 0;
uint8_t module = 0;

/**
 * @brief This function is used by all the modules to signal errors
 * @param mod which module is having an error
 * @param mot the error motivation
 * @retval none
 */
void module_set_error(uint8_t mod, uint8_t mot) {
	module |= mod;
	motivation |= mot;
}

void module_reset_errors(uint8_t mod) {
	module ^= mod;
	motivation &= MOT_NONE;
}

uint8_t module_has_error(uint8_t mod) {
	return (module & mod) == mod;
}
