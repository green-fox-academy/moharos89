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

#define ADDR_TC74 (0b1001000 << 1)
#define ADDR_HT16K33 (0b1110000 << 1)

#define System_Setup_Reg  0x20
#define Display_Setup_Reg  0x80
#define ROW_set 0xA0

#define Normal_mode (1 << 0)
#define Display_on_blinking_off (1 << 0)
#define ROW_output 	(0 << 0)

UART_HandleTypeDef uart_handle;
TIM_HandleTypeDef time_handle;
I2C_HandleTypeDef I2C_handle;

void Error_Handler(void);
void SystemClock_Config(void);

void init_uart();
void init_timer();
void init_I2C();
void HT16K33_config()
{
	uint8_t system_setup = (System_Setup_Reg | Normal_mode);
	uint8_t display_on = (Display_Setup_Reg | Display_on_blinking_off);
	uint8_t Row_output_mode = (ROW_set | ROW_output);
	uint8_t brightness = 0b11101111;

	HAL_I2C_Master_Transmit(&I2C_handle , ADDR_HT16K33 , &system_setup , sizeof(system_setup) , 100);
	HAL_I2C_Master_Transmit(&I2C_handle , ADDR_HT16K33 , &display_on , sizeof(display_on) , 100);
	HAL_I2C_Master_Transmit(&I2C_handle , ADDR_HT16K33 , &Row_output_mode , sizeof(Row_output_mode) , 100);
	HAL_I2C_Master_Transmit(&I2C_handle , ADDR_HT16K33 , &brightness , sizeof(brightness) , 100);
}



int main(void)
{
	HAL_Init();
	init_uart();
	init_timer();

	init_I2C();

	HAL_TIM_Base_Start(&time_handle);
	HT16K33_config();

	uint8_t temp_reg = 0;
	uint8_t temp_value;
	char string[10];
	uint8_t first_column = 0b00011000;
	uint8_t second_column = 0b00100100;
	uint8_t thirst_column = 0b00100010;
	uint8_t fourst_column = 0b00010001;
	uint8_t fifth_column = 0b00010001;
	uint8_t sixth_column = 0b00100010;
	uint8_t seventh_column = 0b00100100;
	uint8_t eights_column = 0b00011000;


	while (1) {
		HAL_I2C_Mem_Write(&I2C_handle, ADDR_HT16K33, 0, I2C_MEMADD_SIZE_8BIT, &first_column, 1, 100);
		HAL_I2C_Mem_Write(&I2C_handle, ADDR_HT16K33, 2, I2C_MEMADD_SIZE_8BIT, &second_column, 1, 100);
		HAL_I2C_Mem_Write(&I2C_handle, ADDR_HT16K33, 4, I2C_MEMADD_SIZE_8BIT, &thirst_column, 1, 100);
		HAL_I2C_Mem_Write(&I2C_handle, ADDR_HT16K33, 6, I2C_MEMADD_SIZE_8BIT, &fourst_column, 1, 100);
		HAL_I2C_Mem_Write(&I2C_handle, ADDR_HT16K33, 8, I2C_MEMADD_SIZE_8BIT, &fifth_column, 1, 100);
		HAL_I2C_Mem_Write(&I2C_handle, ADDR_HT16K33, 10, I2C_MEMADD_SIZE_8BIT, &sixth_column, 1, 100);
		HAL_I2C_Mem_Write(&I2C_handle, ADDR_HT16K33, 12, I2C_MEMADD_SIZE_8BIT, &seventh_column, 1, 100);
		HAL_I2C_Mem_Write(&I2C_handle, ADDR_HT16K33, 14, I2C_MEMADD_SIZE_8BIT, &eights_column, 1, 100);

	}
}

void init_I2C()
{
	__HAL_RCC_GPIOB_CLK_ENABLE()
	;

	GPIO_InitTypeDef SCL_SDA_config;

	SCL_SDA_config.Pin = GPIO_PIN_8 | GPIO_PIN_9;
	SCL_SDA_config.Mode = GPIO_MODE_AF_OD;
	SCL_SDA_config.Pull = GPIO_PULLUP;
	SCL_SDA_config.Speed = GPIO_SPEED_FREQ_HIGH;
	SCL_SDA_config.Alternate = GPIO_AF4_I2C1;

	HAL_GPIO_Init(GPIOB, &SCL_SDA_config);

	__HAL_RCC_I2C1_CLK_ENABLE();

	I2C_handle.Instance = I2C1;
	I2C_handle.Init.Timing = 0x40912732;
	I2C_handle.Init.DualAddressMode = I2C_ADDRESSINGMODE_7BIT;

	HAL_I2C_Init(&I2C_handle);
}

void init_timer()
{
	__HAL_RCC_TIM2_CLK_ENABLE()
	;

	time_handle.Instance = TIM2;
	time_handle.Init.Prescaler = 10800 - 1;
	time_handle.Init.Period = 10000 - 1;
	time_handle.Init.CounterMode = TIM_COUNTERMODE_UP;
	time_handle.Init.ClockDivision = TIM_CLOCKDIVISION_DIV1;

	HAL_TIM_Base_Init(&time_handle);
}

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
