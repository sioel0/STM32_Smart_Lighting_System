/**
 * @file protocol.h
 * @author sioel0
 * @brief This file contains all the protocol related stuff, defines and functions to react to received data
 */

#include <stdint.h>

#ifndef CUSTOM_COMM_INCLUDE_PROTOCOL_H_
#define CUSTOM_COMM_INCLUDE_PROTOCOL_H_

#define WC_RESET_GPIO GPIOD /** Wireless coprocessor reset gpio interface */
#define WC_RESET_PIN GPIO_PIN_12 /** Wireless coprocessor reset pin */
#define WC_RESET WC_RESET_GPIO, WC_RESET_PIN /** Wireless coprocessor reset identifier, it can be used in HAL functions to set GPIO and PIN parameters*/

// first data packet
#define PERIODIC_PACKET  0x50 /** Periodic packet identifier */
#define CMD_PACKET       0x51 /** Command packet identifier */
#define PANIC_PACKET     0x52 /** Panic packet identifier */

// cmd second byte
#define NO_DATA          0x00 /** Placeholder for all the packets that do not need any data ad second byte */
#define TRIGGER_RESET    0x01 /** Reset triggering command packet */
#define TURN_PANIC_ON    0x02 /** Panic module activating packet */
#define TURN_PANIC_OFF   0x04 /** Panic module disabling packet */
#define TURN_LIGHT_ON    0x08 /** Light activating packet */
#define TURN_LIGHT_OFF   0x10 /** Light disabling packet */
#define TURN_MVMT_ON     0x11 /** Movement sensor activating packet */
#define TURN_MVMT_OFF    0x12 /** Movement sensor disabling packet */

/**
 * @brief This function is used to react to received data
 * @param packet data that needs to be analysed
 * @param len length of the received data
 * Since the only possible data that can be received are command packets, this functions
 * is intended to react only to this type of packets, it is of course possible to send
 * any type of data but it will not do anything.
 */
void protocol_interpret_cmd_packet(uint8_t* packet, uint8_t len);

#endif /* CUSTOM_COMM_INCLUDE_PROTOCOL_H_ */
