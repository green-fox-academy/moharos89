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
void init_button();

typedef struct {
	unsigned int counter :4;
} counter_t;

volatile int status = 0;

int main(void)
{
	HAL_Init();

	init_led1();
	init_led2();
	init_led3();
	init_led4();
	init_button();
	counter_t leap;
	leap.counter = 0;

	while (1) {
		if (HAL_GPIO_ReadPin(GPIOB, GPIO_PIN_4) == 1) {
			HAL_Delay(250);
			if (HAL_GPIO_ReadPin(GPIOB, GPIO_PIN_4) == 0) {
				status = 1;
			}
		}

		GPIOF->BSRR |= (leap.counter << 7);
		if (status == 1) {
			GPIOF->BSRR |= (leap.counter << 23);
			leap.counter++;
		}
		status = 0;
	}
}

void init_led1()
{
	__HAL_RCC_GPIOF_CLK_ENABLE()
	;

	GPIO_InitTypeDef gpio_config;

	gpio_config.Pin = GPIO_PIN_10;
	gpio_config.Mode = GPIO_MODE_OUTPUT_PP;
	gpio_config.Pull = GPIO_NOPULL;
	gpio_config.Speed = GPIO_SPEED_FREQ_HIGH;

	HAL_GPIO_Init(GPIOF, &gpio_config);

}

void init_led2()
{
	__HAL_RCC_GPIOF_CLK_ENABLE()
	;

	GPIO_InitTypeDef gpio_config;

	gpio_config.Pin = GPIO_PIN_9;
	gpio_config.Mode = GPIO_MODE_OUTPUT_PP;
	gpio_config.Pull = GPIO_NOPULL;
	gpio_config.Speed = GPIO_SPEED_FREQ_HIGH;

	HAL_GPIO_Init(GPIOF, &gpio_config);
}

void init_led3()
{
	__HAL_RCC_GPIOF_CLK_ENABLE()
	;

	GPIO_InitTypeDef gpio_config;

	gpio_config.Pin = GPIO_PIN_8;
	gpio_config.Mode = GPIO_MODE_OUTPUT_PP;
	gpio_config.Pull = GPIO_NOPULL;
	gpio_config.Speed = GPIO_SPEED_FREQ_HIGH;

	HAL_GPIO_Init(GPIOF, &gpio_config);
}

void init_led4()
{
	__HAL_RCC_GPIOF_CLK_ENABLE()
	;

	GPIO_InitTypeDef gpio_config;

	gpio_config.Pin = GPIO_PIN_7;
	gpio_config.Mode = GPIO_MODE_OUTPUT_PP;
	gpio_config.Pull = GPIO_NOPULL;
	gpio_config.Speed = GPIO_SPEED_FREQ_HIGH;

	HAL_GPIO_Init(GPIOF, &gpio_config);
}

void init_button()
{
	__HAL_RCC_GPIOB_CLK_ENABLE()
	;

	GPIO_InitTypeDef gpio_config;

	gpio_config.Pin = GPIO_PIN_4;
	gpio_config.Mode = GPIO_MODE_INPUT;
	gpio_config.Pull = GPIO_NOPULL;
	gpio_config.Speed = GPIO_SPEED_FREQ_HIGH;

	HAL_GPIO_Init(GPIOB, &gpio_config);
}
