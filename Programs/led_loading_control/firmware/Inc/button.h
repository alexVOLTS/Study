/*
 * button.h
 *
 *  Created on: Dec 6, 2022
 *      Author: АлексанDOOR
 */

#ifndef BUTTON_H_
#define BUTTON_H_

#include <stdint.h>
#include <stdbool.h>

#include "main.h"
#include "tim.h"
#include "stm32f4xx_hal.h"

extern void Initialize_Button(void);
extern bool button_is_pushed(void);

#define BUTTON_Pin          GPIO_PIN_0
#define BUTTON_GPIO_Port    GPIOA

#endif /* BUTTON_H_ */
