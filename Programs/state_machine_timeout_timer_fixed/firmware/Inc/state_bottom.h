/*
 * state_bottom.h
 *
 *  Created on: 28 нояб. 2022 г.
 *      Author: АлексанDOOR
 */

#ifndef STATE_BOTTOM_H_
#define STATE_BOTTOM_H_

void state_bottom_init(struct state_machine *st_machine, void *data);
void state_bottom_run(struct state_machine *st_machine, void *data);
void state_bottom_deinit(struct state_machine *st_machine, void *data);

#endif /* STATE_BOTTOM_H_ */
