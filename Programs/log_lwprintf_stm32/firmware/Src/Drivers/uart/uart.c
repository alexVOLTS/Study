/**
 ******************************************************************************
 * @file           : uart.c
 * @author         : Aleksandr Shabalin       <alexnv97@gmail.com>
 * @brief          : Uart usage file
 ******************************************************************************
 * ----------------- Copyright (c) 2022 Aleksandr Shabalin------------------- *
 ******************************************************************************
 ******************************************************************************
 */

/******************************************************************************/
/* Includes ----------------------------------------------------------------- */
/******************************************************************************/
#include "indication.h"
#include "uart.h"

struct uart debug_uart;
struct uart data_uart;

/**
 * @brief          Initialization of all uarts
 */
void uart_all_init(void)
{
    debug_uart_init();
    //data_uart_init();
}
/******************************************************************************/

void uart_check_msg(void)
{
    if (debug_uart.flag) {
        if(!debug_uart_validate_msg(&debug_uart.msg)) {
            printf("Received incorrect msg");
            for (int i = 0; i < sizeof(struct msg); i++) {
              //  printf("0x%x ", info_uart.msg.payload[i]);
            }
            printf("\r\n");
        }
        else {
            switch (debug_uart.msg.payload) {
                case UART_LED_TOGGLE:
                    HAL_GPIO_TogglePin(LED_RIGHT_GPIO_Port, LED_RIGHT_Pin);
                    break;
                case UART_BLINK_LED:
                    break; // TODO implement command
                default:
                    printf("Received incorrect command 0x%x\r\n", debug_uart.msg.payload);
                    break;
            }
        }
        debug_uart.flag = false;
        memset(&debug_uart.msg, 0x00, sizeof(struct msg));
        uart_setup_receive_msg(&huart2, &debug_uart.msg);
    }
}

/**
 * @brief          Enable interrupt receiving message
 */
bool uart_setup_receive_msg(UART_HandleTypeDef *huart, struct msg *msg_ptr)
{
    return HAL_UART_Receive_IT(huart, (uint8_t*)msg_ptr, sizeof(msg_ptr)) == HAL_OK;
}
/******************************************************************************/

void uart_send_packet(void)
{
    msg = data_uart_create_msg(UART_LED_TOGGLE);
    printf("Here's your msg: %d %d %d\r\n", msg.start_byte, msg.payload, msg.stop_byte);
    if (!uart_send_msg(&huart3, &msg)) {
        printf("Sending msg error!\r\n");
        indication_led_error();
    }
}
/**
 * @brief          Blocking USART2 send/receive functions
 */
bool uart_send_msg(UART_HandleTypeDef *huart, struct msg *msg_ptr)
{
    return HAL_UART_Transmit(huart, (uint8_t*)msg_ptr, sizeof(msg_ptr), HAL_MAX_DELAY) == HAL_OK;
}

bool uart_send_byte(UART_HandleTypeDef *huart, uint8_t byte)
{
    return HAL_UART_Transmit(huart, &byte, sizeof(byte), HAL_MAX_DELAY) == HAL_OK;
}

bool uart_receive_byte(UART_HandleTypeDef *huart,uint8_t byte)
{
    return HAL_UART_Receive(huart, &byte, sizeof(byte), HAL_MAX_DELAY) == HAL_OK;
}
/******************************************************************************/

/**
 * @brief          Interrupt callbacks
 *
 */
void HAL_UART_TxCpltCallback(UART_HandleTypeDef *huart)
{

}

void HAL_UART_RxCpltCallback(UART_HandleTypeDef *huart)
{
    printf("Flag is TRUE!\r\n");
    debug_uart.flag = true;
}

void HAL_UART_ErrorCallback(UART_HandleTypeDef *huart)
{

}
/******************************************************************************/
