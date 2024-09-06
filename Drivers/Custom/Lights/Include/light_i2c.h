/*
 * light_i2c_driver.h
 *
 *  Created on: Jul 24, 2024
 *      Author: leoni
 */

#include <stdint.h>
#include "stm32f4xx_hal.h"

extern I2C_HandleTypeDef hi2c1;

#ifndef CUSTOM_LIGHTS_INCLUDE_LIGHT_I2C_H_
#define CUSTOM_LIGHTS_INCLUDE_LIGHT_I2C_H_

// i2c addresses have to be shifted left by one on stm32
#define LIGHT_MATRIX_ADDR 0x74<<1 // address + write mode
#define LIGHT_I2C_INTERFACE &hi2c1

// command register
#define COMMAND_REGISTER 0xFD

// register definitions
#define MATRIX_FRAME1 0x00
#define MATRIX_FRAME2 0x01
#define MATRIX_FRAME3 0x02
#define MATRIX_FRAME4 0x03
#define MATRIX_FRAME5 0x04
#define MATRIX_FRAME6 0x05
#define MATRIX_FRAME7 0x06
#define MATRIX_FRAME8 0x07
#define MATRIX_FUNCTION_REGISTER 0x0B

// frame registers pg 1-8
#define LED_CONTROL_START 0x00
#define LED_CONTROL_END 0x11
#define BLINK_CONTROL_START 0x12
#define BLINK_CONTROL_END 0x23
#define PWM_CONTROL_START 0x24
#define PWM_CONTROL_END 0xB3

// function register pg 9

/************************************/
/* Configuration register */
#define CONFIGURATION_REGISTER 0x00
#define PICTURE_MODE 0x00
#define AUTOFRAME_MODE 0x01
#define AUDIOFRAME_MODE 0x10
#define AUTOPLAY_MODE(mode,fs) 0x00|((mode<<3)|(fs))
/************************************/
/* Picture display register */
#define PICTURE_DISPLAY_REGISTER 0x01
#define PICTURE_MODE_FRAME(pfs) pfs

/************************************/
/* Auto Play Control register 1 */
#define AUTOPLAY_CONTROL_REGISTER1 0x02
#define AUTOPLAY_MODE_CONFIG(cns,fns) 0x00|((cns<<4)|(fns))

// used for cns and fns
#define ENDLESS_ALLFRAME 0x00
#define LOOPS_FRAMES1 0x01
#define LOOPS_FRAMES2 0x02
#define LOOPS_FRAMES3 0x03
#define LOOPS_FRAMES4 0x04
#define LOOPS_FRAMES5 0x05
#define LOOPS_FRAMES6 0x06
#define LOOPS_FRAMES7 0x07

/************************************/
/* Auto Play Control register 2 */
#define AUTOPLAY_CONTROL_REGISTER2 0x03
#define AUTOPLAY_DELAY_CONFIG(a) a

/************************************/
/* Display option register */
#define DISPLAY_OPTION_REGISTER 0x05
// a represent blink period 0 - 7
#define DISPLAY_OPTIONS(ic,be,a) 0x00|((ic<<5)|(be<<3)|(a))

// used for ic
#define INDEPENDENT_INTENSITY 0x00
#define SAME_INTENSITY_ALL_FRAMES 0x01

// used for be
#define BLINK_DISABLED 0x00
#define BLINK_ENABLED 0x01

/************************************/
/* Audio synchronization register */
#define AUDIO_SYNC_REGISTER 0x06
#define AUDIO_SYNC_CONFIG(ae) ae

// used for ae
#define AUDIO_SYNC_DISABLED 0x00
#define AUDIO_SYNC_ENABLED 0x01

/************************************/
/* Frame state register (read-only) */
#define FRAME_STATE_REGISTER 0x07

/************************************/
/* Breath control register 1 */
#define BREATH_CONTROL_REGISTER1 0x08
// fade out time Tx2^a
// fade in time Tx2^b
// a,b 0 - 7
#define FADE_TIMEOUT(a,b) 0x00|((a<<4)|b)

/************************************/
/* Breath control register 2 */
#define BREATH_CONTROL_REGISTER2 0x09
// extinguish time TX2^a
// a 0 - 7
#define BREATH_FUNCTION_CONFIG(b_en,a) 0x00|((b_en<<4)|a)

// used for b_en
#define BREATH_DISABLED 0x00
#define BREATH_ENABLED 0x01

/************************************/
/* Shutdown register */
#define SHUTDOWN_REGISTER 0x0A

#define SHUTDOWN 0x00
#define TURN_ON 0x01

/************************************/
/* AGC control register */
#define AGC_CONTROL_REGISTER 0x0B
// audio gain selection agsx3dB
// ags 0 - 7
#define AGC_CONFIG(agcm,agc,ags) 0x00|((agcm<<4)|(agc<<3)|ags)

// used for agcm
#define AGC_MODE_SLOW 0x00
#define AGC_MODE_FAST 0x01

// used for agc
#define AGC_DISABLED 0x00
#define AGC_ENABLED 0x01

/************************************/
/* Audio ADC rate register */
#define AUDIO_ADC_RATE_REGISTER 0x0C
#define ADC_CONFIG(a) a

HAL_StatusTypeDef light_i2c_select_page(uint8_t);
HAL_StatusTypeDef light_i2c_write_single_register(uint8_t, uint8_t, uint8_t);
HAL_StatusTypeDef light_i2c_send_data(uint8_t, uint8_t, uint8_t*, uint8_t);
HAL_StatusTypeDef light_i2c_read_single_register(uint8_t, uint8_t);

#endif /* CUSTOM_LIGHTS_INCLUDE_LIGHT_I2C_H_ */
