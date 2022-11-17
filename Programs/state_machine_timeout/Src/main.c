/**
 ******************************************************************************
 * @file           : main.c
 * @author         : Alexandr Shabalin
 * @brief          : Main program body
 ******************************************************************************
 * @attention
 *
 * Copyright (c) 2022 Alexandr Shabalin.
 * All rights NOT reserved.
 *
 * This software is NOT licensed under terms that can be found in the LICENSE file
 * in the root directory of this software component.
 * If no LICENSE file comes with this software, it is provided AS-IS.
 *
 ******************************************************************************
 */

#include <stdint.h>
#include <stdbool.h>

#include "gpio.h"
#include "state.h"

#define PREVIOUS_STATE    led_chain_ptr->previous_state
#define CURRENT_STATE     led_chain_ptr->current_state
#define RESET_STATE       led_chain_ptr->reset

static void SystemClock_Config(void);
static void Initialize_MCU(void);
static void activate_state_machine(struct state_machine *led_chain_ptr);
static void perform_state_machine(struct state_machine *led_chain_ptr);
static void perform_state_top(struct state_machine *led_chain_ptr);
static void perform_state_bottom(struct state_machine *led_chain_ptr);
static void perform_state_right(struct state_machine *led_chain_ptr);
static void perform_state_left(struct state_machine *led_chain_ptr);

static struct state_machine led_chain;

int main(void)
{
	Initialize_MCU();

	while(1) {
		activate_state_machine(&led_chain);
		perform_state_machine(&led_chain);
	}
}

static void activate_state_machine(struct state_machine *led_chain_ptr)
{
	CURRENT_STATE = STATE_0;
	PREVIOUS_STATE = STATE_0;
	RESET_STATE = false;
}

static void perform_state_machine(struct state_machine *led_chain_ptr)
{
	while(1) {
		if (state_top_check(led_chain)) {
			perform_state_top(&led_chain);
		}

		else if (state_bottom_check(led_chain)) {
			perform_state_bottom(&led_chain);

			if (RESET_STATE) {
				break;
			}
			CURRENT_STATE = STATE_2;
		}

		else if (state_right_check(led_chain)) {
			perform_state_right(&led_chain);
		}

		else if (state_left_check(led_chain)) {
			perform_state_left(&led_chain);
		}
	}
}

static void perform_state_top(struct state_machine *led_chain_ptr)
{
	state_top_init();
	state_run();
	state_top_deinit();

	CURRENT_STATE = STATE_1;

	if (PREVIOUS_STATE == STATE_2) {
		CURRENT_STATE = STATE_3;
	}
	else if (PREVIOUS_STATE == STATE_3) {
		CURRENT_STATE = STATE_1;
		RESET_STATE = true;
	}

	PREVIOUS_STATE = STATE_0;
}

static void perform_state_bottom(struct state_machine *led_chain_ptr)
{
	state_bottom_init();
	state_run();
	state_bottom_deinit();

	PREVIOUS_STATE = STATE_1;
}

static void perform_state_right(struct state_machine *led_chain_ptr)
{
	state_right_init();
	state_run();
	state_right_deinit();

	PREVIOUS_STATE = STATE_2;
	CURRENT_STATE = STATE_0;
}

static void perform_state_left(struct state_machine *led_chain_ptr)
{
	state_left_init();
	state_run();
	state_left_deinit();

	PREVIOUS_STATE = STATE_3;
	CURRENT_STATE = STATE_0;
}

static void Initialize_MCU(void)
{
	LL_APB2_GRP1_EnableClock(LL_APB2_GRP1_PERIPH_SYSCFG);
	LL_APB1_GRP1_EnableClock(LL_APB1_GRP1_PERIPH_PWR);

	NVIC_SetPriorityGrouping(NVIC_PRIORITYGROUP_4);
	NVIC_SetPriority(SysTick_IRQn, NVIC_EncodePriority(NVIC_GetPriorityGrouping(),15, 0));

	SystemClock_Config();
	MX_GPIO_Init();
}

static void SystemClock_Config(void)
{
  LL_FLASH_SetLatency(LL_FLASH_LATENCY_2);
  while(LL_FLASH_GetLatency()!= LL_FLASH_LATENCY_2)
  {
  }
  LL_PWR_SetRegulVoltageScaling(LL_PWR_REGU_VOLTAGE_SCALE1);
  LL_RCC_HSE_Enable();

   /* Wait till HSE is ready */
  while(LL_RCC_HSE_IsReady() != 1)
  {

  }
  LL_RCC_PLL_ConfigDomain_SYS(LL_RCC_PLLSOURCE_HSE, LL_RCC_PLLM_DIV_4, 84, LL_RCC_PLLP_DIV_2);
  LL_RCC_PLL_Enable();

   /* Wait till PLL is ready */
  while(LL_RCC_PLL_IsReady() != 1)
  {

  }
  LL_RCC_SetAHBPrescaler(LL_RCC_SYSCLK_DIV_1);
  LL_RCC_SetAPB1Prescaler(LL_RCC_APB1_DIV_2);
  LL_RCC_SetAPB2Prescaler(LL_RCC_APB2_DIV_1);
  LL_RCC_SetSysClkSource(LL_RCC_SYS_CLKSOURCE_PLL);

   /* Wait till System clock is ready */
  while(LL_RCC_GetSysClkSource() != LL_RCC_SYS_CLKSOURCE_STATUS_PLL)
  {

  }
  LL_Init1msTick(84000000);
  LL_SetSystemCoreClock(84000000);
}

void Error_Handler(void)
{
  /* USER CODE BEGIN Error_Handler_Debug */
  /* User can add his own implementation to report the HAL error return state */
  __disable_irq();
  while (1)
  {
  }
  /* USER CODE END Error_Handler_Debug */
}

#ifdef  USE_FULL_ASSERT
/**
  * @brief  Reports the name of the source file and the source line number
  *         where the assert_param error has occurred.
  * @param  file: pointer to the source file name
  * @param  line: assert_param error line source number
  * @retval None
  */
void assert_failed(uint8_t *file, uint32_t line)
{
  /* USER CODE BEGIN 6 */
  /* User can add his own implementation to report the file name and line number,
     ex: printf("Wrong parameters value: file %s on line %d\r\n", file, line) */
  /* USER CODE END 6 */
}
#endif /* USE_FULL_ASSERT */
