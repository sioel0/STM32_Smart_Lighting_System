/*
 * protocol.c
 *
 *  Created on: Sep 2, 2024
 *      Author: sioel0
 */

#include "protocol.h"
#include "light.h"
#include "panic.h"
#include "sensors_movement_sensor.h"

void protocol_interpret_cmd_packet(uint8_t* packet, uint8_t len) {
	if(packet[0] == CMD_PACKET) {
		switch(packet[1]) {
		case TRIGGER_RESET:
			HAL_GPIO_WritePin(WC_RESET, GPIO_PIN_SET);
			HAL_NVIC_SystemReset();
			break;
		case TURN_PANIC_ON:
			panic_activate();
			break;
		case TURN_PANIC_OFF:
			panic_deactivate();
			break;
		case TURN_LIGHT_ON:
			light_activate();
			break;
		case TURN_LIGHT_OFF:
			light_deactivate();
			break;
		case TURN_MVMT_ON:
			sensors_movement_sensor_on();
			break;
		case TURN_MVMT_OFF:
			sensors_movement_sensor_off();
			break;
		default:
			break;
		}
	} else {
		// do nothing
	}
}
