/**
 ******************************************************************************
 * @file           : state_machine.c
 * @author         : Alexandr Shabalin
 * @brief          : State machine source file
 ******************************************************************************
 * @attention
 *
 * Copyright (c) 2022 Alexandr Shabalin.
 * All rights NOT reserved.
 *
 * This software is NOT licensed under terms that can be found in the LICENSE file
 * in the root directory of this software component.
 * If no LICENSE file comes with this software, it is provided AS-IS.
 *
 ******************************************************************************
 */
#include "main.h"
#include "gpio.h"
#include "tim.h"

#include "state.h"

void state_run(struct state_machine *led_chain_ptr)
{
	while(1){
		if (led_chain_ptr->flag == true) {
			break;
		}
	}
}

void state_top_init(void)
{
	LL_GPIO_SetOutputPin(GPIOD, LL_GPIO_PIN_13);
}

void state_top_deinit(void)
{
	LL_GPIO_ResetOutputPin(GPIOD, LL_GPIO_PIN_13);
}

void state_bottom_init(void)
{
	LL_GPIO_SetOutputPin(GPIOD, LL_GPIO_PIN_15);
}

void state_bottom_deinit(void)
{
	LL_GPIO_ResetOutputPin(GPIOD, LL_GPIO_PIN_15);
}

void state_left_init(void)
{
	LL_GPIO_SetOutputPin(GPIOD, LL_GPIO_PIN_12);
}

void state_left_deinit(void)
{
	LL_GPIO_ResetOutputPin(GPIOD, LL_GPIO_PIN_12);
}

void state_right_init(void)
{
	LL_GPIO_SetOutputPin(GPIOD, LL_GPIO_PIN_14);
}

void state_right_deinit(void)
{
	LL_GPIO_ResetOutputPin(GPIOD, LL_GPIO_PIN_14);
}

bool state_top_check(struct state_machine led_chain)
{
	return ((STATE_CURRENT_0) || (STATE_PREVIOUS_2) || (STATE_PREVIOUS_3));
}

bool state_bottom_check(struct state_machine led_chain)
{
	return ((STATE_CURRENT_1) && (STATE_PREVIOUS_0));
}

bool state_right_check(struct state_machine led_chain)
{
	return ((STATE_PREVIOUS_1) || (STATE_CURRENT_2));
}

bool state_left_check(struct state_machine led_chain)
{
	return ((STATE_CURRENT_3) && (STATE_PREVIOUS_0));
}

void state_flag_reset(struct state_machine *led_chain_ptr)
{
	led_chain_ptr->flag = false;
}
