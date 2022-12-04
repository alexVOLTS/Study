/*
 * timeout.c
 *
 *  Created on: 1 дек. 2022 г.
 *      Author: АлексанDOOR
 */


#include "stm32f4xx_hal.h"
#include "main.h"
#include "timeout.h"


void timeout_start(struct timeout *tim, uint32_t timeout_ms)
{
	tim->timestamp_ms = HAL_GetTick();
	tim->timeout_ms = timeout_ms;
	tim->start_flag = true;
}

bool timeout_started(struct timeout *tim)
{
	return tim->start_flag;
}

bool timeout_elapsed(struct timeout *tim)
{
	if (!tim->start_flag) {
		return false;
	}

	if ((HAL_GetTick() - tim->timestamp_ms) > tim->timeout_ms) {
		tim->start_flag = false;

		return true;
	}

	return false;
}
