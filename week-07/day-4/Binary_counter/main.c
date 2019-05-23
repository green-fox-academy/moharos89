/**
 ******************************************************************************
 * @file    main.c
 * @author  Ac6
 * @version V1.0
 * @date    01-December-2013
 * @brief   Default main function.
 ******************************************************************************
 */
#include "stm32f7xx_hal.h"
#include "stm32f7xx.h"
#include "stm32746g_discovery.h"
#include <stdint.h>


void init_led1();
void init_led2();
void init_led3();
void init_led4();
void init_it_button();
void init_it_button_starter();
void EXTI4_IRQHandler();
void HAL_GPIO_EXTI_Callback(uint16_t GPIO_Pin);

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
	init_it_button();
	init_it_button_starter();
	counter_t leap;
	leap.counter = 0;

	while (1) {
		GPIOF->BSRR |= (leap.counter << 7);
		HAL_Delay(1000);
		GPIOF->BSRR |= (leap.counter << 23);
		leap.counter++;
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

void init_it_button()
{
	__HAL_RCC_GPIOB_CLK_ENABLE()
	;

	GPIO_InitTypeDef gpio_config;

	gpio_config.Pin = GPIO_PIN_4;
	gpio_config.Mode = GPIO_MODE_IT_FALLING;
	gpio_config.Pull = GPIO_NOPULL;
	gpio_config.Speed = GPIO_SPEED_FREQ_HIGH;

	HAL_GPIO_Init(GPIOB, &gpio_config);

	HAL_NVIC_EnableIRQ(EXTI4_IRQn);

	HAL_NVIC_SetPriority(EXTI4_IRQn, 10, 0);
}

void init_it_button_starter()
{
	__HAL_RCC_GPIOI_CLK_ENABLE();

	GPIO_InitTypeDef gpio_config;

	gpio_config.Pin = GPIO_PIN_11;
	gpio_config.Mode = GPIO_MODE_IT_FALLING;
	gpio_config.Pull = GPIO_NOPULL;
	gpio_config.Speed = GPIO_SPEED_FREQ_HIGH;

	HAL_GPIO_Init(GPIOI, &gpio_config);

	HAL_NVIC_EnableIRQ(EXTI15_10_IRQn);

	HAL_NVIC_SetPriority(EXTI15_10_IRQn, 9, 0);
}

void EXTI4_IRQHandler()
{
	HAL_GPIO_EXTI_IRQHandler(GPIO_PIN_4);
}

void EXTI15_10_IRQHandler()
{
	HAL_GPIO_EXTI_IRQHandler(GPIO_PIN_11);
}

void HAL_GPIO_EXTI_Callback(uint16_t GPIO_Pin)
{
	if (GPIO_Pin == GPIO_PIN_4) {
		while (status == 0) {
			HAL_GPIO_WritePin(GPIOF, GPIO_PIN_10, GPIO_PIN_RESET);
			HAL_GPIO_WritePin(GPIOF, GPIO_PIN_9, GPIO_PIN_RESET);
			HAL_GPIO_WritePin(GPIOF, GPIO_PIN_8, GPIO_PIN_RESET);
			HAL_GPIO_WritePin(GPIOF, GPIO_PIN_7, GPIO_PIN_RESET);
		}
		status = 0;
	}
	if (GPIO_Pin == GPIO_PIN_11) {
		status = 1;
	}
}
