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

void flasher(int _unit, int _divider){
	for (int i=0; i<3; i++){
		BSP_LED_On(LED1);
		HAL_Delay(_unit/_divider);
		BSP_LED_Off(LED1);
		HAL_Delay(_unit/_divider);
	}
}


int main(void)
{
	BSP_PB_Init(BUTTON_KEY, BUTTON_MODE_GPIO);
	BSP_LED_Init(LED1);
	HAL_Init();
	int unit=2000;
	int bool=1;
	while(bool){
		if(BSP_PB_GetState(BUTTON_KEY)){
			for (int j=0; j<4; j++){
				int divider = (1 << j);
				flasher(unit, divider);
			}
			for (int j=3; j>=0; j--){
				int divider = (1 << j);
				flasher(unit, divider);
			}
			bool=0;
		}
	}
}
