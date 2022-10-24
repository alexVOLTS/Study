/**
 ******************************************************************************
 * @file           : event/event.c
 * @author         : Alexandr Shabalin    <shabalin@voltsbattery.com>
 * @brief          : Event functions
 ******************************************************************************
 * This module is a confidential and proprietary property of Alexandr Shabalin
 * and possession or use of this module requires written permission
 * of Alexandr Shabalin.
 ******************************************************************************
 */

/******************************************************************************/
/* Includes ----------------------------------------------------------------- */
/******************************************************************************/
#include <stdio.h>
#include <locale.h>
#include <float.h>
#include <stdbool.h>

#include "event.h"
/******************************************************************************/
/* Private defines ---------------------------------------------------------- */
/******************************************************************************/
#define EVENT_CHECK(x,y)    			((((x) > 24) || ((y) > 60)) ? (false) : (true))
#define EVENT_TIME_MINS(x,y,a,b,c,d)    ((((((x) * 60) + (y)) >= (((a) * 60) + (b))) && ((((x) * 60) + (y)) <= (((c) * 60) + (d)))) ? (true) : (false))
#define EVENT_ZERO_POINT(x,y)    		(((x) == 0) && ((y) == 0) ? (true) : (false))
/******************************************************************************/
/* Private variables -------------------------------------------------------- */
/******************************************************************************/
/******************************************************************************/
/* Private function prototypes ---------------------------------------------- */
/******************************************************************************/
/******************************************************************************/

bool event_time_check_start(struct time schedule)
{
	return EVENT_CHECK(schedule.start_hour, schedule.start_min);
}

bool event_time_check_end(struct time schedule)
{
	return EVENT_CHECK(schedule.end_hour, schedule.end_min);
}

bool event_triggered(struct time schedule)
{
	return EVENT_TIME_MINS(schedule.current_hour, schedule.current_min, schedule.start_hour, schedule.start_min, schedule.end_hour, schedule.end_min);
}

bool event_zero_point(struct time schedule)
{
	return EVENT_ZERO_POINT(schedule.current_hour, schedule.current_min);
}
