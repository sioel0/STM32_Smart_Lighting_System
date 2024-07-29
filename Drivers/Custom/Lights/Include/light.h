/*
 * light.h
 *
 *  Created on: Jul 15, 2024
 *      Author: leoni
 */

#ifndef LIGHTS_INCLUDE_LIGHT_H_
#define LIGHTS_INCLUDE_LIGHT_H_

#include "light_i2c.h"

#define DEFAULT_LIGHT_INTENSITY 100
#define MAX_LIGHT_INTENSITY 255

void light_power_on();
void light_shutdown();

void light_default_state(uint8_t);
void light_init();

void light_turn_on_frame(uint8_t);
void light_turn_off_frame(uint8_t);

#define light_set_current_intensity(i) light_set_intensity(MATRIX_FRAME1, i)
void light_set_intensity(uint8_t, uint8_t);

void light_transition_to_max();

uint8_t light_is_on();
void light_activate();
void light_deactivate();

void light_level_check();

void light_main();

#endif /* LIGHTS_INCLUDE_LIGHT_H_ */
