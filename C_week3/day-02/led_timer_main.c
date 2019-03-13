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

GPIO_InitTypeDef PA15_LED_config;

typedef enum{
	SET_LED,
	RESET_LED
}timer_interrupt_t;

timer_interrupt_t led = RESET_LED;

void pa15_led_init();
void tim2_init();

static void Error_Handler(void);
static void SystemClock_Config(void);

int main(void) {
	HAL_Init();
	SystemClock_Config();

	__HAL_RCC_GPIOA_CLK_ENABLE()
	;
	__HAL_RCC_TIM2_CLK_ENABLE()
	;

	tim2_init();
	pa15_led_init();

	HAL_TIM_Base_Start_IT(&tim2_handle);

	while (1) {

	}
}


void pa15_led_init() {
	PA15_LED_config.Pin = GPIO_PIN_15;
	PA15_LED_config.Mode = GPIO_MODE_OUTPUT_PP; /* configure as output, in push-pull mode */
	PA15_LED_config.Pull = GPIO_NOPULL;
	PA15_LED_config.Speed = GPIO_SPEED_HIGH;
//PA15_LED_config.Alternate = GPIO_AF1_TIM2; /* this alternate function we need to use TIM2 in output compare mode */
	HAL_GPIO_Init(GPIOA, &PA15_LED_config);
}

void tim2_init() {
	tim2_handle.Instance = TIM2;
	tim2_handle.Init.Prescaler = 10800 - 1; /* 108000000/10800=10000 -> speed of 1 count-up: 1/10000 sec = 0.1 ms */
	tim2_handle.Init.Period = 10000/2 - 1; /* 10000 x 0.1 ms = 1 second period */
	tim2_handle.Init.ClockDivision = TIM_CLOCKDIVISION_DIV1;
	tim2_handle.Init.CounterMode = TIM_COUNTERMODE_UP;

	/* configure the timer */
	HAL_TIM_Base_Init(&tim2_handle);

	HAL_NVIC_SetPriority(TIM2_IRQn, 1, 1);
	HAL_NVIC_EnableIRQ(TIM2_IRQn);
}

void TIM2_IRQHandler() {
	HAL_TIM_IRQHandler(&tim2_handle);
}

void HAL_TIM_PeriodElapsedCallback(TIM_HandleTypeDef *htim) {
	if(led == RESET_LED){
		led = SET_LED;
		HAL_GPIO_WritePin(GPIOA, GPIO_PIN_15, GPIO_PIN_SET);
	}else if(led == SET_LED){
		led = RESET_LED;
		HAL_GPIO_WritePin(GPIOA, GPIO_PIN_15, GPIO_PIN_RESET);
	}
}

static void Error_Handler(void) {
}

static void SystemClock_Config(void) {
	RCC_OscInitTypeDef RCC_OscInitStruct = { 0 };
	RCC_ClkInitTypeDef RCC_ClkInitStruct = { 0 };

	/**Configure the main internal regulator output voltage */
	__HAL_RCC_PWR_CLK_ENABLE()
	;
	__HAL_PWR_VOLTAGESCALING_CONFIG(PWR_REGULATOR_VOLTAGE_SCALE1);

	/**Initializes the CPU, AHB and APB busses clocks */
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

	/**Activate the Over-Drive mode */
	if (HAL_PWREx_EnableOverDrive() != HAL_OK) {
		Error_Handler();
	}

	/**Initializes the CPU, AHB and APB busses clocks */
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
