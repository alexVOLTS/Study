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

#include "state.h"

#define INIT_STATE    STATE_TOP

extern struct state_machine state_top;
extern struct state_machine state_left;
extern struct state_machine state_right;
extern struct state_machine state_bottom;

static struct state_machine *state_get_by_id(enum state_id id);

static struct state_machine *current_state;
static struct state_machine *next_state;
static volatile bool state_need_change;

static struct state_machine_previous previous = {
		.previous_state = STATE_NULL
};

static void state_init(struct state_machine *state_machine);
static void state_run(struct state_machine *state_machine);
static void state_deinit(struct state_machine *state_machine);

void state_machine_activate(void)
{
	state_transition(INIT_STATE);
}

void state_run_current(void)
{
	if (state_need_change) {
		state_deinit(current_state);
		previous.previous_state = current_state->id;

		state_init(next_state);
		current_state = next_state;
		next_state = NULL;

		state_need_change = false;
	}

	state_run(current_state);
}

static void state_init(struct state_machine *state_machine)
{
	if (state_machine == NULL || state_machine->fns->init == NULL) {
		return;
	}

	state_machine->fns->init(state_machine, &previous);
}

static void state_run(struct state_machine *state_machine)
{
	if (state_machine == NULL || state_machine->fns->init == NULL) {
		return;
	}

	state_machine->fns->run(state_machine, &previous);
}

static void state_deinit(struct state_machine *state_machine)
{
	if (state_machine == NULL || state_machine->fns->init == NULL) {
		return;
	}

	state_machine->fns->deinit(state_machine, &previous);
}

void state_transition(enum state_id next)
{
	next_state = state_get_by_id(next);
	state_need_change = true;
}

static struct state_machine *state_get_by_id(enum state_id id)
{
	struct state_machine *state_found = NULL;

	switch (id) {
		case STATE_TOP:
			state_found = &state_top;
			break;
		case STATE_LEFT:
			state_found = &state_left;
			break;
		case STATE_RIGHT:
			state_found = &state_right;
			break;
		case STATE_BOTTOM:
			state_found = &state_bottom;
			break;
		default:
			break;
	}

	return state_found;
}

//void state_top_init(void)
//{
//	LL_GPIO_SetOutputPin(GPIOD, LL_GPIO_PIN_13);
//}
//
//void state_top_deinit(void)
//{
//	LL_GPIO_ResetOutputPin(GPIOD, LL_GPIO_PIN_13);
//}
//
//void state_bottom_init(void)
//{
//	LL_GPIO_SetOutputPin(GPIOD, LL_GPIO_PIN_15);
//}
//
//void state_bottom_deinit(void)
//{
//	LL_GPIO_ResetOutputPin(GPIOD, LL_GPIO_PIN_15);
//}
//
//void state_left_init(void)
//{
//	LL_GPIO_SetOutputPin(GPIOD, LL_GPIO_PIN_12);
//}
//
//void state_left_deinit(void)
//{
//	LL_GPIO_ResetOutputPin(GPIOD, LL_GPIO_PIN_12);
//}
//
//void state_right_init(void)
//{
//	LL_GPIO_SetOutputPin(GPIOD, LL_GPIO_PIN_14);
//}
//
//void state_right_deinit(void)
//{
//	LL_GPIO_ResetOutputPin(GPIOD, LL_GPIO_PIN_14);
//}
//
//bool state_top_check(struct state_machine led_chain)
//{
//	return (((STATE_CURRENT_0) && (STATE_PREVIOUS_2)) || ((STATE_CURRENT_0) && (STATE_PREVIOUS_3)) || ((STATE_CURRENT_0) && (STATE_PREVIOUS_0)));
//}
//
//bool state_bottom_check(struct state_machine led_chain)
//{
//	return ((STATE_CURRENT_1) && (STATE_PREVIOUS_0));
//}
//
//bool state_right_check(struct state_machine led_chain)
//{
//	return ((STATE_PREVIOUS_1) && (STATE_CURRENT_2));
//}
//
//bool state_left_check(struct state_machine led_chain)
//{
//	return ((STATE_CURRENT_3) && (STATE_PREVIOUS_0));
//}
