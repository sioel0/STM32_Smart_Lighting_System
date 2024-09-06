/*
 * light_i2c.c
 *
 *  Created on: Jul 25, 2024
 *      Author: leoni
 */

#include <stdint.h>
#include <string.h>
#include "light_i2c.h"
#include "stm32f4xx_hal.h"

HAL_StatusTypeDef light_i2c_select_page(uint8_t page) {
	uint8_t data[2] = {COMMAND_REGISTER, page};
	return HAL_I2C_Master_Transmit(LIGHT_I2C_INTERFACE, LIGHT_MATRIX_ADDR, data, 2, 100);
}

HAL_StatusTypeDef light_i2c_write_single_register(uint8_t page, uint8_t reg, uint8_t value) {
	HAL_StatusTypeDef page_selected = light_i2c_select_page(page);
	if(page_selected != HAL_BUSY) {
		uint8_t data[2] = {reg, value};
		return HAL_I2C_Master_Transmit(LIGHT_I2C_INTERFACE, LIGHT_MATRIX_ADDR, data, 2, 100);
	}
	return page_selected;
}

HAL_StatusTypeDef light_i2c_send_data(uint8_t page, uint8_t reg, uint8_t *data, uint8_t data_len) {
	HAL_StatusTypeDef page_selected = light_i2c_select_page(page);
	if(page_selected != HAL_BUSY) {
		uint8_t buff[data_len+1];
		buff[0] = reg;
		memcpy(buff+1, data, data_len);
		return HAL_I2C_Master_Transmit(LIGHT_I2C_INTERFACE, LIGHT_MATRIX_ADDR, buff, data_len + 1, 100);
	}
	return page_selected;
}

HAL_StatusTypeDef light_i2c_read_single_register(uint8_t page, uint8_t reg) {
	// not sure if it is necessary
	return HAL_OK;
}
