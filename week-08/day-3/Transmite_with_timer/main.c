/**
 ******************************************************************************
 * @file    main.c
 * @author  Ac6
 * @version V1.0
 * @date    01-December-2013
 * @brief   Default main function.
 ******************************************************************************
 */

#include "stm32f7xx.h"
#include "stm32746g_discovery.h"
#include <string.h>

UART_HandleTypeDef uart_handle;
TIM_HandleTypeDef time_handle;

void Error_Handler(void);
void SystemClock_Config(void);

void init_uart()
{
	GPIO_InitTypeDef GPIOTx_handle;
	GPIO_InitTypeDef GPIORx_handle;

	__HAL_RCC_GPIOA_CLK_ENABLE()
	;
	__HAL_RCC_GPIOB_CLK_ENABLE()
	;

	GPIOTx_handle.Pin = GPIO_PIN_9;
	GPIOTx_handle.Mode = GPIO_MODE_AF_PP;
	GPIOTx_handle.Pull = GPIO_NOPULL;
	GPIOTx_handle.Speed = GPIO_SPEED_FAST;
	GPIOTx_handle.Alternate = GPIO_AF7_USART1;

	HAL_GPIO_Init(GPIOA, &GPIOTx_handle);

	GPIORx_handle.Pin = GPIO_PIN_7;
	GPIORx_handle.Mode = GPIO_MODE_AF_PP;
	GPIORx_handle.Pull = GPIO_NOPULL;
	GPIORx_handle.Speed = GPIO_SPEED_FAST;
	GPIORx_handle.Alternate = GPIO_AF7_USART1;

	HAL_GPIO_Init(GPIOB, &GPIORx_handle);

	__HAL_RCC_USART1_CLK_ENABLE()
	;

	uart_handle.Instance = USART1;
	uart_handle.Init.BaudRate = 115200;
	uart_handle.Init.WordLength = UART_WORDLENGTH_8B;
	uart_handle.Init.StopBits = UART_STOPBITS_1;
	uart_handle.Init.Parity = UART_PARITY_NONE;
	uart_handle.Init.Mode = UART_MODE_TX_RX;

	HAL_UART_Init(&uart_handle);
}

void init_timer()
{
	__HAL_RCC_TIM2_CLK_ENABLE()
	;

	time_handle.Instance = TIM2;
	time_handle.Init.Prescaler = 10800 - 1;
	time_handle.Init.Period = 1000 - 1;
	time_handle.Init.CounterMode = TIM_COUNTERMODE_UP;
	time_handle.Init.ClockDivision = TIM_CLOCKDIVISION_DIV1;

	HAL_TIM_Base_Init(&time_handle);
}

int main(void)
{
	HAL_Init();
	init_uart();
	init_timer();

	HAL_TIM_Base_Start(&time_handle);

	char string[] = "Hello World!\r\n";

	uint16_t time_value;

	while (1) {
		time_value = __HAL_TIM_GET_COUNTER(&time_handle);
		if (time_value == 0) {
			HAL_UART_Transmit(&uart_handle, (uint8_t *) string, strlen(string),
					0xFFFF);
		}
	}
}

void Error_Handler(void)
{
}

void SystemClock_Config(void)
{
	RCC_OscInitTypeDef RCC_OscInitStruct = { 0 };
	RCC_ClkInitTypeDef RCC_ClkInitStruct = { 0 };

	/**Configure the main internal regulator output voltage */
	__HAL_RCC_PWR_CLK_ENABLE()
	;
	__HAL_PWR_VOLTAGESCALING_CONFIG(PWR_REGULATOR_VOLTAGE_SCALE1);

	/**Initializes the CPU, AHB and APB busses clocks */
	RCC_OscInitStruct.OscillatorType = RCC_OSCILLATORTYPE_HSI;
	RCC_OscInitStruct.HSIState = RCC_HSI_ON;
	RCC_OscInitStruct.HSICalibrationValue = RCC_HSICALIBRATION_DEFAULT;
	RCC_OscInitStruct.PLL.PLLState = RCC_PLL_ON;
	RCC_OscInitStruct.PLL.PLLSource = RCC_PLLSOURCE_HSI;
	RCC_OscInitStruct.PLL.PLLM = 8;
	RCC_OscInitStruct.PLL.PLLN = 216;
	RCC_OscInitStruct.PLL.PLLP = RCC_PLLP_DIV2;
	RCC_OscInitStruct.PLL.PLLQ = 2;

	if (HAL_RCC_OscConfig(&RCC_OscInitStruct) != HAL_OK) {
		Error_Handler();
	}

	/**Activate the Over-Drive mode */
	if (HAL_PWREx_EnableOverDrive() != HAL_OK) {
		Error_Handler();
	}

	/**Initializes the CPU, AHB and APB busses clocks */
	RCC_ClkInitStruct.ClockType = RCC_CLOCKTYPE_HCLK | RCC_CLOCKTYPE_SYSCLK
			| RCC_CLOCKTYPE_PCLK1 | RCC_CLOCKTYPE_PCLK2;
	RCC_ClkInitStruct.SYSCLKSource = RCC_SYSCLKSOURCE_PLLCLK;
	RCC_ClkInitStruct.AHBCLKDivider = RCC_SYSCLK_DIV1;
	RCC_ClkInitStruct.APB1CLKDivider = RCC_HCLK_DIV4;
	RCC_ClkInitStruct.APB2CLKDivider = RCC_HCLK_DIV2;

	if (HAL_RCC_ClockConfig(&RCC_ClkInitStruct, FLASH_LATENCY_7) != HAL_OK) {
		Error_Handler();
	}
}
