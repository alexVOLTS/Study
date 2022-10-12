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
static void on_engine(struct engine *engine_ptr);
static void off_engine(struct engine *engine_ptr);

/******************************************************************************/

void car_engine_start(struct engine *engine_ptr)
{
	if (!engine_ptr->start) {
		on_engine(engine_ptr);
	}
	else {
		off_engine(engine_ptr);
	}
}

static void on_engine(struct engine *engine_ptr)
{
	int eng_start;

	printf("\n\nDo you want to start a car?");
	printf("\n1)YES\t\t2)NO\n");
	scanf("%d", &eng_start);

	engine_ptr->start = eng_start == 1 ? true : false;
}

static void off_engine(struct engine *engine_ptr)
{
	int eng_start;

	printf("\nEngine is already ON");
	printf("\nDo you want to off the engine?");
	printf("\n1)YES\t\t2)NO\n");
	scanf("%d", &eng_start);

	engine_ptr->start = eng_start == 1 ? false : true;
}

int get_temperature(void)
{
	return DEFAULT_ENGINE_TEMP;
}
