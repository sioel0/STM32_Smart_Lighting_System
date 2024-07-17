/*
 * Error.h
 *
 *  Created on: Jul 16, 2024
 *      Author: sioel0
 */

#include <stdint.h>

#ifndef CUSTOM_ERROR_INCLUDE_ERROR_H_
#define CUSTOM_ERROR_INCLUDE_ERROR_H_

/* ------- Defines -------- */

// all the project modules
#define MOD_NONE     (uint8_t) 0x0000
#define MOD_COMM     (uint8_t) 0x0001
#define MOD_LIGHTS   (uint8_t) 0x0010
#define MOD_PANIC    (uint8_t) 0x0100
#define MOD_SENSORS  (uint8_t) 0x1000

// all the possible errors motivation
#define MOT_NONE     (uint8_t) 0x0000
#define MOT_GENERIC  (uint8_t) 0x0001
#define MOT_NO_DATA  (uint8_t) 0x0010
#define MOT_NO_CONN  (uint8_t) 0x0100

/* -------- Function macros -------- */

// module specific error set
#define comm_error(mot)    module_set_error(MOD_COMM, mot)    // comm module error
#define lights_error(mot)  module_set_error(MOD_LIGHTS, mot)  // lights module error
#define panic_error(mot)   module_set_error(MOD_PANIC)        // panic module error
#define sensors_error(mot) module_set_error(MOD_SENSORS, mot) // sensors module error

// module specific error reset
#define comm_res_errors()    module_reset_errors(MOD_COMM)
#define lights_res_errors()  module_reset_errors(MOD_LIGHTS)
#define panic_res_errors()   module_reset_errors(MOD_PANIC)
#define sensors_res_errors() module_reset_errors(MOD_SENSORS)

// module specific error check
#define comm_has_error()    module_has_error(MOD_COMM)
#define lights_has_error()  module_has_error(MOD_LIGHTS)
#define panic_has_error()   module_has_error(MOD_PANIC)
#define sensors_has_error() module_has_error(MOD_SENSORS)

/* -------- Function declarations -------- */

void module_set_error(uint8_t, uint8_t);
void module_reset_errors(uint8_t);

uint8_t module_has_error(uint8_t);

#endif /* CUSTOM_ERROR_INCLUDE_ERROR_H_ */
