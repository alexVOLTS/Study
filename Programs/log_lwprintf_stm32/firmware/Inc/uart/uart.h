/*
 * uart.h
 *
 *  Created on: Dec 27, 2022
 *      Author: АлексанDOOR
 */

#ifndef UART_H_
#define UART_H_

#include <stdint.h>
#include <stdbool.h>
#include <string.h>

#include "debug_uart.h"
#include "data_uart.h"

#define START_BYTE    0x3A
#define STOP_BYTE     0x68

extern struct msg msg;

struct __attribute__ ((__packed__)) msg {
    uint8_t start_byte;
    uint8_t payload;
    uint8_t stop_byte;
};

struct uart {
    struct msg msg;
    volatile bool flag;
};

void uart_all_init(void);
void uart_check_msg(void);
void uart_send_packet(void);
bool uart_setup_receive_msg(UART_HandleTypeDef *huart, struct msg *msg_ptr);
bool uart_send_byte(UART_HandleTypeDef *huart, uint8_t byte);
bool uart_receive_byte(UART_HandleTypeDef *huart,uint8_t byte);
bool uart_send_msg(UART_HandleTypeDef *huart, struct msg *msg_ptr);

#endif /* UART_H_ */
