/*
 * timeout.h
 *
 *  Created on: 1 дек. 2022 г.
 *      Author: АлексанDOOR
 */

#ifndef TIMEOUT_H_
#define TIMEOUT_H_

#include <stdbool.h>

#ifdef __cplusplus
extern "C" {
#endif /* __cplusplus */

struct timeout {
	volatile bool    start_flag;
	volatile uint32_t timestamp_ms;
	volatile uint32_t timeout_ms;
};

void timeout_start(struct timeout *tim, uint32_t timeout_ms);
bool timeout_started(struct timeout *tim);
bool timeout_elapsed(struct timeout *tim);

#ifdef __cplusplus
extern "C" {
#endif /* __cplusplus */

#endif /* TIMEOUT_H_ */
