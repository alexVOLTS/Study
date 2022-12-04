/*
 * state_left.c
 *
 *  Created on: 28 нояб. 2022 г.
 *      Author: АлексанDOOR
 */

#include "stm32f4xx_hal.h"
#include "gpio.h"

#include "state.h"
#include "state_left.h"
#include "button.h"

struct state_left_data
{

};

static struct state_machine_fns state_left_fns = {
    .init   = state_left_init,
    .run    = state_left_run,
    .deinit = state_left_deinit,
};

static struct state_left_data state_left_data = {

};

struct state_machine state_left = {
	.fns     = &state_left_fns,
	.id     = STATE_LEFT,
	.data   = &state_left_data,
};

static enum state_id state_next_determine(struct state_machine_previous *previous_data);

void state_left_init(struct state_machine *st_machine, void *data)
{
	LL_GPIO_SetOutputPin(GPIOD, LL_GPIO_PIN_12);
}

void state_left_deinit(struct state_machine *st, void *data)
{
	LL_GPIO_ResetOutputPin(GPIOD, LL_GPIO_PIN_12);
}

void state_left_run(struct state_machine *st_machine, void *data)
{
	struct state_machine_previous *previous = (struct state_machine_previous *)data;

	if (button_is_pushed()) {
		enum state_id next_state = state_next_determine(previous);

		state_transition(next_state);
	}
}

static enum state_id state_next_determine(struct state_machine_previous *previous_data)
{
	if (previous_data->previous_state == STATE_TOP) {
			return STATE_TOP;
		}

	return state_left.id;
}
