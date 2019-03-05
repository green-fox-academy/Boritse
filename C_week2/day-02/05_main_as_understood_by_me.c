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
	int unit=2000;
	int divider=1;
	int bool=1;
while(bool){
	if(BSP_PB_GetState(BUTTON_KEY)){
		for (int j=0; j<3; j++){
			for (int i=0; i<4; i++){
				BSP_LED_On(LED1);
				HAL_Delay(unit/divider);
				BSP_LED_Off(LED1);
				HAL_Delay(unit/divider);
				divider*=2;
	    	}
			for (int i=0; i<4; i++){
				BSP_LED_On(LED1);
				HAL_Delay(unit/divider);
				BSP_LED_Off(LED1);
				HAL_Delay(unit/divider);
				divider/=2;
			}
	    }
		bool=0;
	}
	}
}
