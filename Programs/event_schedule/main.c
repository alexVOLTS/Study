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

#include "event.h"

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
static void run_schedule(struct time schedule);
/******************************************************************************/

int main(void)
{
	run_schedule(schedule);

	return 0;
}

static void run_schedule(struct time schedule)
{
	bool event_trigger;
	bool start_check = false;
	bool end_check = false;
	bool zero_check = false;

	while(!start_check) {
		printf("\nInput event start time HH:MM format: ");
		scanf("%d%d", &schedule.start_hour, &schedule.start_min);

		start_check = event_time_check_start(schedule);
	}

	while(!end_check) {
		printf("\nInput event end time HH:MM format: ");
		scanf("%d%d", &schedule.end_hour, &schedule.end_min);

		end_check = event_time_check_end(schedule);
	}

	while(!zero_check) {
		printf("\nInput current time HH:MM format: \n");
		scanf("%d%d", &schedule.current_hour, &schedule.current_min);

		zero_check = event_zero_point(schedule);

		event_trigger = event_triggered(schedule);

		if (event_trigger) {
			printf("\n\n\t\t\t\t\tEVENT HAS TRIGGERED!!!\n\n");
		}
	}
}

