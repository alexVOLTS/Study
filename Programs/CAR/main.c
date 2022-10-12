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
static void car_strt();


/******************************************************************************/

int main(void)
{

	printf("\nWelcome to the brand new RUSSIAN CAR");

	car_strt(&lada);
	return 0;
}

static void car_strt(struct car *car_ptr)
{
	car_ptr->enter = true;

	while (car_ptr->enter) {
		check_fuel_overflow(car_ptr);
		car_start(car_ptr);
	}
}
