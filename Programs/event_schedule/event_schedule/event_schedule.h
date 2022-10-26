/**
 ******************************************************************************
 * @file           : events/event.h
 * @author         : Alexandr Shabalin    <shabalin@voltsbattery.com>
 * @brief          : Header for event functions
 ******************************************************************************
 * This module is a confidential and proprietary property of Alexandr Shabalin
 * and possession or use of this module requires written permission
 * of Alexandr Shabalin.
 ******************************************************************************
 */

/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef EVENT_EVENT_H_
#define EVENT_EVENT_H_
/******************************************************************************/
/* Includes ----------------------------------------------------------------- */
/******************************************************************************/
#ifdef __cplusplus
extern "C" {
#endif
/******************************************************************************/
/* Public variables --------------------------------------------------------- */
/******************************************************************************/
struct event_schedule_time
{
	int hour;
	int min;
};

struct time
{
	struct event_schedule_time current_time;
	struct event_schedule_time start_time;
	struct event_schedule_time end_time;
};
/******************************************************************************/
/* Public functions --------------------------------------------------------- */
/******************************************************************************/
extern bool event_time_check_start(struct time schedule);
extern bool event_time_check_end(struct time schedule);
extern bool event_triggered(struct time *schedule_ptr);
extern bool event_zero_point(struct time *schedule_ptr);
/******************************************************************************/

#ifdef __cplusplus
}
#endif

#endif /* CAR_CAR_H_ */
