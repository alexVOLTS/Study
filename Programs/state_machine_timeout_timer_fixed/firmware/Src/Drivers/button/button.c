/*
 * button.c
 *
 *  Created on: 29 нояб. 2022 г.
 *      Author: АлексанDOOR
 */

#include <stdbool.h>
#include "stm32f4xx_hal.h"
#include "timeout.h"
#include "button.h"
#include "gpio.h"
#include "state.h"

#define BUTTON_DEBOUNCE_TIME_MS    50u

struct user_button {
	struct timeout debounce_timeout;
};

static struct user_button user_button;

bool button_is_pushed(void)
{
	if (!timeout_started(&user_button.debounce_timeout)) {
		return false;
	}

	if (!timeout_elapsed(&user_button.debounce_timeout)) {
		return false;
	}

	return LL_GPIO_IsInputPinSet(GPIOA, LL_GPIO_PIN_0);
}

void EXTI0_IRQHandler(void)
{
	HAL_GPIO_EXTI_IRQHandler(LL_GPIO_PIN_0);
}

void HAL_GPIO_EXTI_Callback(uint16_t gpio_pin)
{
	if (gpio_pin == LL_GPIO_PIN_0) {
		timeout_start(&user_button.debounce_timeout, BUTTON_DEBOUNCE_TIME_MS);
	}
}
