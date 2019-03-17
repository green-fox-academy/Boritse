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
//GPIO_InitTypeDef extern_button;
GPIO_InitTypeDef PA15_LED_config;
GPIO_InitTypeDef led2_config;
GPIO_InitTypeDef led3_config;
GPIO_InitTypeDef led4_config;

volatile int counter = 1;
volatile int round_counter = 1;

void tim2_init();
void led_init();
//void extern_button_init();
static void Error_Handler(void);
static void SystemClock_Config(void);

int main(void) {
	HAL_Init();

	SystemClock_Config();

	__HAL_RCC_GPIOA_CLK_ENABLE()
	;
	__HAL_RCC_GPIOF_CLK_ENABLE()
	;
	__HAL_RCC_TIM2_CLK_ENABLE()
	;

	led_init();
	tim2_init();

	HAL_TIM_Base_Start_IT(&tim2_handle);

	//extern_button_init();

	while (1) {

	}

}

void led_init() {
	PA15_LED_config.Pin = GPIO_PIN_15;
	PA15_LED_config.Mode = GPIO_MODE_OUTPUT_PP; /* configure as output, in push-pull mode */
	PA15_LED_config.Pull = GPIO_NOPULL;
	PA15_LED_config.Speed = GPIO_SPEED_HIGH;

	HAL_GPIO_Init(GPIOA, &PA15_LED_config);

	led2_config.Pin = GPIO_PIN_9;
	led2_config.Mode = GPIO_MODE_OUTPUT_PP; /* configure as output, in push-pull mode */
	led2_config.Pull = GPIO_NOPULL;
	led2_config.Speed = GPIO_SPEED_HIGH;

	HAL_GPIO_Init(GPIOF, &led2_config);

	led3_config.Pin = GPIO_PIN_8;
	led3_config.Mode = GPIO_MODE_OUTPUT_PP; /* configure as output, in push-pull mode */
	led3_config.Pull = GPIO_NOPULL;
	led3_config.Speed = GPIO_SPEED_HIGH;

	HAL_GPIO_Init(GPIOF, &led3_config);

	led4_config.Pin = GPIO_PIN_6;
	led4_config.Mode = GPIO_MODE_OUTPUT_PP; /* configure as output, in push-pull mode */
	led4_config.Pull = GPIO_NOPULL;
	led4_config.Speed = GPIO_SPEED_HIGH;

	HAL_GPIO_Init(GPIOF, &led4_config);
}

void tim2_init() {
	tim2_handle.Instance = TIM2;
	tim2_handle.Init.Prescaler = 10800 - 1;
	tim2_handle.Init.Period = 10000 / 12 - 1;
	tim2_handle.Init.ClockDivision = TIM_CLOCKDIVISION_DIV1;
	tim2_handle.Init.CounterMode = TIM_COUNTERMODE_UP;

	HAL_TIM_Base_Init(&tim2_handle);

	HAL_NVIC_SetPriority(TIM2_IRQn, 1, 2);
	HAL_NVIC_EnableIRQ(TIM2_IRQn);
}

void TIM2_IRQHandler() {
	HAL_TIM_IRQHandler(&tim2_handle);
}

void HAL_TIM_PeriodElapsedCallback(TIM_HandleTypeDef *htim) {

	HAL_GPIO_WritePin(GPIOF, GPIO_PIN_6, GPIO_PIN_RESET);
	HAL_GPIO_WritePin(GPIOF, GPIO_PIN_8, GPIO_PIN_RESET);
	HAL_GPIO_WritePin(GPIOF, GPIO_PIN_9, GPIO_PIN_RESET);
	HAL_GPIO_WritePin(GPIOA, GPIO_PIN_15, GPIO_PIN_RESET);

		if (((counter & 1) && (round_counter % 8 == 1)) || ((counter & 1 << 7) && (round_counter % 8 == 0))) {
			HAL_GPIO_WritePin(GPIOF, GPIO_PIN_6, GPIO_PIN_SET);
		}
		if (((counter & 1 << 1) && (round_counter % 8 == 2)) || ((counter & 1 << 6) && (round_counter % 8 == 7))) {
			HAL_GPIO_WritePin(GPIOF, GPIO_PIN_8, GPIO_PIN_SET);
		}
		if (((counter & 1 << 2) && (round_counter % 8 == 3)) || ((counter & 1 << 5) && (round_counter % 8 == 6))) {
			HAL_GPIO_WritePin(GPIOF, GPIO_PIN_9, GPIO_PIN_SET);
		}
		if (((counter & 1 << 3) && (round_counter % 8 == 4)) || ((counter & 1 << 4) && (round_counter % 8 == 5))) {
			HAL_GPIO_WritePin(GPIOA, GPIO_PIN_15, GPIO_PIN_SET);
		}
		if(counter < 128){
		counter *= 2;
		}else{
			counter = 1;
		}
		round_counter++;
}
/*
 void extern_button_init() {
 extern_button.Pin = GPIO_PIN_10;
 extern_button.Mode = GPIO_MODE_IT_RISING;
 extern_button.Pull = GPIO_NOPULL;
 extern_button.Speed = GPIO_SPEED_HIGH;

 HAL_GPIO_Init(GPIOF, &extern_button);

 HAL_NVIC_SetPriority(EXTI15_10_IRQn, 2, 1);
 HAL_NVIC_EnableIRQ(EXTI15_10_IRQn);
 }

 void EXTI15_10_IRQHandler() {
 HAL_GPIO_EXTI_IRQHandler(extern_button.Pin);
 }

 void HAL_GPIO_EXTI_Callback(uint16_t GPIO_Pin) {

 }
 */

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

