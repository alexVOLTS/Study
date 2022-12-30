/*
 * button.c
 *
 *  Created on: Dec 6, 2022
 *      Author: АлексанDOOR
 */

#include <stdbool.h>

#include "stm32f4xx_hal.h"
#include "tim.h"
#include "button.h"
#include "indication.h"

#define BUTTON_DEBOUNCE_TIME_MS    50u

struct user_button {
	struct timeout debounce_timeout;
};

static struct user_button user_button;

void Initialize_Button(void)
{
	GPIO_InitTypeDef GPIO_InitStruct = {0};

   __HAL_RCC_GPIOH_CLK_ENABLE();
   __HAL_RCC_GPIOD_CLK_ENABLE();

   HAL_NVIC_SetPriority(EXTI0_IRQn, 0, 0);
   HAL_NVIC_EnableIRQ(EXTI0_IRQn);

   /*Configure GPIO pin : PtPin */
   GPIO_InitStruct.Pin = BUTTON_Pin;
   GPIO_InitStruct.Mode = GPIO_MODE_IT_RISING;
   GPIO_InitStruct.Pull = GPIO_NOPULL;
   HAL_GPIO_Init(BUTTON_GPIO_Port, &GPIO_InitStruct);
}

bool button_is_pushed(void)
{
	if (!timeout_started(&user_button.debounce_timeout)) {
		return false;
	}

	if (!timeout_elapsed(&user_button.debounce_timeout)) {
		return false;
	}

	return HAL_GPIO_ReadPin(BUTTON_GPIO_Port, BUTTON_Pin) == GPIO_PIN_SET;
}

void EXTI0_IRQHandler(void)
{
	HAL_GPIO_EXTI_IRQHandler(BUTTON_Pin);
}

void HAL_GPIO_EXTI_Callback(uint16_t gpio_pin)
{
	if (gpio_pin == BUTTON_Pin) {
		indication_led_button();
		timeout_start(&user_button.debounce_timeout, BUTTON_DEBOUNCE_TIME_MS);
	}
}
