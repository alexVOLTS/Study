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

#define CAR_TOTAL_TANK_VOLUME      43u

/******************************************************************************/
/* Public functions --------------------------------------------------------- */
/******************************************************************************/
extern void car_exit(struct car *car_ptr);
extern void car_drain_fuel(struct car *car_ptr);
extern void car_buy_fuel(struct car *car_ptr);
extern void car_check_fuel_overflow(struct car *car_ptr);
/******************************************************************************/

#ifdef __cplusplus
}
#endif

#endif /* CAR_CAR_H_ */
