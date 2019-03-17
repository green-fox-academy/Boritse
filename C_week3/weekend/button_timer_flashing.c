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

TIM_HandleTypeDef tim2_handle;
GPIO_InitTypeDef extern_button;
GPIO_InitTypeDef PA15_LED_config;

volatile int pushed_bool = 0;

typedef enum{
	LED_ON,
	LED_OFF
}led_state_t;

led_state_t led_state = LED_OFF;

typedef enum{
	PUSHED,
	RELEASED
}button_state_t;

button_state_t button_state = RELEASED;

void tim2_init();
void pa15_led_init();
void extern_button_init();
static void Error_Handler(void);
static void SystemClock_Config(void);

int main(void)
{
	HAL_Init();

	SystemClock_Config();

	__HAL_RCC_GPIOA_CLK_ENABLE();
	__HAL_RCC_GPIOF_CLK_ENABLE();
	__HAL_RCC_TIM2_CLK_ENABLE();

	pa15_led_init();
	tim2_init();

	HAL_TIM_Base_Start_IT(&tim2_handle);

	extern_button_init();

	while(1){
		/*if (BSP_PB_GetState(BUTTON_KEY)) {
		   toggle_time = HAL_GetTick();
		   if(toggle_time % 500 == 250){
			  HAL_GPIO_WritePin(GPIOA, GPIO_PIN_15, GPIO_PIN_SET);
		   }else if(toggle_time % 500 == 0){
				  HAL_GPIO_WritePin(GPIOA, GPIO_PIN_15, GPIO_PIN_RESET);
		   }
		}*/
	}

}

void pa15_led_init() {
	PA15_LED_config.Pin = GPIO_PIN_15;
	PA15_LED_config.Mode = GPIO_MODE_OUTPUT_PP; /* configure as output, in push-pull mode */
	PA15_LED_config.Pull = GPIO_NOPULL;
	PA15_LED_config.Speed = GPIO_SPEED_HIGH;

	HAL_GPIO_Init(GPIOA, &PA15_LED_config);
}

void tim2_init()
{
	tim2_handle.Instance = TIM2;
	tim2_handle.Init.Prescaler = 10800 - 1;
	tim2_handle.Init.Period = 10000/4 - 1;
	tim2_handle.Init.ClockDivision = TIM_CLOCKDIVISION_DIV1;
	tim2_handle.Init.CounterMode = TIM_COUNTERMODE_UP;

	HAL_TIM_Base_Init(&tim2_handle);

	HAL_NVIC_SetPriority(TIM2_IRQn, 1, 2);
	HAL_NVIC_EnableIRQ(TIM2_IRQn);
}

void TIM2_IRQHandler()
{
	HAL_TIM_IRQHandler(&tim2_handle);
}

void HAL_TIM_PeriodElapsedCallback(TIM_HandleTypeDef *htim)
{
	if(pushed_bool){
		if(led_state == LED_OFF){
			led_state = LED_ON;
			HAL_GPIO_WritePin(GPIOA, GPIO_PIN_15, GPIO_PIN_SET);
		}else{
			led_state = LED_OFF;
			HAL_GPIO_WritePin(GPIOA, GPIO_PIN_15, GPIO_PIN_RESET);
		}
	}
}

void extern_button_init()
{
	extern_button.Pin = GPIO_PIN_10;
	extern_button.Mode = GPIO_MODE_IT_RISING_FALLING;
	extern_button.Pull = GPIO_NOPULL;
	extern_button.Speed = GPIO_SPEED_HIGH;

	HAL_GPIO_Init(GPIOF, &extern_button);

	HAL_NVIC_SetPriority(EXTI15_10_IRQn, 2, 1);
	HAL_NVIC_EnableIRQ(EXTI15_10_IRQn);
}

void EXTI15_10_IRQHandler()
{
	HAL_GPIO_EXTI_IRQHandler(extern_button.Pin);
}

void HAL_GPIO_EXTI_Callback(uint16_t GPIO_Pin)
{
	if(button_state == RELEASED){
		button_state = PUSHED;
		pushed_bool = 1;
	}else{
		button_state = RELEASED;
		pushed_bool = 0;
	}
}

static void Error_Handler(void) {
}

static void SystemClock_Config(void) {
	RCC_OscInitTypeDef RCC_OscInitStruct = { 0 };
	RCC_ClkInitTypeDef RCC_ClkInitStruct = { 0 };

	__HAL_RCC_PWR_CLK_ENABLE()
	;
	__HAL_PWR_VOLTAGESCALING_CONFIG(PWR_REGULATOR_VOLTAGE_SCALE1);

	RCC_OscInitStruct.OscillatorType = RCC_OSCILLATORTYPE_HSI;
	RCC_OscInitStruct.HSIState = RCC_HSI_ON;
	RCC_OscInitStruct.HSICalibrationValue = RCC_HSICALIBRATION_DEFAULT;
	RCC_OscInitStruct.PLL.PLLState = RCC_PLL_ON;
	RCC_OscInitStruct.PLL.PLLSource = RCC_PLLSOURCE_HSI;
	RCC_OscInitStruct.PLL.PLLM = 8;
	RCC_OscInitStruct.PLL.PLLN = 216;
	RCC_OscInitStruct.PLL.PLLP = RCC_PLLP_DIV2;
	RCC_OscInitStruct.PLL.PLLQ = 2;

	if (HAL_RCC_OscConfig(&RCC_OscInitStruct) != HAL_OK) {
		Error_Handler();
	}

	if (HAL_PWREx_EnableOverDrive() != HAL_OK) {
		Error_Handler();
	}

	RCC_ClkInitStruct.ClockType = RCC_CLOCKTYPE_HCLK | RCC_CLOCKTYPE_SYSCLK
			| RCC_CLOCKTYPE_PCLK1 | RCC_CLOCKTYPE_PCLK2;
	RCC_ClkInitStruct.SYSCLKSource = RCC_SYSCLKSOURCE_PLLCLK;
	RCC_ClkInitStruct.AHBCLKDivider = RCC_SYSCLK_DIV1;
	RCC_ClkInitStruct.APB1CLKDivider = RCC_HCLK_DIV4;
	RCC_ClkInitStruct.APB2CLKDivider = RCC_HCLK_DIV2;

	if (HAL_RCC_ClockConfig(&RCC_ClkInitStruct, FLASH_LATENCY_7) != HAL_OK) {
		Error_Handler();
	}
}
