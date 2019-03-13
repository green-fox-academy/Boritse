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
TIM_HandleTypeDef tim3_handle;
GPIO_InitTypeDef extern_button;
GPIO_InitTypeDef PA15_LED_config;
TIM_OC_InitTypeDef sConfig;

typedef enum {
	SET_LED, RESET_LED
} timer_interrupt_t;

timer_interrupt_t led = RESET_LED;

typedef enum {
	PUSHED, RELEASED
} button_status_t;

button_status_t button_status = RELEASED;
volatile uint8_t counter = 0;

void pa15_led_init();
void extern_button_init();
void tim_init();

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
	__HAL_RCC_TIM3_CLK_ENABLE()
	;

	tim_init();
	extern_button_init();
	pa15_led_init();

	BSP_LED_Init(LED_GREEN);

	HAL_TIM_PWM_Start(&tim2_handle, TIM_CHANNEL_1);
	__HAL_TIM_SET_COMPARE(&tim2_handle, TIM_CHANNEL_1, 100);
	HAL_TIM_Base_Start_IT(&tim3_handle);

	while (1) {

	}
}

void extern_button_init() {
	extern_button.Pin = GPIO_PIN_10; /* this is about PIN 10 */
	extern_button.Mode = GPIO_MODE_IT_RISING_FALLING; /* configure as input */
	/* we don't need internal pull-up or -down resistor, we use an external one */
	extern_button.Pull = GPIO_NOPULL;
	extern_button.Speed = GPIO_SPEED_HIGH; /* high-speed */

	HAL_GPIO_Init(GPIOF, &extern_button);

	HAL_NVIC_SetPriority(EXTI15_10_IRQn, 4, 1);
	HAL_NVIC_EnableIRQ(EXTI15_10_IRQn);
}

void pa15_led_init() {
	PA15_LED_config.Pin = GPIO_PIN_15;
	PA15_LED_config.Mode = GPIO_MODE_AF_PP; /* configure as output, in push-pull mode */
	PA15_LED_config.Pull = GPIO_NOPULL;
	PA15_LED_config.Speed = GPIO_SPEED_HIGH;
	PA15_LED_config.Alternate = GPIO_AF1_TIM2; /* this alternate function we need to use TIM2 in output compare mode */

	HAL_GPIO_Init(GPIOA, &PA15_LED_config);
}

void EXTI15_10_IRQHandler() {
	HAL_GPIO_EXTI_IRQHandler(extern_button.Pin);
}

void HAL_GPIO_EXTI_Callback(uint16_t GPIO_Pin) {
	if (button_status == RELEASED) {
		button_status = PUSHED;
		counter++;
	} else if (button_status == PUSHED) {
		button_status = RELEASED;
	}
}

void tim_init() {
	tim2_handle.Instance = TIM2;
	tim2_handle.Init.Prescaler = 108 - 1; /* 108000000/10800=10000 -> speed of 1 count-up: 1/10000 sec = 0.1 ms */
	tim2_handle.Init.Period = 100 - 1; /* 10000 x 0.1 ms = 1 second period */
	tim2_handle.Init.ClockDivision = TIM_CLOCKDIVISION_DIV1;
	tim2_handle.Init.CounterMode = TIM_COUNTERMODE_UP;

	HAL_TIM_PWM_Init(&tim2_handle);

	/* output compare config ***********************************************************************************************/
	sConfig.Pulse = 50;
	/* 50% * 0.01 s = 0.005 s: 0.005 low, then 0.005 s high; our eyes are not able to notice, that it is a vibrating light */
	sConfig.OCMode = TIM_OCMODE_PWM1;
	sConfig.OCPolarity = TIM_OCPOLARITY_HIGH;
	sConfig.OCFastMode = TIM_OCFAST_ENABLE;

	HAL_TIM_PWM_ConfigChannel(&tim2_handle, &sConfig, TIM_CHANNEL_1);

	tim3_handle.Instance = TIM3;
	tim3_handle.Init.Prescaler = 10800 - 1; /* 108000000/10800=10000 -> speed of 1 count-up: 1/10000 sec = 0.1 ms */
	tim3_handle.Init.Period = 10000 - 1; /* 10000 x 0.1 ms = 1 second period */
	tim3_handle.Init.ClockDivision = TIM_CLOCKDIVISION_DIV1;
	tim3_handle.Init.CounterMode = TIM_COUNTERMODE_UP;

	HAL_TIM_Base_Init(&tim3_handle);

	HAL_NVIC_SetPriority(TIM3_IRQn, 1, 1);
	HAL_NVIC_EnableIRQ(TIM3_IRQn);
}

void TIM3_IRQHandler() {
	HAL_TIM_IRQHandler(&tim3_handle);
}

void HAL_TIM_PeriodElapsedCallback(TIM_HandleTypeDef *htim) {
		__HAL_TIM_SET_COMPARE(&tim2_handle, TIM_CHANNEL_1, counter);
		if(counter)
			counter--;
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
