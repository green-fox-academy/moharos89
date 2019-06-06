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

static void SystemClock_Config(void);

void init_time_it();
void TIM3_IRQHandler();
void HAL_TIM_PeriodElapsedCallback(TIM_HandleTypeDef *htim);
void init_ext_it_button_gas();
void EXTI9_5_IRQHandler();
void HAL_GPIO_EXTI_Callback(uint16_t GPIO_Pin);
void init_ext_it_button_spark();
void init_LED();

TIM_HandleTypeDef IT_time_handle;

volatile int state = 0;
volatile int gas_ammount = 20;

int main(void)
{
	HAL_Init();
	SystemClock_Config();

	init_time_it();
	init_ext_it_button_gas();
	init_ext_it_button_spark();
	init_LED();

	while (1) {
		if (state == 0) {
			HAL_TIM_Base_Stop_IT(&IT_time_handle);
			HAL_GPIO_WritePin(GPIOF , GPIO_PIN_10 , RESET);
		}
		if (state == 1) {
			HAL_TIM_Base_Start_IT(&IT_time_handle);
		}
		if (state == 2 && gas_ammount > 0) {
			HAL_GPIO_WritePin(GPIOF , GPIO_PIN_10 , SET);
		}
	}
}

void init_LED()
{
	__HAL_RCC_GPIOF_CLK_ENABLE();

	GPIO_InitTypeDef led_gpio_config;

	led_gpio_config.Pin = GPIO_PIN_10;
	led_gpio_config.Mode = GPIO_MODE_OUTPUT_PP;
	led_gpio_config.Pull = GPIO_NOPULL;
	led_gpio_config.Speed = GPIO_SPEED_FREQ_HIGH;

	HAL_GPIO_Init(GPIOF, &led_gpio_config);
}

void init_ext_it_button_spark()
{
	__HAL_RCC_GPIOI_CLK_ENABLE()
	;

	GPIO_InitTypeDef button_ext_it;

	button_ext_it.Pin = GPIO_PIN_2;
	button_ext_it.Mode = GPIO_MODE_IT_FALLING;
	button_ext_it.Pull = GPIO_NOPULL;
	button_ext_it.Speed = GPIO_SPEED_FREQ_HIGH;

	HAL_GPIO_Init(GPIOI, &button_ext_it);

	/*Priority pre and sub: 2, 0*/
	HAL_NVIC_SetPriority(EXTI2_IRQn, 1, 0);

	HAL_NVIC_EnableIRQ(EXTI2_IRQn);
}

void EXTI2_IRQHandler()
{
	HAL_GPIO_EXTI_IRQHandler(GPIO_PIN_2);
}

void init_ext_it_button_gas()
{
	__HAL_RCC_GPIOG_CLK_ENABLE()
	;

	GPIO_InitTypeDef button_ext_it;

	button_ext_it.Pin = GPIO_PIN_7;
	button_ext_it.Mode = GPIO_MODE_IT_RISING_FALLING;
	button_ext_it.Pull = GPIO_NOPULL;
	button_ext_it.Speed = GPIO_SPEED_FREQ_HIGH;

	HAL_GPIO_Init(GPIOG, &button_ext_it);

	/*Priority pre and sub: 2, 0*/
	HAL_NVIC_SetPriority(EXTI9_5_IRQn, 2, 0);

	HAL_NVIC_EnableIRQ(EXTI9_5_IRQn);
}

void EXTI9_5_IRQHandler()
{
	HAL_GPIO_EXTI_IRQHandler(GPIO_PIN_7);
}

void HAL_GPIO_EXTI_Callback(uint16_t GPIO_Pin)
{
	if (GPIO_PIN_7 == GPIO_Pin) {
		if (state == 0) {
			state = 1;
		} else {
			state = 0;
		}
	}
	if (GPIO_PIN_2 == GPIO_Pin && state == 1) {
		state = 2;
	}
}

void init_time_it()
{
	__HAL_RCC_TIM3_CLK_ENABLE()
	;

	IT_time_handle.Instance = TIM3;
	IT_time_handle.Init.Prescaler = 54000 - 1;
	IT_time_handle.Init.Period = 2000 - 1;
	IT_time_handle.Init.ClockDivision = TIM_CLOCKDIVISION_DIV1;
	IT_time_handle.Init.CounterMode = TIM_COUNTERMODE_UP;

	HAL_TIM_Base_Init(&IT_time_handle);

	/* 2 pre and 2 sub priority*/
	HAL_NVIC_SetPriority(TIM3_IRQn, 2, 2);

	HAL_NVIC_EnableIRQ(TIM3_IRQn);
}

void TIM3_IRQHandler()
{
	HAL_TIM_IRQHandler(&IT_time_handle);
}

void HAL_TIM_PeriodElapsedCallback(TIM_HandleTypeDef *htim)
{
	if (gas_ammount > 0) {
		gas_ammount--;
	} else {
		state = 0;
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
