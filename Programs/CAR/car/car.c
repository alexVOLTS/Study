/**
 ******************************************************************************
 * @file           : car/car.c
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

#include "car.h"
#include "engine.h"

/******************************************************************************/
/* Private defines ---------------------------------------------------------- */
/******************************************************************************/


/******************************************************************************/
/* Private variables -------------------------------------------------------- */
/******************************************************************************/

int fuel_volume_buy, fuel_volume_drain, eng_temp;

/******************************************************************************/
/* Private function prototypes ---------------------------------------------- */
/******************************************************************************/
/******************************************************************************/

bool car_check_fuel_overflow(struct car *car_ptr)
{
	car_ptr->fuel_overflow_status = car_ptr->fuel > CAR_TOTAL_TANK_VOLUME ? true : false;

	return car_ptr->fuel_overflow_status;
}

void car_buy_fuel(struct car *car_ptr)
{
	printf("\nHow many fuel do you want to buy?\n");
	scanf("%d", &fuel_volume_buy);

	car_ptr->fuel += fuel_volume_buy;

	car_check_fuel_overflow(car_ptr);
}

void car_drain_fuel(struct car *car_ptr)
{
	printf("\nHow many fuel do you want to drain?\n");
	scanf("%d", &fuel_volume_drain);

	car_ptr->fuel -= fuel_volume_drain;

	car_check_fuel_overflow(car_ptr);
}

void car_enter(struct car *car_ptr)
{
	car_ptr->enter = true;
}

void car_exit(struct car *car_ptr)
{
	car_ptr->enter = false;
}
