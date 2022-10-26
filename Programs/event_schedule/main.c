/*
 ******************************************************************************
 * @file           : main.c
 * @author         : Alexandr Shabalinn    <shabalin@voltsbattery.com>
 * @brief          : Main program body
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
#include <conio.h>

#include "event_schedule/event_schedule.h"

/******************************************************************************/
/* Private defines ---------------------------------------------------------- */
/******************************************************************************/
/******************************************************************************/
/* Private variables -------------------------------------------------------- */
/******************************************************************************/
static struct time schedule;
/******************************************************************************/
/* Private function prototypes ---------------------------------------------- */
/******************************************************************************/
static void run_schedule(struct time *schedule_ptr);
/******************************************************************************/

int main(void)
{
	run_schedule(&schedule);

	return 0;
}

static void run_schedule(struct time *schedule_ptr)
{
	bool event_trigger;
	bool start_check = false;
	bool end_check = false;
	bool zero_check = false;

	while(!start_check) {
		printf("\nInput event start time HH:MM format: ");
		scanf("%d%d", &schedule_ptr->start_time.hour, &schedule_ptr->start_time.min);

		start_check = event_time_check_start(schedule);
	}

	while(!end_check) {
		printf("\nInput event end time HH:MM format: ");
		scanf("%d%d", &schedule_ptr->end_time.hour, &schedule_ptr->end_time.min);

		end_check = event_time_check_end(schedule);
	}

	if (schedule_ptr->start_time.hour > schedule_ptr->end_time.hour) {
		while(!zero_check) {
			printf("\nInput current time HH:MM format: \n");
			scanf("%d%d", &schedule_ptr->current_time.hour, &schedule_ptr->current_time.min);

			zero_check = event_zero_point(&schedule);

			event_trigger = event_triggered_transition(&schedule);

			if (event_trigger) {
				printf("\n\n\t\t\t\t\tEVENT HAS TRIGGERED!!!\n\n");
			}
		}
	}
	else {
		while(!zero_check) {
			printf("\nInput current time HH:MM format: \n");
			scanf("%d%d", &schedule_ptr->current_time.hour, &schedule_ptr->current_time.min);

			zero_check = event_zero_point(&schedule);

			event_trigger = event_triggered_transitionless(&schedule);

			if (event_trigger) {
				printf("\n\n\t\t\t\t\tEVENT HAS TRIGGERED!!!\n\n");
			}
		}
	}
}

