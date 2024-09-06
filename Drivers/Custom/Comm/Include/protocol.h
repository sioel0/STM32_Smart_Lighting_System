/*
 * protocol.h
 *
 *  Created on: Sep 2, 2024
 *      Author: sioel0
 */

#include <stdint.h>

#ifndef CUSTOM_COMM_INCLUDE_PROTOCOL_H_
#define CUSTOM_COMM_INCLUDE_PROTOCOL_H_

// packet composition:
// byte 1: source address
// byte 2: packet type
// byte 3: additional data if necessary
// since this will only send data to the router the destination address
// will be added using the LoRa coprocessor

#define WC_RESET_GPIO GPIOD
#define WC_RESET_PIN GPIO_PIN_12
#define WC_RESET WC_RESET_GPIO, WC_RESET_PIN

// first data packet
#define PERIODIC_PACKET  0x50
#define CMD_PACKET       0x51
#define PANIC_PACKET     0x52
#define SET_LIGHT_PACKET 0x54

// cmd second byte
#define NO_DATA          0x00
#define TRIGGER_RESET    0x01
#define TURN_PANIC_ON    0x02
#define TURN_PANIC_OFF   0x04
#define TURN_LIGHT_ON    0x08
#define TURN_LIGHT_OFF   0x10
#define TURN_MVMT_ON     0x11
#define TURN_MVMT_OFF    0x12

void protocol_interpret_cmd_packet(uint8_t*, uint8_t);

#endif /* CUSTOM_COMM_INCLUDE_PROTOCOL_H_ */
