/**
 * @file panic.h
 * @author sioel0
 * @brief This file contains all the high level panic module interaction functions
 */

#ifndef CUSTOM_PANIC_INCLUDE_PANIC_H_
#define CUSTOM_PANIC_INCLUDE_PANIC_H_

#include "panic_buzzer.h"
#include "panic_button.h"
#include "panic_timer.h"

/**
 * @brief This function is used to acknowledge if the panic module is active
 * @return 1 if it is active 0 otherwise
 */
uint8_t panic_is_active();
/**
 * @brief This function is used to activate the panic module
 */
void panic_activate();
/**
 * @brief this function is used to turn the panic module off
 */
void panic_deactivate();
/**
 * @brief This function is the one that manages all the panic module main loop
 * This function reacts to all the data received from outside to make the panic module
 * work properly
 */
void panic_main();

#endif /* CUSTOM_PANIC_INCLUDE_PANIC_H_ */
