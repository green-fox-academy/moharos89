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

void init();

int main(void)
{
	HAL_Init();

	init();

	int red_led = (1 << 7);
	while (1) {
		for (int i = 0; i < 4; i++) {
			GPIOF->BSRR = red_led << i;
			for (int i = 0; i < 150000; i++) {

			}
			GPIOF->BSRR = red_led << (16 + i);
			for (int i = 0; i < 150000; i++) {

			}
		}
	}
}

void init()
{
	/* GPIOA Periph clock enable */
	RCC->AHB1ENR |= RCC_AHB1ENR_GPIOFEN;

	/* configure PF7 in output mode */
	GPIOF->MODER |= (GPIO_MODER_MODER7_0);
	/* ensure push pull mode selected default */
	GPIOF->OTYPER &= ~(GPIO_OTYPER_OT_7);
	/* ensure maximum speed setting (even though it is unnecessary) */
	GPIOF->OSPEEDR |= (GPIO_OSPEEDER_OSPEEDR7);
	/* ensure all pull up pull down resistors are disabled */
	GPIOF->PUPDR &= ~(GPIO_PUPDR_PUPDR7);

	/* configure PF8 in output mode */
	GPIOF->MODER |= (GPIO_MODER_MODER8_0);
	/* ensure push pull mode selected default */
	GPIOF->OTYPER &= ~(GPIO_OTYPER_OT_8);
	/* ensure maximum speed setting (even though it is unnecessary) */
	GPIOF->OSPEEDR |= (GPIO_OSPEEDER_OSPEEDR8);
	/* ensure all pull up pull down resistors are disabled */
	GPIOF->PUPDR &= ~(GPIO_PUPDR_PUPDR8);

	/* configure PF9 in output mode */
	GPIOF->MODER |= (GPIO_MODER_MODER9_0);
	/* ensure push pull mode selected default */
	GPIOF->OTYPER &= ~(GPIO_OTYPER_OT_9);
	/* ensure maximum speed setting (even though it is unnecessary) */
	GPIOF->OSPEEDR |= (GPIO_OSPEEDER_OSPEEDR9);
	/* ensure all pull up pull down resistors are disabled */
	GPIOF->PUPDR &= ~(GPIO_PUPDR_PUPDR9);

	/* configure PF10 in output mode */
	GPIOF->MODER |= (GPIO_MODER_MODER10_0);
	/* ensure push pull mode selected default */
	GPIOF->OTYPER &= ~(GPIO_OTYPER_OT_10);
	/* ensure maximum speed setting (even though it is unnecessary) */
	GPIOF->OSPEEDR |= (GPIO_OSPEEDER_OSPEEDR10);
	/* ensure all pull up pull down resistors are disabled */
	GPIOF->PUPDR &= ~(GPIO_PUPDR_PUPDR10);

}
