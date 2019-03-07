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

/* create a config structure */
GPIO_InitTypeDef semafor;

void one(){
	HAL_GPIO_WritePin(GPIOF, GPIO_PIN_7, GPIO_PIN_SET);
	HAL_Delay(250);
	HAL_GPIO_WritePin(GPIOF, GPIO_PIN_7, GPIO_PIN_RESET);
}

void three(){
	HAL_GPIO_WritePin(GPIOF, GPIO_PIN_8, GPIO_PIN_SET);
	HAL_Delay(500);
	one();
	HAL_GPIO_WritePin(GPIOF, GPIO_PIN_8, GPIO_PIN_RESET);
}

void seven(){
	HAL_GPIO_WritePin(GPIOF, GPIO_PIN_9, GPIO_PIN_SET);
	HAL_Delay(500);
	three();
	HAL_GPIO_WritePin(GPIOF, GPIO_PIN_9, GPIO_PIN_RESET);
}

void fifteen(){
	HAL_GPIO_WritePin(GPIOF, GPIO_PIN_10, GPIO_PIN_SET);
	HAL_Delay(750);
	seven();
	HAL_GPIO_WritePin(GPIOF, GPIO_PIN_10, GPIO_PIN_RESET);
}

int main(void)
{
    HAL_Init();

    /* we need to enable the GPIOA port's clock first */
    __HAL_RCC_GPIOF_CLK_ENABLE();

    semafor.Pin = GPIO_PIN_9 | GPIO_PIN_10 | GPIO_PIN_8 | GPIO_PIN_7;		/* setting up 2 pins at once with | operator */
    semafor.Mode = GPIO_MODE_OUTPUT_PP;		/* configure as output, in push-pull mode */
    semafor.Pull = GPIO_NOPULL;			/* we don't need internal pull-up or -down resistor */
    semafor.Speed = GPIO_SPEED_HIGH;		/* we need a high-speed output */

    HAL_GPIO_Init(GPIOF, &semafor);		/* initialize the pin on GPIOF port */
    BSP_PB_Init(BUTTON_KEY, BUTTON_MODE_GPIO);

    while (1) {
    	if (BSP_PB_GetState(BUTTON_KEY))
    		fifteen();/* wait a second */
    }
}
