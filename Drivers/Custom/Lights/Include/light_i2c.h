/**
 * @file light_i2c.h
 * @author sioel0
 * @brief This file contains the low level i2c driver for the light matrix
 * To better understand how everything works refer to the light matrix documentation
 * which can be found <a href=https://learn.adafruit.com/system/assets/assets/000/030/994/original/31FL3731.pdf?1457554773>here</a>
 */
#ifndef CUSTOM_LIGHTS_INCLUDE_LIGHT_I2C_H_
#define CUSTOM_LIGHTS_INCLUDE_LIGHT_I2C_H_

#include <stdint.h>
#include "stm32f4xx_hal.h"

extern I2C_HandleTypeDef hi2c1;

// i2c addresses have to be shifted left by one on stm32
#define LIGHT_MATRIX_ADDR 0x74<<1 /** Light matrix address with 1 bit left shift */
#define LIGHT_I2C_INTERFACE &hi2c1 /** i2c interface used to communicate with the led matrix */

// command register
#define COMMAND_REGISTER 0xFD /** Command register address */

// register definitions
#define MATRIX_FRAME1 0x00 /** Frame 1 address */
#define MATRIX_FRAME2 0x01 /** Frame 2 address */
#define MATRIX_FRAME3 0x02 /** Frame 3 address */
#define MATRIX_FRAME4 0x03 /** Frame 4 address */
#define MATRIX_FRAME5 0x04 /** Frame 5 address */
#define MATRIX_FRAME6 0x05 /** Frame 6 address */
#define MATRIX_FRAME7 0x06 /** Frame 7 address */
#define MATRIX_FRAME8 0x07 /** Frame 8 address */
#define MATRIX_FUNCTION_REGISTER 0x0B /** matrix function register */

// frame registers pg 1-8
#define LED_CONTROL_START 0x00 /** First led control register, 1 bit per led */
#define LED_CONTROL_END 0x11 /** Last led control register */
#define BLINK_CONTROL_START 0x12 /** First blink control register, 1 bit per led */
#define BLINK_CONTROL_END 0x23 /** Last blink control register */
#define PWM_CONTROL_START 0x24 /** First pwm control register, 8 bit per led */
#define PWM_CONTROL_END 0xB3 /** Last pwm control register */

// function register pg 9


/* Configuration register */
#define CONFIGURATION_REGISTER 0x00 /** Configuration register address */
#define PICTURE_MODE 0x00 /** Enable picture mode */
#define AUTOFRAME_MODE 0x01 /** Enable autoframe mode */
#define AUDIOFRAME_MODE 0x10 /** Enable audioframe mode */
/*
 * @brief Enable autoplay mode with the defined options
 * @param mode can be choose between @ref PICTURE_MODE, @ref AUTOFRAME_MODE and @ref AUDIOFRAME_MODE
 * @param fs the starting frame for the animation
 * @return a bit mask representing the desired configuration
 */
#define AUTOPLAY_MODE(mode,fs) 0x00|((mode<<3)|(fs))

/* Picture display register */
#define PICTURE_DISPLAY_REGISTER 0x01 /** Picture display configuration register, this register is important only in picture mode */
#define PICTURE_MODE_FRAME(pfs) pfs /** Setup which frame should be shown in picture mode */


/* Auto Play Control register 1 */
#define AUTOPLAY_CONTROL_REGISTER1 0x02 /** Autoplay configuration register */
/**
 * @brief Autoplay configuration generator
 * @param cns number of loops to which the animation should perform
 * @param fns number of frame which will take part to the animation
 * @return a bit mask representing the defined configuration
 */
#define AUTOPLAY_MODE_CONFIG(cns,fns) 0x00|((cns<<4)|(fns))

// used for cns and fns
#define ENDLESS_ALLFRAME 0x00 /** This is used both for all frame and endless loop in @ref AUTOPLAY_MODE_CONFIG */
#define LOOPS_FRAMES1 0x01 /** This is used both for 1 frame and 1 loop in @ref AUTOPLAY_MODE_CONFIG */
#define LOOPS_FRAMES2 0x02 /** This is used both for 2 frame and 2 loop in @ref AUTOPLAY_MODE_CONFIG */
#define LOOPS_FRAMES3 0x03 /** This is used both for 3 frame and 3 loop in @ref AUTOPLAY_MODE_CONFIG */
#define LOOPS_FRAMES4 0x04 /** This is used both for 4 frame and 4 loop in @ref AUTOPLAY_MODE_CONFIG */
#define LOOPS_FRAMES5 0x05 /** This is used both for 5 frame and 5 loop in @ref AUTOPLAY_MODE_CONFIG */
#define LOOPS_FRAMES6 0x06 /** This is used both for 6 frame and 6 loop in @ref AUTOPLAY_MODE_CONFIG */
#define LOOPS_FRAMES7 0x07 /** This is used both for 7 frame and 7 loop in @ref AUTOPLAY_MODE_CONFIG */

/************************************/
/* Auto Play Control register 2 */
#define AUTOPLAY_CONTROL_REGISTER2 0x03 /** Delay autoplay configuration register */
/**
 * @brief Autoplay delay configuration generator
 * @param a frame delay time, it can be any value in [1-63] where the delay will be T*a with T~11ms
 * @return a bit mask representing the desired configuration
 */
#define AUTOPLAY_DELAY_CONFIG(a) a

/************************************/
/* Display option register */
#define DISPLAY_OPTION_REGISTER 0x05 /** Display option register */
/**
 * @brief Display configuration options generator
 * @param ic intensity control it can be either @ref INDEPENDENT_INTENSIDTY or @ref SAME_INTENSITY_ALL_FRAMES
 * @param be blink enable, it can be either @ref BLINK_DISABLED and @ref BLINK_ENABLED
 * @param a blink period time, it can be any value in [1-63] where the delay will be T*a with T~11ms
 */
#define DISPLAY_OPTIONS(ic,be,a) 0x00|((ic<<5)|(be<<3)|(a))

// used for ic
#define INDEPENDENT_INTENSITY 0x00 /** Set each frame intensity independently */
#define SAME_INTENSITY_ALL_FRAMES 0x01 /** Every frame has the same led intensity ad any other frame */

// used for be
#define BLINK_DISABLED 0x00 /** Disable blinking */
#define BLINK_ENABLED 0x01 /** Enable blinking */

/************************************/
/* Audio synchronization register */
#define AUDIO_SYNC_REGISTER 0x06 /** Audio synchronisation register */
/**
 * @brief Audio sync mode configuration register
 * @param ae audio synchronisation enable, it can be either @ref AUDIO_SYNC_DISABLED or @ref AUDIO_SYNC_ENABLED
 * @return a bit mask representing the desired configuration
 */
#define AUDIO_SYNC_CONFIG(ae) ae

// used for ae
#define AUDIO_SYNC_DISABLED 0x00 /** Disable audio sync mode */
#define AUDIO_SYNC_ENABLED 0x01 /** Enable audio sync mode */

/* Frame state register (read-only) */
#define FRAME_STATE_REGISTER 0x07 /** Frame state register which is read_only and can be used to get current display configuration */

/************************************/
/* Breath control register 1 */
#define BREATH_CONTROL_REGISTER1 0x08 /** Breath control register */
// fade out time Tx2^a
// fade in time Tx2^b
// a,b 0 - 7
/**
 * @brief Breath control configuration generator
 * @param a fade out time configuration, it can be any value in [0-7], the amount of time will be T*2^a
 * @param b fade in time configuration, it can be any value in [0-7], the amount of time will be T*2^b
 * @return a bit mask representing the desired configuration
 */
#define FADE_TIMEOUT(a,b) 0x00|((a<<4)|b)

/* Breath control register 2 */
#define BREATH_CONTROL_REGISTER2 0x09 /** Breath configuration register */
// extinguish time TX2^a
// a 0 - 7
/**
 * @brief Breath configuration generator
 * @param b_en breath enable, can be either @ref BREATH_DISABLED or @ref BREATH_ENABLED
 * @param a extinguish time configuration, it can be any value in [0-7], the amount of time will be T*2^a
 * @return a bit mask representing the desired configuration
 */
#define BREATH_FUNCTION_CONFIG(b_en,a) 0x00|((b_en<<4)|a)

// used for b_en
#define BREATH_DISABLED 0x00 /** Disable breath animation */
#define BREATH_ENABLED 0x01 /** Enable breath animation */

/************************************/
/* Shutdown register */
#define SHUTDOWN_REGISTER 0x0A /** Shutdown register */

#define SHUTDOWN 0x00 /** Turn off the led matrix */
#define TURN_ON 0x01 /** Turn on the led matrix */

/************************************/
#define AGC_CONTROL_REGISTER 0x0B /** AGC control register */
// audio gain selection agsx3dB
// ags 0 - 7
/**
 * @brief AGC configuration generator
 * @param agcm agc mode, it can be either @ref AGC_MODE_SLOW or @ref AGC_MODE_FAST
 * @param agc agc enable, it cna be either @ref AGC_DISABLED or @ref AGC_ENABLED
 * @param ags audio gain selection which can be any value in [0-7] and sets the audio gain to 3db*ags
 * @return a control
 */
#define AGC_CONFIG(agcm,agc,ags) 0x00|((agcm<<4)|(agc<<3)|ags)

// used for agcm
#define AGC_MODE_SLOW 0x00 /** Agc slow mode */
#define AGC_MODE_FAST 0x01 /** Agc fast mode */

// used for agc
#define AGC_DISABLED 0x00 /** Disable agc */
#define AGC_ENABLED 0x01 /** Enable agc */

/************************************/
#define AUDIO_ADC_RATE_REGISTER 0x0C/** Audio ADC rate register */
/**
 * @brief ADC configuration generator
 * @param a audio adc rate, the adc rate will be set to T*a with T~46us and a in [0-255]
 */
#define ADC_CONFIG(a) a

/**
 * @brief this function is used to select which destination frame of the following data
 * @param page the frame that needs to be selected
 * @return return HAL_OK if the page has been correctly selected HAL_BUSY otherwise
 */
HAL_StatusTypeDef light_i2c_select_page(uint8_t page);

/**
 * @brief this function is used to write the given value to the given register
 * @param page the page containing the desired register
 * @param reg the register address
 * @param value the value that needs to be written in the given register
 * @return return HAL_OK if the page has been correctly written HAL_BUSY otherwise
 */
HAL_StatusTypeDef light_i2c_write_single_register(uint8_t page, uint8_t reg, uint8_t value);

/*
 * @brief Send any amount of data starting from the given register
 * @param page the page which contains the data destination register
 * @param reg the data starting register
 * @param data the data that needs to be sent
 * @param data_len amount of bytes that needs to be sent
 * @return return HAL_OK if the page has been written selected HAL_BUSY otherwise
 * This function uses the automatic address increment present on the matrix led, this way it is not necessary
 * to select the next register each time
 */
HAL_StatusTypeDef light_i2c_send_data(uint8_t page, uint8_t reg, uint8_t* data, uint8_t data_len);

#endif /* CUSTOM_LIGHTS_INCLUDE_LIGHT_I2C_H_ */
