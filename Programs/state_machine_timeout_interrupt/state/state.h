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

#define STATE_CURRENT_0     (led_chain.current_state == STATE_0)
#define STATE_CURRENT_1	    (led_chain.current_state == STATE_1)
#define STATE_CURRENT_2     (led_chain.current_state == STATE_2)
#define STATE_CURRENT_3     (led_chain.current_state == STATE_3)
#define STATE_PREVIOUS_0    (led_chain.previous_state == STATE_0)
#define STATE_PREVIOUS_1    (led_chain.previous_state == STATE_1)
#define STATE_PREVIOUS_2    (led_chain.previous_state == STATE_2)
#define STATE_PREVIOUS_3    (led_chain.previous_state == STATE_3)

#include <stdint.h>
#include <stdbool.h>

enum state {
	STATE_0 = 0,
	STATE_1,
	STATE_2,
	STATE_3
};

struct state_machine {
	enum state previous_state;
	enum state current_state;
	bool reset;
	bool flag;
};

extern void state_run(struct state_machine *led_chain_ptr);

extern void state_top_init(void);
extern void state_top_deinit(void);
extern bool state_top_check(struct state_machine led_chain);
extern void state_bottom_init(void);
extern void state_bottom_deinit(void);
extern bool state_bottom_check(struct state_machine led_chain);
extern void state_left_init(void);
extern void state_left_deinit(void);
extern bool state_left_check(struct state_machine led_chain);
extern void state_right_init(void);
extern void state_right_deinit(void);
extern bool state_right_check(struct state_machine led_chain);
extern void state_flag_reset(struct state_machine *led_chain_ptr);

/* USER CODE END Prototypes */

#ifdef __cplusplus
}
#endif
#endif /*__STATE_H__ */
