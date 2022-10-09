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

#define TOTAL_TANK_VOLUME      43u

/******************************************************************************/
/* Private variables -------------------------------------------------------- */
/******************************************************************************/

int car_action, gas_tank_status, fuel_volume_buy, fuel_volume_drain, eng_temp;

/******************************************************************************/
/* Private function prototypes ---------------------------------------------- */
/******************************************************************************/

static void fill_fuel_volume(struct car *car_ptr);
static void exit_car(struct car *car_ptr);
static void enter_car(struct car *car_ptr);

/******************************************************************************/

void car_start(struct car *car_ptr)
{
	enter_car(car_ptr);

	while (car_ptr->enter) {

		printf("\nChecking all the systems...");
		printf("\nFuel...");

		if (car_ptr->fuel > TOTAL_TANK_VOLUME) {
			printf("\nTANK OVERFLOW!");
			printf("\nDrain the fuel first");
			fill_fuel_volume(car_ptr);
		}

		printf("\n******************************************************************\n\n");
		printf("\nWhat do you want to do?");
		printf("\n1) Start a car\t\t2) Check fuel volume\t\t3) Check engine temperature\t\t4)EXIT\n");
		printf("\n******************************************************************\n\n");
		scanf("%d", &car_action);

		switch(car_action) {
			case 1:
				car_engine_start(car_ptr->eng_ptr);
				break;
			case 2:
				fill_fuel_volume(car_ptr);
				break;
			case 3:
				car_ptr->eng_ptr->temp = get_temperature();
				break;
			case 4:
				exit_car(car_ptr);
				break;
		}
	}
}

static void fill_fuel_volume(struct car *car_ptr)
{
	printf("\nYou car gas tank is %d", TOTAL_TANK_VOLUME);
	printf("\nYou tank has %d liters", car_ptr->fuel);
	printf("\nDo you want to fill the tank or drain fuel?");
	printf("\n1) FILL\t\t2) DRAIN\n\t\t3) EXIT\n");
	scanf("%d", &gas_tank_status);

	if (gas_tank_status == 1) {
		printf("\nHow many fuel do you want to buy?");
		scanf("%d", &fuel_volume_buy);
		car_ptr->fuel += fuel_volume_buy;

		printf("\nNow you have %d liters of fuel", car_ptr->fuel);

		check_fuel_overflow(car_ptr);
	}
	else if (gas_tank_status == 2) {
		printf("\nHow many fuel do you want to drain?");
		scanf("%d", &fuel_volume_drain);
		car_ptr->fuel -= fuel_volume_drain;

		printf("\nNow you have %d liters of fuel", car_ptr->fuel);

		check_fuel_overflow(car_ptr);
	}
	else {
		printf("\nClosing the fuel tank");
	}
}

void check_fuel_overflow(struct car *car_ptr)
{
	if (car_ptr->fuel > TOTAL_TANK_VOLUME) {
		car_ptr->fuel_overflow_status = true;
	}
	else {
		car_ptr->fuel_overflow_status = false;
	}
}

static void enter_car(struct car *car_ptr)
{
	int enter_to_car = 0;

	printf("\nDo you want to enter to the car?");
	printf("\n1)YES\t\t2)NO\n");
	scanf("%d", &enter_to_car);

	if (enter_to_car == 1) {
		car_ptr->enter = true;
	}
	else {
		car_ptr->enter = false;
	}
}

void exit_car(struct car *car_ptr)
{
	printf("\nExiting from the car...");
	car_ptr->enter = false;
}
