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

void init_time_PWM();
void init_time_it();
void init_PWM_LED();
void init_ADC();
void TIM3_IRQHandler();
void HAL_TIM_PeriodElapsedCallback(TIM_HandleTypeDef *htim);
void init_UART();
void set_brightness();
void set_blinking_frequency();
void init_user_botton_it();
void EXTI15_10_IRQHandler();
void HAL_GPIO_EXTI_Callback(uint16_t GPIO_Pin);

TIM_HandleTypeDef PWM_handle;
TIM_HandleTypeDef IT_time_handle;
TIM_OC_InitTypeDef PWM_config;
ADC_HandleTypeDef ADC_handle;
UART_HandleTypeDef UART_handle;

volatile int state = 0;
volatile int setting_state = 0;
volatile int bright_set_value;

int main(void)
{
	HAL_Init();
	SystemClock_Config();

	init_time_PWM();
	init_time_it();
	init_UART();
	init_PWM_LED();
	init_ADC();
	init_user_botton_it();

	HAL_ADC_Start(&ADC_handle);
	HAL_TIM_PWM_Start(&PWM_handle, TIM_CHANNEL_1);
	HAL_TIM_Base_Start_IT(&IT_time_handle);

	int ADC_value;

	while (1) {
		if (HAL_ADC_PollForConversion(&ADC_handle, 10) == HAL_OK) {
			char buffer[10];
			ADC_value = HAL_ADC_GetValue(&ADC_handle);
			sprintf(buffer, "%d\n", ADC_value);
			HAL_UART_Transmit(&UART_handle, (uint8_t *) buffer, strlen(buffer),
					100);

			//TIM3->ARR = frequency_value;
		}
		if (setting_state == 0) {
			set_brightness();
		} else {
			set_blinking_frequency();
		}
		if (state == 0) {
			__HAL_TIM_SET_COMPARE(&PWM_handle, TIM_CHANNEL_1, bright_set_value);
		}
		if (state == 1) {
			__HAL_TIM_SET_COMPARE(&PWM_handle, TIM_CHANNEL_1, 0);
		}

	}
}

void init_user_botton_it()
{
	__HAL_RCC_GPIOI_CLK_ENABLE();

	GPIO_InitTypeDef it_button_handle;
	it_button_handle.Pin = GPIO_PIN_11;
	it_button_handle.Mode = GPIO_MODE_IT_RISING;
	it_button_handle.Pull = GPIO_NOPULL;
	it_button_handle.Speed = GPIO_SPEED_FREQ_HIGH;

	HAL_GPIO_Init(GPIOI ,&it_button_handle);

	HAL_NVIC_SetPriority(EXTI15_10_IRQn , 2 , 0);

	HAL_NVIC_EnableIRQ(EXTI15_10_IRQn);

}

void EXTI15_10_IRQHandler()
{
	HAL_GPIO_EXTI_IRQHandler(GPIO_PIN_11);
}

void HAL_GPIO_EXTI_Callback(uint16_t GPIO_Pin)
{
	if(setting_state == 0) {
		setting_state = 1;
	} else {
		setting_state = 0;
	}
}

void set_blinking_frequency()
{
	uint16_t frequency_value;
	int ADC_value;
	char buffer[10];
	if (HAL_ADC_PollForConversion(&ADC_handle, 10) == HAL_OK) {
		ADC_value = HAL_ADC_GetValue(&ADC_handle);
		frequency_value = (float) ADC_value / (float) 255 * 3800 + 200;
		__HAL_TIM_SET_AUTORELOAD(&IT_time_handle, (uint16_t ) frequency_value);
		sprintf(buffer, "%d\n", frequency_value);
		HAL_UART_Transmit(&UART_handle, (uint8_t *) buffer, strlen(buffer),
				100);
	}
}

void set_brightness()
{
	int ADC_value;
		ADC_value = HAL_ADC_GetValue(&ADC_handle);
		bright_set_value = (float) ADC_value / (float) 255 * 100;
}

void init_time_it()
{
	__HAL_RCC_TIM3_CLK_ENABLE()
	;

	IT_time_handle.Instance = TIM3;
	IT_time_handle.Init.Prescaler = 54000 - 1;
	IT_time_handle.Init.Period = 2000 - 1;
	IT_time_handle.Init.ClockDivision = TIM_CLOCKDIVISION_DIV1;
	IT_time_handle.Init.CounterMode = TIM_COUNTERMODE_DOWN;

	HAL_TIM_Base_Init(&IT_time_handle);

	HAL_NVIC_SetPriority(TIM3_IRQn, 2, 2);

	HAL_NVIC_EnableIRQ(TIM3_IRQn);
}

void TIM3_IRQHandler()
{
	HAL_TIM_IRQHandler(&IT_time_handle);
}

void HAL_TIM_PeriodElapsedCallback(TIM_HandleTypeDef *htim)
{
	if (state == 1) {
		state = 0;
	} else {
		state = 1;
	}
}

void init_UART()
{
	__HAL_RCC_GPIOA_CLK_ENABLE()
	;
	__HAL_RCC_GPIOB_CLK_ENABLE()
	;

	GPIO_InitTypeDef UARTTx_pin_handle;

	UARTTx_pin_handle.Pin = GPIO_PIN_9;
	UARTTx_pin_handle.Mode = GPIO_MODE_AF_PP;
	UARTTx_pin_handle.Pull = GPIO_NOPULL;
	UARTTx_pin_handle.Speed = GPIO_SPEED_FREQ_HIGH;
	UARTTx_pin_handle.Alternate = GPIO_AF7_USART1;

	HAL_GPIO_Init(GPIOA, &UARTTx_pin_handle);

	GPIO_InitTypeDef UARTRx_pin_handle;

	UARTRx_pin_handle.Pin = GPIO_PIN_7;
	UARTRx_pin_handle.Mode = GPIO_MODE_AF_PP;
	UARTRx_pin_handle.Pull = GPIO_NOPULL;
	UARTRx_pin_handle.Speed = GPIO_SPEED_FREQ_HIGH;
	UARTRx_pin_handle.Alternate = GPIO_AF7_USART1;

	HAL_GPIO_Init(GPIOB, &UARTRx_pin_handle);

	__HAL_RCC_USART1_CLK_ENABLE()
	;

	UART_handle.Instance = USART1;
	UART_handle.Init.BaudRate = 115200;
	UART_handle.Init.WordLength = UART_WORDLENGTH_8B;
	UART_handle.Init.StopBits = UART_STOPBITS_1;
	UART_handle.Init.Parity = UART_PARITY_NONE;
	UART_handle.Init.HwFlowCtl = UART_HWCONTROL_NONE;
	UART_handle.Init.Mode = UART_MODE_TX_RX;

	HAL_UART_Init(&UART_handle);
}

void init_ADC()
{
	__HAL_RCC_GPIOA_CLK_ENABLE()
	;

	GPIO_InitTypeDef ADC_pin_handle;

	ADC_pin_handle.Pin = GPIO_PIN_0;
	ADC_pin_handle.Mode = GPIO_MODE_ANALOG;
	ADC_pin_handle.Pull = GPIO_NOPULL;
	ADC_pin_handle.Speed = GPIO_SPEED_FREQ_HIGH;

	HAL_GPIO_Init(GPIOA, &ADC_pin_handle);

	__HAL_RCC_ADC3_CLK_ENABLE()
	;

	ADC_handle.Instance = ADC3;
	ADC_handle.Init.ClockPrescaler = ADC_CLOCK_SYNC_PCLK_DIV2;
	ADC_handle.Init.Resolution = ADC_RESOLUTION_8B;
	ADC_handle.Init.DataAlign = ADC_DATAALIGN_RIGHT;

	ADC_handle.Init.ScanConvMode = DISABLE;
	ADC_handle.Init.ContinuousConvMode = ENABLE;
	ADC_handle.Init.DiscontinuousConvMode = DISABLE;
	ADC_handle.Init.EOCSelection = ADC_EOC_SEQ_CONV;
	ADC_handle.Init.NbrOfConversion = 1;

	HAL_ADC_Init(&ADC_handle);

	ADC_ChannelConfTypeDef ADC_config;
	ADC_config.Rank = 1;
	ADC_config.Channel = ADC_CHANNEL_0;
	ADC_config.SamplingTime = ADC_SAMPLETIME_56CYCLES;

	HAL_ADC_ConfigChannel(&ADC_handle, &ADC_config);
}

void init_time_PWM()
{
	__HAL_RCC_TIM2_CLK_ENABLE()
	;

	PWM_handle.Instance = TIM2;
	PWM_handle.Init.Prescaler = 108 - 1;
	PWM_handle.Init.Period = 100 - 1;
	PWM_handle.Init.ClockDivision = TIM_CLOCKDIVISION_DIV1;
	PWM_handle.Init.CounterMode = TIM_COUNTERMODE_UP;

	HAL_TIM_PWM_Init(&PWM_handle);

	PWM_config.Pulse = 50;
	PWM_config.OCMode = TIM_OCMODE_PWM1;
	PWM_config.OCPolarity = TIM_OCPOLARITY_HIGH;
	PWM_config.OCFastMode = TIM_OCFAST_ENABLE;

	HAL_TIM_PWM_ConfigChannel(&PWM_handle, &PWM_config, TIM_CHANNEL_1);
}

void init_PWM_LED()
{
	__HAL_RCC_GPIOA_CLK_ENABLE()
	;

	GPIO_InitTypeDef led_gpio_config;

	led_gpio_config.Pin = GPIO_PIN_15;
	led_gpio_config.Mode = GPIO_MODE_AF_PP;
	led_gpio_config.Pull = GPIO_NOPULL;
	led_gpio_config.Speed = GPIO_SPEED_FREQ_HIGH;
	led_gpio_config.Alternate = GPIO_AF1_TIM2;

	HAL_GPIO_Init(GPIOA, &led_gpio_config);
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
