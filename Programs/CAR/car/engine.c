/**
 ******************************************************************************
 * @file           : car/engine.c
 * @author         : Alexandr Shabalin    <shabalin@voltsbattery.com>
 * @brief          : Car study model on C language
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

#include "engine.h"

/******************************************************************************/
/* Private defines ---------------------------------------------------------- */
/******************************************************************************/

#define DEFAULT_ENGINE_TEMP    25u

/******************************************************************************/
/* Private variables -------------------------------------------------------- */
/******************************************************************************/

struct engine diesel;

/******************************************************************************/
/* Private function prototypes ---------------------------------------------- */
/******************************************************************************/



/******************************************************************************/

void car_engine_start(struct engine *engine_ptr)
{
	int eng_start;

	if (!engine_ptr->start) {
		printf("\n\nDo you want to start a car?");
		printf("\n1)YES\t\t2)NO\n");
		scanf("%d", &eng_start);
		if (eng_start == 1) {
			engine_ptr->start = true;
		}
		else {
			engine_ptr->start = false;
		}
	}
	else {
		printf("\nEngine is already ON");
		printf("\nDo you want to off the engine?");
		printf("\n1)YES\t\t2)NO\n");
		scanf("%d", &eng_start);
		if (eng_start == 1) {
			engine_ptr->start = false;
		}
		else {
			engine_ptr->start = true;
		}

	}

	if (engine_ptr->start) {
		printf("\nStarting...");
	}
	else {
		printf("\n");
	}
}

int get_temperature(void)
{
	return DEFAULT_ENGINE_TEMP;
}







