/*
 * led.h
 *
 *  Created on: Dec 6, 2022
 *      Author: АлексанDOOR
 */

#ifndef LED_H_
#define LED_H_

#include <stdint.h>
#include <stdbool.h>

#include "main.h"
#include "stm32f4xx_hal.h"

#define LED_LEFT_Pin            GPIO_PIN_12
#define LED_LEFT_GPIO_Port      GPIOD
#define LED_TOP_Pin             GPIO_PIN_13
#define LED_TOP_GPIO_Port       GPIOD
#define LED_RIGHT_Pin           GPIO_PIN_14
#define LED_RIGHT_GPIO_Port     GPIOD
#define LED_BOTTOM_Pin          GPIO_PIN_15
#define LED_BOTTOM_GPIO_Port    GPIOD

#define ZERO_MS                 (0u)

#define LED_INDICATION_VERY_FAST(x)    ((x) * (1u))
#define LED_INDICATION_FAST(x)         ((x) * (2u))
#define LED_INDICATION_MIDDLE(x)       ((x) * (3u))
#define LED_INDICATION_SLOW(x)         ((x) * (4u))
#define LED_INDICATION_VERY_SLOW(x)    ((x) * (6u))

#define LED_TOP_TIME_ON                (50u)
#define LED_LEFT_TIME_ON               (70u)
#define LED_BOTTOM_TIME_ON             (90u)
#define LED_RIGHT_TIME_ON              (110u)

#define LED_TOP_TIME_OFF               (70u)
#define LED_LEFT_TIME_OFF              (90u)
#define LED_BOTTOM_TIME_OFF            (110u)
#define LED_RIGHT_TIME_OFF             (130u)

#define LED_TIME_ON                    (50u)
#define LED_TIME_OFF                   (70u)

#define LED_LOADING_NUM                (10000u)
#define LED_ERROR_NUM                  (3u)
#define LED_BUTTON_NUM                 (1u)

#define N_LED                          (4u)

enum led_id {
	LED_TOP = 0,
	LED_LEFT,
	LED_BOTTOM,
	LED_RIGHT
};

enum led_mode {
	LED_OFF = 0,
	LED_ON,
	LED_BLINK,
	LED_TOGGLE,
	LED_LOADING //"LOADING" AND "ON" MODES ARE THE SAME FOR NOW. MAYBE I'LL CHANGE IT IN FUTURE
};

enum led_speed {
	LED_SPEED_VERY_FAST = 1,
	LED__SPEED_FAST,
	LED_SPEED_MIDDLE,
	LED_SPEED_SLOW,
	LED_SPEED_VERY_SLOW = 6
};

struct led {

	struct {
		uint16_t on_ms;
		uint16_t off_ms;
		uint16_t delay_ms;
		uint16_t iterations_num;
		bool activate;
	} config;

	struct {
		uint32_t pin;
		uint32_t port;
		uint8_t mode;
	} hardware;

	struct {
		uint16_t on_timeout;
		uint16_t off_timeout;
		uint16_t iterations_counter;
	} status;
};

extern struct led led[N_LED];

extern void Initialize_LED_indication(void);
extern void leds_update(void);
extern void led_loading_setup(struct led *led_ptr, int led_index);
extern void led_button_setup(struct led *led_ptr, int led_index);
extern void led_error_setup(struct led *led_ptr);
extern void led_function(struct led *led_ptr);
//extern void led_reset_all(void);

#endif /* LED_H_ */
