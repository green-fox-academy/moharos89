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

int main(void)
{
	HAL_Init();

	BSP_PB_Init(BUTTON_KEY, BUTTON_MODE_GPIO);

	BSP_LED_Init(LED1);

	int was_buttom_pushed = 0;

	int frequency = 1000;
	int halfPeriod = 0;

	while (1) {

		if (BSP_PB_GetState(BUTTON_KEY) == 1) {
			HAL_Delay(250);
			if (BSP_PB_GetState(BUTTON_KEY) == 0) {
				was_buttom_pushed = 1;
			}
		}
		if (was_buttom_pushed == 1) {
			for (int i = 0; i < 3; i++) {
				BSP_LED_On(LED1);
				HAL_Delay(frequency);
				BSP_LED_Off(LED1);
				HAL_Delay(frequency);
			}
			if (halfPeriod == 0) {
				frequency /= 2;
				if (frequency == 125) {
					halfPeriod = 1;
				}
			}
			if (halfPeriod == 1) {
				frequency *= 2;
				if (frequency == 1000) {
					halfPeriod = 0;
				}
			}
		}
	}
}
