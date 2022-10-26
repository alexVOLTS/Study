/**
 ******************************************************************************
 * @file           : event/event_schedule.c
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

#include "event_schedule.h"
/******************************************************************************/
/* Private defines ---------------------------------------------------------- */
/******************************************************************************/
#define EVENT_CHECK(x,y)    			    ((((x) > 24) || ((y) > 60)) ? (false) : (true))
#define EVENT_TIME_MINS_TRANSITION(x,y,a,b,c,d)    ((((((((x) * 60) + (y)) <= (((a) * 60) + (b))) && ((((x) * 60) + (y)) <= (((c) * 60) + (d))))) || ((((((x) * 60) + (y)) >= (((a) * 60) + (b))) && ((((x) * 60) + (y)) >= (((c) * 60) + (d)))))) ? (true) : (false))
#define EVENT_TIME_MINS_TRANSITIONLESS(x,y,a,b,c,d)    ((((((x) * 60) + (y)) >= (((a) * 60) + (b))) && ((((x) * 60) + (y)) <= (((c) * 60) + (d)))) ? (true) : (false))
#define EVENT_ZERO_POINT(x,y)    		    (((x) == 0) && ((y) == 0) ? (true) : (false))
/******************************************************************************/
/* Private variables -------------------------------------------------------- */
/******************************************************************************/
/******************************************************************************/
/* Private function prototypes ---------------------------------------------- */
/******************************************************************************/
/******************************************************************************/

bool event_time_check_start(struct time schedule)
{
	return EVENT_CHECK(schedule.start_time.hour, schedule.start_time.min);
}

bool event_time_check_end(struct time schedule)
{
	return EVENT_CHECK(schedule.end_time.hour, schedule.end_time.min);
}

bool event_triggered_transition(struct time *schedule_ptr)
{
	return EVENT_TIME_MINS_TRANSITION(schedule_ptr->current_time.hour, schedule_ptr->current_time.min, schedule_ptr->start_time.hour, schedule_ptr->start_time.min, schedule_ptr->end_time.hour, schedule_ptr->end_time.min);
}

bool event_triggered_transitionless(struct time *schedule_ptr)
{
	return EVENT_TIME_MINS_TRANSITIONLESS(schedule_ptr->current_time.hour, schedule_ptr->current_time.min, schedule_ptr->start_time.hour, schedule_ptr->start_time.min, schedule_ptr->end_time.hour, schedule_ptr->end_time.min);
}

bool event_zero_point(struct time *schedule_ptr)
{
	return EVENT_ZERO_POINT(schedule_ptr->current_time.hour, schedule_ptr->current_time.min);
}
