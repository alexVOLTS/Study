/*
 * indication.c
 *
 *  Created on: 15 дек. 2022 г.
 *      Author: АлексанDOOR
 */

#include "led.h"
#include "indication.h"

void indication_led_loading(void)
{
	for (int led_index = 0; led_index < N_LED; led_index++) {
		led_loading_setup(&led[led_index], led_index);
		led_function(&led[led_index]);
	}
}

void indication_led_button(void)
{
	for (int led_index = 0; led_index < N_LED; led_index++) {
		led_button_setup(&led[led_index], led_index);
		led_function(&led[led_index]);
	}
}

void indication_led_error(void)
{
	for (int led_index = 0; led_index < N_LED; led_index++) {
		led_error_setup(&led[led_index]);
		led_function(&led[led_index]);
	}
}
