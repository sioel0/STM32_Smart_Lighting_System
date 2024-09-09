/**
 * @file light.h
 * @author sioel0
 * @brief This file contains all the needed high level function for light module interaction
 */

#ifndef LIGHTS_INCLUDE_LIGHT_H_
#define LIGHTS_INCLUDE_LIGHT_H_

#include "light_i2c.h"

#define DEFAULT_LIGHT_INTENSITY 100 /** Default light intensity value */
#define MAX_LIGHT_INTENSITY 255 /** Maximum light intensity value */

/**
 * @brief Turn light on via @ref SHUTDOWN_REGISTER
 */
void light_power_on();
/**
 * @brief Turn light off via @ref SHUTDOWN_REGISTER
 */
void light_shutdown();

/**
 * @brief Turn light on in picture mode with a given light intensity
 * @param intensity the desired light intensity level
 */
void light_default_state(uint8_t intensity);
/**
 * @brief Initialise light module settings up all the frames
 */
void light_init();

/**
 * @brief Turns on all the LEDs of a given frame
 * @param frame the frame to activate
 */
void light_turn_on_frame(uint8_t frame);
/**
 * @brief Turns off all the LEDs of a given frame
 * @param frame the frame to deactivate
 */
void light_turn_off_frame(uint8_t frame);

/**
 * @brief Set light intensity of the given frame
 * @param frame the selected frame
 * @param intensity intensity level, it can be any value in [0-255]
 */
void light_set_intensity(uint8_t frame, uint8_t intensity);

/**
 * @brief Set current intensity of frame 1
 * @param i light intensity, it can be any value in [0-255]
 */
#define light_set_current_intensity(i) light_set_intensity(MATRIX_FRAME1, i)

/**
 * @brief Activates a smooth transition to max intensity level
 */
void light_transition_to_max();

/**
 * @brief Yells if the light module is currently working or not
 * @return 1 if the module light is working 0 otherwise
 */
uint8_t light_is_on();
/**
 * @brief Activates the component that make the light module work correctly
 */
void light_activate();
/**
 * @brief Deactivates the component that make the light module work correctly
 */
void light_deactivate();

/**
 * @brief Triggers the ambient light level check
 */
void light_level_check();

/**
 * @brief Main cycle of the light module
 * This function is the one that takes care of the normal operation of the light module
 * it coordinates all the operations linked to the device sensors to make the light
 * react to external data
 */
void light_main();

#endif /* LIGHTS_INCLUDE_LIGHT_H_ */
