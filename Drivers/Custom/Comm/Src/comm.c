/*
 * comm.c
 *
 *  Created on: Sep 3, 2024
 *      Author: sioel0
 */

#include "protocol.h"
#include "comm.h"
#include "stm32f4xx_hal.h"
#include <stdint.h>

static uint8_t received_data[PACKET_SIZE];

void HAL_UART_RxCpltCallback(UART_HandleTypeDef *UartHandle) {
	protocol_interpret_cmd_packet(received_data, PACKET_SIZE);
	HAL_UART_Receive_IT(COMM_UART_INTERFACE, received_data, PACKET_SIZE);
}

void comm_send_data(const uint8_t* data) {
	HAL_UART_Transmit_DMA(COMM_UART_INTERFACE, data, PACKET_SIZE);
}

void comm_init() {
	HAL_TIM_Base_Stop_IT(COMM_TIMER);
	HAL_TIM_Base_Start_IT(COMM_TIMER);
	HAL_UART_Receive_IT(COMM_UART_INTERFACE, received_data, PACKET_SIZE);
}
