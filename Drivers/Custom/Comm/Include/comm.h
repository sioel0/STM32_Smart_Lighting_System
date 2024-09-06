/*
 * comm.h
 *
 *  Created on: Sep 3, 2024
 *      Author: sioel0
 */

#include "stm32f4xx_hal.h"
#include <stdint.h>

#ifndef CUSTOM_COMM_INCLUDE_COMM_H_
#define CUSTOM_COMM_INCLUDE_COMM_H_

#include "protocol.h"

extern UART_HandleTypeDef huart2;
extern TIM_HandleTypeDef htim11;

#define COMM_UART_INTERFACE &huart2
#define COMM_TIMER &htim11
#define PACKET_SIZE 2
#define INPUT_BUFF_SIZE 10

static const uint8_t periodic_packet[PACKET_SIZE] = {PERIODIC_PACKET, NO_DATA};
static const uint8_t panic_packet[PACKET_SIZE] = {PANIC_PACKET, NO_DATA};

void comm_send_data(const uint8_t*);
void comm_init();

#endif /* CUSTOM_COMM_INCLUDE_COMM_H_ */
