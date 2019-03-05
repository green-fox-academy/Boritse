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
	BSP_PB_Init(BUTTON_KEY, BUTTON_MODE_GPIO);
	BSP_LED_Init(LED1);
	HAL_Init();
	int counter=0;
while(1){
	    if(BSP_PB_GetState(BUTTON_KEY)){
	    	counter++;
	    	if(counter<5){
	    		HAL_Delay(500);
	    	}else{
	    		BSP_LED_On(LED1);
	    	}
	    }
	}
}
