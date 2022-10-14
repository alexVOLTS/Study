/**
 ******************************************************************************
 * @file           : car/car.h
 * @author         : Alexandr Shabalin    <shabalin@voltsbattery.com>
 * @brief          : Header for car functions
 ******************************************************************************
 * This module is a confidential and proprietary property of Alexandr Shabalin
 * and possession or use of this module requires written permission
 * of Alexandr Shabalin.
 ******************************************************************************
 */

/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef CAR_CAR_H_
#define CAR_CAR_H_

/******************************************************************************/
/* Includes ----------------------------------------------------------------- */
/******************************************************************************/


#ifdef __cplusplus
extern "C" {
#endif

/******************************************************************************/
/* Public variables --------------------------------------------------------- */
/******************************************************************************/
struct car {
	struct engine *eng_ptr;
	int  fuel;
	bool fuel_overflow_status;
	bool enter;
};

/******************************************************************************/
/* Public functions --------------------------------------------------------- */
/******************************************************************************/
extern void run_car(struct car *car_ptr);

/******************************************************************************/

#ifdef __cplusplus
}
#endif

#endif /* CAR_CAR_H_ */
