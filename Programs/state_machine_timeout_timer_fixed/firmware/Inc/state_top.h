/*
 * state_top.h
 *
 *  Created on: 28 нояб. 2022 г.
 *      Author: АлексанDOOR
 */

#ifndef STATE_TOP_H_
#define STATE_TOP_H_

void state_top_init(struct state_machine *st_machine, void *data);
void state_top_run(struct state_machine *st_machine, void *data);
void state_top_deinit(struct state_machine *st_machine, void *data);

#endif /* STATE_TOP_H_ */
