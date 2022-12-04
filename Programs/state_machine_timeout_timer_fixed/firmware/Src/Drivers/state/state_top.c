/*
 * state_right.c
 *
 *  Created on: 28 нояб. 2022 г.
 *      Author: АлексанDOOR
 */

#include "stm32f4xx_hal.h"
#include "gpio.h"

#include "state.h"
#include "state_top.h"
#include "button.h"

struct state_top_data
{

};

static struct state_machine_fns state_top_fns = {
    .init   = state_top_init,
    .run    = state_top_run,
    .deinit = state_top_deinit,
};

static struct state_top_data state_top_data = {

};

struct state_machine state_top = {
	.fns     = &state_top_fns,
	.id     = STATE_TOP,
	.data   = &state_top_data,
};

static enum state_id state_next_determine(struct state_machine_previous *previous_data);

void state_top_init(struct state_machine *st_machine, void *data)
{
	LL_GPIO_SetOutputPin(GPIOD, LL_GPIO_PIN_13);
}

void state_top_deinit(struct state_machine *st, void *data)
{
	LL_GPIO_ResetOutputPin(GPIOD, LL_GPIO_PIN_13);
}

void state_top_run(struct state_machine *st_machine, void *data)
{
	struct state_machine_previous *previous = (struct state_machine_previous *)data;

	if (button_is_pushed()) {
		enum state_id next_state = state_next_determine(previous);

		state_transition(next_state);
	}
}

static enum state_id state_next_determine(struct state_machine_previous *previous_data)
{
	if (previous_data->previous_state == STATE_NULL) {
		return STATE_BOTTOM;
	}

	if (previous_data->previous_state == STATE_RIGHT) {
			return STATE_LEFT;
		}

	if (previous_data->previous_state == STATE_LEFT) {
			return STATE_BOTTOM;
		}

	if (previous_data->previous_state == STATE_BOTTOM) {
			return STATE_BOTTOM;
		}

	return state_top.id;
}
