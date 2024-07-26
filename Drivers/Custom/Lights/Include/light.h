/*
 * light.h
 *
 *  Created on: Jul 15, 2024
 *      Author: leoni
 */

#ifndef LIGHTS_INCLUDE_LIGHT_H_
#define LIGHTS_INCLUDE_LIGHT_H_

void light_power_on();
void light_shutdown();

void light_init();

void light_turn_on();
void light_turn_off();

void light_set_intensity(uint8_t);

#endif /* LIGHTS_INCLUDE_LIGHT_H_ */
