/*
 * panic.c
 *
 *  Created on: Jul 17, 2024
 *      Author: leoni
 */

#include "panic_button.h"
#include "panic_buzzer.h"
#include "panic.h"
#include "stm32f4xx_hal.h"

extern uint8_t button_pressed;

#ifdef PANIC

	void panic_main() {
		// fai partire il timer e resetta lo stato di button_pressed
		if(button_pressed) {
			panic_buzzer_start();
			panic_button_reset();
			// TODO: aggiungi invio messaggi / trova il modo per inviare i messaggi di emergenza(variabile o simili)
		}
		else {
			// finché timer non scade esegui
			if(/* time scaduto */) {
				panic_button_stop();
			}
		}
	}

#endif
