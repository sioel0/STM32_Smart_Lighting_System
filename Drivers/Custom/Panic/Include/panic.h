/*
 * panic.h
 *
 *  Created on: Jul 17, 2024
 *      Author: leoni
 */

#ifndef CUSTOM_PANIC_INCLUDE_PANIC_H_
#define CUSTOM_PANIC_INCLUDE_PANIC_H_

#include "panic_buzzer.h"
#include "panic_button.h"
#include "panic_timer.h"

uint8_t panic_is_active();
void panic_activate();
void panic_deactivate();
void panic_main();

#endif /* CUSTOM_PANIC_INCLUDE_PANIC_H_ */
