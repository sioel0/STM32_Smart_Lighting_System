/**
 * @file comm.h
 * @author sioel0
 * @brief This file contains useful function which gives the opportunity to abstract the serial communication layer
 */

#include "stm32f4xx_hal.h"
#include <stdint.h>

#ifndef CUSTOM_COMM_INCLUDE_COMM_H_
#define CUSTOM_COMM_INCLUDE_COMM_H_

#include "protocol.h"

extern UART_HandleTypeDef huart2;
extern TIM_HandleTypeDef htim11;

#define COMM_UART_INTERFACE &huart2 /** uart interface used to interact with wireless coprocessor */
#define COMM_TIMER &htim11 /** 5 seconds timer used to send period packets */
#define PACKET_SIZE 2 /** data packet size */

/**
 * @brief Periodic packet
 */
static const uint8_t periodic_packet[PACKET_SIZE] = {PERIODIC_PACKET, NO_DATA};

/**
 * @brief Panic packet
 */
static const uint8_t panic_packet[PACKET_SIZE] = {PANIC_PACKET, NO_DATA};

/**
 * @brief this function is used to send data via uart interface.
 * @param data the data that needs to be sent
 * Since both the MCU and the coprocessor are able to work on fixed sized packet, it is assumed
 * that the data length of @ref param is @ref PACKET_SIZE
 */
void comm_send_data(const uint8_t* data);

/**
 * @brief This function is used to initialise the communication module
 * This function is used to make the period packet timer start and active the IRQ routine
 * for uart data reception
 */
void comm_init();

#endif /* CUSTOM_COMM_INCLUDE_COMM_H_ */
