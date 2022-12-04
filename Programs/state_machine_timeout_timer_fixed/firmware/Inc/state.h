/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file    gpio.h
  * @brief   This file contains all the function prototypes for
  *          the gpio.c file
  ******************************************************************************
  * @attention
  *
  * Copyright (c) 2022 STMicroelectronics.
  * All rights reserved.
  *
  * This software is licensed under terms that can be found in the LICENSE file
  * in the root directory of this software component.
  * If no LICENSE file comes with this software, it is provided AS-IS.
  *
  ******************************************************************************
  */
/* USER CODE END Header */
/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef STATE_H_
#define STATE_H_

#ifdef __cplusplus
extern "C" {
#endif

#include <stdint.h>
#include <stdbool.h>

struct state_machine;

typedef void (*init_fn)(struct state_machine *st_machine, void *data);
typedef void (*run_fn)(struct state_machine *st_machine, void *data);
typedef void (*deinit_fn)(struct state_machine *st_machine, void *data);

enum state_id {
	STATE_NULL = 0,
	STATE_LEFT,
	STATE_TOP,
	STATE_RIGHT,
	STATE_BOTTOM
};

struct state_machine_fns {
	init_fn    init;
	run_fn     run;
	deinit_fn  deinit;
};

struct state_machine {
	enum state_id id;
	struct state_machine_fns *fns;
	void *data;
};

struct state_machine_previous
{
	enum state_id previous_state;
};

extern void state_machine_activate(void);
extern void state_init_states(void);
extern void state_transition(enum state_id next);
extern void state_run_current(void);


/* USER CODE END Prototypes */

#ifdef __cplusplus
}
#endif
#endif /*__STATE_H__ */
