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
void led_init();
void timer_init1();
void timer_init2();
void timer_init3();
void init_button_IT();
void EXTI9_5_IRQHandler();

volatile int status = 0;
volatile int timer_start = 0;

TIM_HandleTypeDef base_timer1;
TIM_HandleTypeDef base_timer2;
TIM_HandleTypeDef base_timer3;

int main(void)
{
	HAL_Init();
	SystemClock_Config();

	led_init();
	timer_init1();
	timer_init2();
	timer_init3();

	init_button_IT();

	HAL_TIM_Base_Start(&base_timer1);

	uint16_t time1_value;
	uint16_t time2_value;
	uint16_t time3_value;
	int start = 0;

	while (1) {
		if (status == 0) {
			HAL_GPIO_WritePin(GPIOF, GPIO_PIN_8, SET);
			HAL_GPIO_WritePin(GPIOF, GPIO_PIN_10, RESET);
			HAL_GPIO_WritePin(GPIOF, GPIO_PIN_9, RESET);
		}
		time1_value = __HAL_TIM_GET_COUNTER(&base_timer1);
		if (time1_value == 0) {
			start = 1;
		} else {
			start = 0;
		}
		if (status == 1 && start == 1) {
			/* starting the timer */
				HAL_TIM_Base_Start(&base_timer2);
				HAL_TIM_Base_Start(&base_timer3);

			while (time1_value != base_timer1.Init.Period) {
				time1_value = __HAL_TIM_GET_COUNTER(&base_timer1);
				time2_value = __HAL_TIM_GET_COUNTER(&base_timer2);
				time3_value = __HAL_TIM_GET_COUNTER(&base_timer3);
				if (time1_value == 0) {
					HAL_GPIO_WritePin(GPIOF, GPIO_PIN_10, RESET);
				} else if (time1_value == 12000) {
					HAL_GPIO_WritePin(GPIOF, GPIO_PIN_10, SET);
				}
				if (time2_value == 0) {
					HAL_GPIO_WritePin(GPIOF, GPIO_PIN_9, RESET);
				} else if (time2_value == 6000) {
					HAL_GPIO_WritePin(GPIOF, GPIO_PIN_9, SET);
				}
				if (time3_value == 0) {
					HAL_GPIO_WritePin(GPIOF, GPIO_PIN_8, SET);
				} else if (time3_value == 6000) {
					HAL_GPIO_WritePin(GPIOF, GPIO_PIN_8, RESET);
				}
			}
			status = 0;
		}
	}
}

void led_init()
{
	__HAL_RCC_GPIOF_CLK_ENABLE()
	;

	GPIO_InitTypeDef gpio_led;

	gpio_led.Pin = GPIO_PIN_10 | GPIO_PIN_9 | GPIO_PIN_8;
	gpio_led.Mode = GPIO_MODE_OUTPUT_PP;
	gpio_led.Pull = GPIO_NOPULL;
	gpio_led.Speed = GPIO_SPEED_FREQ_HIGH;

	HAL_GPIO_Init(GPIOF, &gpio_led);
}

void init_button_IT()
{
	__HAL_RCC_GPIOG_CLK_ENABLE()
	;

	GPIO_InitTypeDef button_config;

	button_config.Pin = GPIO_PIN_7;
	button_config.Mode = GPIO_MODE_IT_RISING;
	button_config.Pull = GPIO_NOPULL;
	button_config.Speed = GPIO_SPEED_FREQ_HIGH;

	HAL_GPIO_Init(GPIOG, &button_config);

}

void timer_init1()
{
	__HAL_RCC_TIM2_CLK_ENABLE()
	;

	base_timer1.Instance = TIM2;
	base_timer1.Init.Prescaler = 54000 - 1;
	base_timer1.Init.Period = 24000 - 1;
	base_timer1.Init.CounterMode = TIM_COUNTERMODE_UP;
	base_timer1.Init.ClockDivision = TIM_CLOCKDIVISION_DIV1;

	HAL_TIM_Base_Init(&base_timer1);

	HAL_NVIC_SetPriority(EXTI9_5_IRQn, 2, 0);

	HAL_NVIC_EnableIRQ(EXTI9_5_IRQn);

}

void timer_init2()
{
	__HAL_RCC_TIM3_CLK_ENABLE()
	;

	base_timer2.Instance = TIM3;
	base_timer2.Init.Prescaler = 54000 - 1;
	base_timer2.Init.Period = 12000 - 1;
	base_timer2.Init.CounterMode = TIM_COUNTERMODE_UP;
	base_timer2.Init.ClockDivision = TIM_CLOCKDIVISION_DIV1;

	HAL_TIM_Base_Init(&base_timer2);
}

void timer_init3()
{
	__HAL_RCC_TIM4_CLK_ENABLE()
	;

	base_timer3.Instance = TIM4;
	base_timer3.Init.Prescaler = 54000 - 1;
	base_timer3.Init.Period = 24000 - 1;
	base_timer3.Init.CounterMode = TIM_COUNTERMODE_UP;
	base_timer3.Init.ClockDivision = TIM_CLOCKDIVISION_DIV1;

	HAL_TIM_Base_Init(&base_timer3);
}

void EXTI9_5_IRQHandler()
{
	HAL_GPIO_EXTI_IRQHandler(GPIO_PIN_7);
}

void HAL_GPIO_EXTI_Callback(uint16_t GPIO_Pin)
{
	if (status != 1) {
		status = 1;
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
