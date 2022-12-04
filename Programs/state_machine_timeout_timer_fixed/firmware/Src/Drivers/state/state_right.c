/*
 * state_right.c
 *
 *  Created on: 28 нояб. 2022 г.
 *      Author: АлексанDOOR
 */

#include "stm32f4xx_hal.h"
#include "gpio.h"

#include "state.h"
#include "state_right.h"
#include "button.h"

struct state_right_data
{

};

static struct state_machine_fns state_right_fns = {
    .init   = state_right_init,
    .run    = state_right_run,
    .deinit = state_right_deinit,
};

static struct state_right_data state_right_data = {

};

struct state_machine state_right = {
	.fns     = &state_right_fns,
	.id     = STATE_RIGHT,
	.data   = &state_right_data,
};

static enum state_id state_next_determine(struct state_machine_previous *previous_data);

void state_right_init(struct state_machine *st_machine, void *data)
{
	LL_GPIO_SetOutputPin(GPIOD, LL_GPIO_PIN_14);
}

void state_right_deinit(struct state_machine *st, void *data)
{
	LL_GPIO_ResetOutputPin(GPIOD, LL_GPIO_PIN_14);
}

void state_right_run(struct state_machine *st_machine, void *data)
{
	struct state_machine_previous *previous = (struct state_machine_previous *)data;

	if (button_is_pushed()) {
		enum state_id next_state = state_next_determine(previous);

		state_transition(next_state);
	}
}

static enum state_id state_next_determine(struct state_machine_previous *previous_data)
{
	if (previous_data->previous_state == STATE_BOTTOM) {
			return STATE_TOP;
		}

	return state_right.id;
}
