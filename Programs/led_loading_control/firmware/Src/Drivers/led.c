/*
 * led.c
 *
 *  Created on: Dec 6, 2022
 *      Author: АлексанDOOR
 */

#include "led.h"

struct led led[N_LED];
enum led_id id;
enum led_mode mode;
enum led_speed speed;

static void led_init(void);
static void led_update(struct led *led_ptr);

void Initialize_LED_indication(void)
{
	led_init();
}

void led_init(void)
{
	GPIO_InitTypeDef GPIO_InitStruct = {0};

	__HAL_RCC_GPIOD_CLK_ENABLE();
    __HAL_RCC_GPIOH_CLK_ENABLE();
    __HAL_RCC_GPIOA_CLK_ENABLE();

	HAL_GPIO_WritePin(GPIOD, LED_LEFT_Pin|LED_TOP_Pin|LED_RIGHT_Pin|LED_BOTTOM_Pin, GPIO_PIN_RESET);

	GPIO_InitStruct.Pin = LED_LEFT_Pin|LED_TOP_Pin|LED_RIGHT_Pin|LED_BOTTOM_Pin;
	GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
	GPIO_InitStruct.Pull = GPIO_NOPULL;
	GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
	HAL_GPIO_Init(GPIOD, &GPIO_InitStruct);

	led[LED_TOP].hardware.port = (uint32_t) LED_TOP_GPIO_Port;
	led[LED_TOP].hardware.pin = (uint32_t) LED_TOP_Pin;
	led[LED_LEFT].hardware.port = (uint32_t) LED_LEFT_GPIO_Port;
	led[LED_LEFT].hardware.pin = (uint32_t) LED_LEFT_Pin;
	led[LED_BOTTOM].hardware.port = (uint32_t) LED_BOTTOM_GPIO_Port;
	led[LED_BOTTOM].hardware.pin = (uint32_t) LED_BOTTOM_Pin;
	led[LED_RIGHT].hardware.port = (uint32_t) LED_RIGHT_GPIO_Port;
	led[LED_RIGHT].hardware.pin = (uint32_t) LED_RIGHT_Pin;
}

void led_function(struct led *led_ptr)
{
	if (led_ptr->hardware.mode == LED_OFF) {
		HAL_GPIO_WritePin((GPIO_TypeDef *) led_ptr->hardware.port, led_ptr->hardware.pin, GPIO_PIN_RESET);
	}
	if (led_ptr->hardware.mode == LED_ON) {
		HAL_GPIO_WritePin((GPIO_TypeDef *) led_ptr->hardware.port, led_ptr->hardware.pin, GPIO_PIN_SET);
	}
	if (led_ptr->hardware.mode == LED_LOADING) {
		HAL_GPIO_WritePin((GPIO_TypeDef *) led_ptr->hardware.port, led_ptr->hardware.pin, GPIO_PIN_SET);
	}
}

void leds_update(void)
{
	led_update(&led[LED_TOP]);
	led_update(&led[LED_LEFT]);
	led_update(&led[LED_BOTTOM]);
	led_update(&led[LED_RIGHT]);
}

void led_update(struct led *led_ptr)
{
	if (led_ptr->status.on_timeout) {
		if (!--led_ptr->status.on_timeout) {
			HAL_GPIO_WritePin((GPIO_TypeDef *) led_ptr->hardware.port, led_ptr->hardware.pin, GPIO_PIN_RESET);
			if (led_ptr->config.iterations_num) {
				led_ptr->status.iterations_counter++;
				if (led_ptr->status.iterations_counter >= led_ptr->config.iterations_num) {
					led_ptr->config.off_ms = ZERO_MS;
					led_ptr->config.delay_ms = ZERO_MS;
				}
				led_ptr->status.off_timeout = (led_ptr->config.off_ms + led_ptr->config.delay_ms);
			}
		}
	}

	if (led_ptr->status.off_timeout) {
		if (!--led_ptr->status.off_timeout) {
			led_ptr->status.on_timeout = (led_ptr->config.on_ms + led_ptr->config.delay_ms);
			HAL_GPIO_WritePin((GPIO_TypeDef *) led_ptr->hardware.port, led_ptr->hardware.pin, GPIO_PIN_SET);
		}
	}
}

void led_loading_setup(struct led *led_ptr, int led_index)
{
	led_ptr->hardware.mode = LED_LOADING;
	led_ptr->config.iterations_num = LED_LOADING_NUM;
	led_ptr->config.activate = true;

	switch (led_index) {
		case LED_TOP:
			led_ptr->config.on_ms = (LED_SPEED_VERY_FAST * LED_TOP_TIME_ON);
			led_ptr->config.off_ms = (LED_SPEED_VERY_FAST * LED_TOP_TIME_OFF);
			led_ptr->config.delay_ms = (LED_SPEED_VERY_FAST * (LED_RIGHT_TIME_OFF - LED_TOP_TIME_ON));
			break;
		case LED_LEFT:
			led_ptr->config.on_ms = (LED_SPEED_VERY_FAST * LED_LEFT_TIME_ON);
			led_ptr->config.off_ms = (LED_SPEED_VERY_FAST * LED_LEFT_TIME_OFF);
			led_ptr->config.delay_ms = (LED_SPEED_VERY_FAST * (LED_RIGHT_TIME_OFF - LED_LEFT_TIME_ON));
			break;
		case LED_BOTTOM:
			led_ptr->config.on_ms = (LED_SPEED_VERY_FAST * LED_BOTTOM_TIME_ON);
			led_ptr->config.off_ms = (LED_SPEED_VERY_FAST * LED_BOTTOM_TIME_OFF);
			led_ptr->config.delay_ms = (LED_SPEED_VERY_FAST * (LED_RIGHT_TIME_OFF - LED_BOTTOM_TIME_ON));
			break;
		case LED_RIGHT:
			led_ptr->config.on_ms = (LED_SPEED_VERY_FAST * LED_RIGHT_TIME_ON);
			led_ptr->config.off_ms = (LED_SPEED_VERY_FAST * LED_RIGHT_TIME_OFF);
			led_ptr->config.delay_ms = (LED_SPEED_VERY_FAST * (LED_RIGHT_TIME_OFF - LED_RIGHT_TIME_ON));
			break;
		default:
			break;
 	}

	led_ptr->status.iterations_counter = 0;
	led_ptr->status.on_timeout = led_ptr->config.on_ms;
	led_ptr->status.off_timeout = led_ptr->config.off_ms;
}

void led_button_setup(struct led *led_ptr, int led_index)
{
	switch (led_index) {
		case LED_TOP:
			led_ptr->hardware.mode = LED_ON;
			led_ptr->config.iterations_num = LED_BUTTON_NUM;
			led_ptr->config.activate = true;
			led_ptr->config.on_ms = (LED_SPEED_MIDDLE * LED_TOP_TIME_ON);
			led_ptr->config.off_ms = (LED_SPEED_MIDDLE * LED_TOP_TIME_OFF);
			led_ptr->config.delay_ms = ZERO_MS;
			break;
		case LED_LEFT:
			led_ptr->hardware.mode = LED_OFF;
			led_ptr->config.on_ms = ZERO_MS;
			led_ptr->config.off_ms = ZERO_MS;
			break;
		case LED_BOTTOM:
			led_ptr->hardware.mode = LED_OFF;
			led_ptr->config.on_ms = ZERO_MS;
			led_ptr->config.off_ms = ZERO_MS;
			break;
		case LED_RIGHT:
			led_ptr->hardware.mode = LED_OFF;
			led_ptr->config.on_ms = ZERO_MS;
			led_ptr->config.off_ms = ZERO_MS;
			break;
		default:
			break;
 	}

	led_ptr->status.iterations_counter = 0;
	led_ptr->status.on_timeout = led_ptr->config.on_ms;
	led_ptr->status.off_timeout = led_ptr->config.off_ms;
}

void led_error_setup(struct led *led_ptr)
{
	led_ptr->hardware.mode = LED_ON;
	led_ptr->config.iterations_num = LED_ERROR_NUM;
	led_ptr->config.activate = true;

	led_ptr->config.on_ms = (LED__SPEED_FAST * LED_TIME_ON);
	led_ptr->config.off_ms = (LED__SPEED_FAST * LED_TIME_OFF);
	led_ptr->config.delay_ms = ZERO_MS;

	led_ptr->status.iterations_counter = 0;
	led_ptr->status.on_timeout = led_ptr->config.on_ms;
	led_ptr->status.off_timeout = led_ptr->config.off_ms;
}
