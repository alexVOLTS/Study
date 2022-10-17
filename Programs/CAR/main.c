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

#include "car.h"
#include "engine.h"

/******************************************************************************/
/* Private defines ---------------------------------------------------------- */
/******************************************************************************/

/******************************************************************************/
/* Private variables -------------------------------------------------------- */
/******************************************************************************/
static struct car lada = {
		.eng_ptr = &diesel,
};
/******************************************************************************/
/* Private function prototypes ---------------------------------------------- */
/******************************************************************************/
static bool get_in_the_car(struct car *car_ptr);
static void run_car(struct car *car_ptr);
static void start_car(struct car *car_ptr);
static void fill_fuel_volume(struct car *car_ptr);
/******************************************************************************/

int main(void)
{
	printf("\nWelcome to the brand new RUSSIAN CAR");

	if (!get_in_the_car(&lada)) {
		return 0;
	}

	printf("\nEntering the car...\n\n");
	run_car(&lada);

	return 0;
}

static bool get_in_the_car(struct car *car_ptr)
{
	int enter_to_car = 0;

	printf("\nDo you want to enter to the car?");
	printf("\n1)YES\t\t2)NO\n");
	scanf("%d", &enter_to_car);

	if (enter_to_car != 1) {
		printf("\nExiting from the car...");

		car_exit(car_ptr);

		return false;
	}

	car_enter(car_ptr);
	return true;
}

static void run_car(struct car *car_ptr)
{
	while (car_ptr->enter) {
		car_check_fuel_overflow(car_ptr);
		start_car(car_ptr);
	}
}

static void start_car(struct car *car_ptr)
{
	int car_action;

	//enter_car(car_ptr);

	while (car_ptr->enter) {
		printf("\n\nChecking all the systems...");
		printf("\n\nFuel...\n\n");

		if (car_check_fuel_overflow(car_ptr)) {
			printf("\nTANK OVERFLOW!");
			printf("\nDrain the fuel first\n");
			fill_fuel_volume(car_ptr);
		}

		printf("\n******************************************************************\n");
		printf("\nWhat do you want to do?");
		printf("\n1) Start a car\t\t2) Check fuel volume\t\t3) Check engine temperature\t\t4)EXIT\n");
		printf("\n******************************************************************\n\n");
		scanf("%d", &car_action);

		switch(car_action) {
			case 1:
				engine_change_operating_mode(car_ptr->eng_ptr);
				break;
			case 2:
				fill_fuel_volume(car_ptr);
				break;
			case 3:
				car_ptr->eng_ptr->temp = engine_get_temperature();
				printf("\n\nEngine temperature is %d degrees Celsius", car_ptr->eng_ptr->temp);
				break;
			case 4:
				car_exit(car_ptr);
				break;
			default:
				car_exit(car_ptr);
		}
	}
}

static void fill_fuel_volume(struct car *car_ptr)
{
	int gas_tank_status;

	printf("\nYou car gas tank is %d", CAR_TOTAL_TANK_VOLUME);
	printf("\nYou tank has %d liters", car_ptr->fuel);
	printf("\nDo you want to fill the tank or drain fuel?");
	printf("\n1) FILL\t\t2) DRAIN\n\t\t3) EXIT\n");
	scanf("%d", &gas_tank_status);

	switch(gas_tank_status) {
		case 1:
			car_buy_fuel(car_ptr);
			printf("\nNow you have %d liters of fuel", car_ptr->fuel);
			break;
		case 2:
			car_drain_fuel(car_ptr);
			printf("\nNow you have %d liters of fuel", car_ptr->fuel);
			break;
		default:
			printf("\nClosing the fuel tank");
	}
}
