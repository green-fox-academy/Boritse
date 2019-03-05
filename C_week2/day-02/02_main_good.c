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
	int bool=1;
while(1){
	    if(BSP_PB_GetState(BUTTON_KEY)){
	    	if(bool){
	    		BSP_LED_On(LED1);
	    		HAL_Delay(500);
	    		bool=0;
	    	}else if(!bool){
	    		BSP_LED_Off(LED1);
	    		HAL_Delay(500);
	    		bool=1;
	    	}
	    }
	}
}
