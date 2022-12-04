/*
 * state_bottom.c
 *
 *  Created on: 28 нояб. 2022 г.
 *      Author: АлексанDOOR
 */

#include "stm32f4xx_hal.h"
#include "gpio.h"

#include "state.h"
#include "state_bottom.h"
#include "button.h"

#define STATE_BOTTOM_MAX_COUNT    2u

struct state_bottom_data
{
	uint8_t counter;
};

static struct state_machine_fns state_bottom_fns = {
    .init   = state_bottom_init,
    .run    = state_bottom_run,
    .deinit = state_bottom_deinit,
};

static struct state_bottom_data state_bottom_data = {

};

struct state_machine state_bottom = {
	.fns     = &state_bottom_fns,
	.id     = STATE_BOTTOM,
	.data   = &state_bottom_data,
};

static enum state_id state_next_determine(struct state_machine_previous *previous_data);

void state_bottom_init(struct state_machine *st_machine, void *data)
{
	LL_GPIO_SetOutputPin(GPIOD, LL_GPIO_PIN_15);
}

void state_bottom_deinit(struct state_machine *st, void *data)
{
	LL_GPIO_ResetOutputPin(GPIOD, LL_GPIO_PIN_15);
}

void state_bottom_run(struct state_machine *st_machine, void *data)
{
	struct state_machine_previous *previous = (struct state_machine_previous *)data;

	if (button_is_pushed()) {
		enum state_id next_state = state_next_determine(previous);

		state_transition(next_state);
	}
}

static enum state_id state_next_determine(struct state_machine_previous *previous_data)
{
	struct state_bottom_data *bottom_data = (struct state_bottom_data *)state_bottom.data;

    if (bottom_data->counter >= STATE_BOTTOM_MAX_COUNT) {
        bottom_data->counter = 0;
    }

    if (previous_data->previous_state == STATE_TOP && bottom_data->counter == 0) {
        ++bottom_data->counter;
        return STATE_RIGHT;
    }

    if (previous_data->previous_state == STATE_TOP && bottom_data->counter == 1) {
        ++bottom_data->counter;
        return STATE_TOP;
    }

    bottom_data->counter = 0;
    return state_bottom.id;
}
