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
void timer_init();
void base_timer_init();
void pwm_init();

TIM_HandleTypeDef pwm_timer;

TIM_HandleTypeDef base_timer;

TIM_OC_InitTypeDef pwm_config;

int main(void)
{
	HAL_Init();
	SystemClock_Config();

	led_init();
	timer_init();
	pwm_init();
	base_timer_init();

	/* starting the timer */
	HAL_TIM_PWM_Start(&pwm_timer, TIM_CHANNEL_1);
	HAL_TIM_Base_Start(&base_timer);
	uint16_t timer_value;
	int signal = 0;
	uint16_t counter = 1;

	while (1) {
		timer_value = __HAL_TIM_GET_COUNTER(&base_timer);
		if (timer_value == 0) {
			if (signal == 0) {
				counter += 1;
			} else {
				counter -= 1;
			}
		}
		if (counter == 99) {
			signal = 1;
		}
		if (counter == 1) {
			signal = 0;
		}
		__HAL_TIM_SET_COMPARE(&pwm_timer, TIM_CHANNEL_1, counter);
	}
	return 0;
}

void led_init()
{
	__HAL_RCC_GPIOA_CLK_ENABLE()
	;

	GPIO_InitTypeDef gpio_led;

	gpio_led.Pin = GPIO_PIN_15;
	gpio_led.Mode = GPIO_MODE_AF_PP;
	gpio_led.Pull = GPIO_NOPULL;
	gpio_led.Speed = GPIO_SPEED_FREQ_HIGH;
	gpio_led.Alternate = GPIO_AF1_TIM2;

	HAL_GPIO_Init(GPIOA, &gpio_led);
}

void base_timer_init()
{
	__HAL_RCC_TIM3_CLK_ENABLE()
	;

	base_timer.Instance = TIM3;
	base_timer.Init.Prescaler = 54000 - 1;
	base_timer.Init.Period = 200 - 1;
	base_timer.Init.CounterMode = TIM_COUNTERMODE_UP;
	base_timer.Init.ClockDivision = TIM_CLOCKDIVISION_DIV1;

	HAL_TIM_Base_Init(&base_timer);
}

void timer_init()
{
	__HAL_RCC_TIM2_CLK_ENABLE()
	;

	pwm_timer.Instance = TIM2;
	pwm_timer.Init.Prescaler = 108 - 1;
	pwm_timer.Init.Period = 100 - 1;
	pwm_timer.Init.CounterMode = TIM_COUNTERMODE_UP;
	pwm_timer.Init.ClockDivision = TIM_CLOCKDIVISION_DIV1;

	HAL_TIM_PWM_Init(&pwm_timer);
}

void pwm_init()
{
	pwm_config.Pulse = 0;
	pwm_config.OCMode = TIM_OCMODE_PWM1;
	pwm_config.OCNPolarity = TIM_OCPOLARITY_HIGH;
	pwm_config.OCFastMode = TIM_OCFAST_ENABLE;

	HAL_TIM_PWM_ConfigChannel(&pwm_timer, &pwm_config, TIM_CHANNEL_1);
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
