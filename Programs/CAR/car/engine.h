/**
 ******************************************************************************
 * @file           : car/engine.h
 * @author         : Alexandr Shabalin    <shabalin@voltsbattery.com>
 * @brief          : Header for engine of car functions
 ******************************************************************************
 * This module is a confidential and proprietary property of Alexandr Shabalin
 * and possession or use of this module requires written permission
 * of Alexandr Shabalin.
 ******************************************************************************
 */

/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef CAR_ENGINE_H_
#define CAR_ENGINE_H_

/******************************************************************************/
/* Includes ----------------------------------------------------------------- */
/******************************************************************************/


#ifdef __cplusplus
extern "C" {
#endif

/******************************************************************************/
/* Public variables --------------------------------------------------------- */
/******************************************************************************/
struct engine {
	bool start;
	int temp;
};

extern struct engine diesel;
/******************************************************************************/

/******************************************************************************/
/* Public functions --------------------------------------------------------- */
/******************************************************************************/
extern void car_engine_start(struct engine *engine_ptr);
extern int get_temperature(void);


/******************************************************************************/

#ifdef __cplusplus
}
#endif


#endif /* CAR_ENGINE_H_ */
