/*
 * state_right.h
 *
 *  Created on: 28 нояб. 2022 г.
 *      Author: АлексанDOOR
 */

#ifndef STATE_RIGHT_H_
#define STATE_RIGHT_H_

void state_right_init(struct state_machine *st_machine, void *data);
void state_right_run(struct state_machine *st_machine, void *data);
void state_right_deinit(struct state_machine *st_machine, void *data);

#endif /* STATE_RIGHT_H_ */
