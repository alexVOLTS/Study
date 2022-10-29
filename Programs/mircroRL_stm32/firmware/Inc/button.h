/*
 * button.h
 *
 *  Created on: Dec 6, 2022
 *      Author: АлексанDOOR
 */

#ifndef BUTTON_H_
#define BUTTON_H_

/******************************************************************************/
/* Includes ----------------------------------------------------------------- */
/******************************************************************************/
#include <stdint.h>
#include <stdbool.h>

#include "main.h"
#include "tim.h"
#include "stm32f4xx_hal.h"

/******************************************************************************/
/* Public defines ----------------------------------------------------------- */
/******************************************************************************/
#define BUTTON_DEBOUNCE_TIME_MS    (50u)

#define BUTTON_Pin          GPIO_PIN_0
#define BUTTON_GPIO_Port    GPIOA

/******************************************************************************/
/* Public variables --------------------------------------------------------- */
/******************************************************************************/
enum button_mode {
	BUTTON_ONE_CLICK = 0,
	BUTTON_DOUBLE_CLICK,
	BUTTON_HELD_PRESSED
};

/******************************************************************************/
/* Public functions --------------------------------------------------------- */
/******************************************************************************/
extern void initialize_button(void);
extern bool button_is_pushed(void);
extern void button_check_mode(void);

/******************************************************************************/

#endif /* BUTTON_H_ */