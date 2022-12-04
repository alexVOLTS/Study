/*
 * state_left.h
 *
 *  Created on: 28 нояб. 2022 г.
 *      Author: АлексанDOOR
 */

#ifndef STATE_LEFT_H_
#define STATE_LEFT_H_

void state_left_init(struct state_machine *st_machine, void *data);
void state_left_run(struct state_machine *st_machine, void *data);
void state_left_deinit(struct state_machine *st_machine, void *data);

#endif /* STATE_LEFT_H_ */
