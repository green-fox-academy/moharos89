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
#include <stdint.h>

void init_led1();
void init_led2();
void init_led3();
void init_led4();

int main(void)
{
	HAL_Init();

	init_led1();
	init_led2();

	while (1) {
		HAL_GPIO_WritePin(GPIOF , GPIO_PIN_10 , GPIO_PIN_SET);
		HAL_GPIO_WritePin(GPIOF , GPIO_PIN_9 , GPIO_PIN_RESET);
		HAL_Delay(500);
		HAL_GPIO_WritePin(GPIOF , GPIO_PIN_10 , GPIO_PIN_RESET);
		HAL_GPIO_WritePin(GPIOF , GPIO_PIN_9 , GPIO_PIN_SET);
		HAL_Delay(500);
	}
}

void init_led1()
{
	__HAL_RCC_GPIOF_CLK_ENABLE();

	GPIO_InitTypeDef gpio_config;

	gpio_config.Pin = GPIO_PIN_10;
	gpio_config.Mode = GPIO_MODE_OUTPUT_PP;
	gpio_config.Pull = GPIO_NOPULL;
	gpio_config.Speed = GPIO_SPEED_FREQ_HIGH;

	HAL_GPIO_Init(GPIOF , &gpio_config);

}

void init_led2()
{
	__HAL_RCC_GPIOF_CLK_ENABLE();

	GPIO_InitTypeDef gpio_config;

	gpio_config.Pin = GPIO_PIN_9;
	gpio_config.Mode = GPIO_MODE_OUTPUT_PP;
	gpio_config.Pull = GPIO_NOPULL;
	gpio_config.Speed = GPIO_SPEED_FREQ_HIGH;

	HAL_GPIO_Init(GPIOF , &gpio_config);
}
