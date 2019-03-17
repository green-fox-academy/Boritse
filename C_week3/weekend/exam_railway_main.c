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
#include <string.h>

TIM_HandleTypeDef tim2_handle;
UART_HandleTypeDef uart_handle;
GPIO_InitTypeDef extern_button;
GPIO_InitTypeDef PA15_LED_config;
//GPIO_InitTypeDef led2_config;
//GPIO_InitTypeDef led3_config;
//GPIO_InitTypeDef led4_config;
GPIO_InitTypeDef GPIOTxConfig;
GPIO_InitTypeDef GPIORxConfig;

typedef enum {
	OPEN, SECURING, SECURED, OPENING
} crossing_state_t;
volatile int flashing_slower = 0;
volatile int time_count = 0;
crossing_state_t crossing_state = OPEN;

volatile char entered_open[22] = "Entered in OPEN state";
volatile char entered_securing[26] = "Entered in SECURING state";
volatile char entered_secured[25] = "Entered in SECURED state";
volatile char entered_opening[25] = "Entered in OPENING state";


void tim2_init();
void uart_init();
void led_init();
void extern_button_init();
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
	__HAL_RCC_USART1_CLK_ENABLE()
	;

	led_init();
	uart_init();
	tim2_init();

	HAL_TIM_Base_Start_IT(&tim2_handle);

	extern_button_init();

	while (1) {
		if (crossing_state == SECURING) {
			time_count = HAL_GetTick();
			while (HAL_GetTick() - time_count < 5000) {
				HAL_NVIC_DisableIRQ(EXTI15_10_IRQn);
			}
			HAL_NVIC_EnableIRQ(EXTI15_10_IRQn);
			HAL_UART_Transmit_IT(&uart_handle, entered_secured, 24);
			crossing_state = SECURED;
		} else if (crossing_state == OPENING) {
			time_count = HAL_GetTick();
			while (HAL_GetTick() - time_count < 6000) {
				HAL_NVIC_DisableIRQ(EXTI15_10_IRQn);
			}
			HAL_NVIC_EnableIRQ(EXTI15_10_IRQn);
			crossing_state = OPEN;
			HAL_UART_Transmit_IT(&uart_handle, entered_open, 21);
		}
	}

}

void led_init() {
	PA15_LED_config.Pin = GPIO_PIN_15;
	PA15_LED_config.Mode = GPIO_MODE_OUTPUT_PP;
	PA15_LED_config.Pull = GPIO_NOPULL;
	PA15_LED_config.Speed = GPIO_SPEED_HIGH;

	HAL_GPIO_Init(GPIOA, &PA15_LED_config);
	/*
	 led2_config.Pin = GPIO_PIN_9;
	 led2_config.Mode = GPIO_MODE_OUTPUT_PP;
	 led2_config.Pull = GPIO_NOPULL;
	 led2_config.Speed = GPIO_SPEED_HIGH;

	 HAL_GPIO_Init(GPIOF, &led2_config);

	 led3_config.Pin = GPIO_PIN_8;
	 led3_config.Mode = GPIO_MODE_OUTPUT_PP;
	 led3_config.Pull = GPIO_NOPULL;
	 led3_config.Speed = GPIO_SPEED_HIGH;

	 HAL_GPIO_Init(GPIOF, &led3_config);

	 led4_config.Pin = GPIO_PIN_6;
	 led4_config.Mode = GPIO_MODE_OUTPUT_PP;
	 led4_config.Pull = GPIO_NOPULL;
	 led4_config.Speed = GPIO_SPEED_HIGH;

	 HAL_GPIO_Init(GPIOF, &led4_config);

	 */
}
void uart_init() {
	uart_handle.Instance = USART1;
	uart_handle.Init.BaudRate = 115200;
	uart_handle.Init.WordLength = UART_WORDLENGTH_8B;
	uart_handle.Init.StopBits = UART_STOPBITS_1;
	uart_handle.Init.Parity = UART_PARITY_NONE;
	uart_handle.Init.HwFlowCtl = UART_HWCONTROL_NONE;
	uart_handle.Init.Mode = UART_MODE_TX_RX;

	BSP_COM_Init(COM1, &uart_handle);

	HAL_NVIC_SetPriority(USART1_IRQn, 3, 0);
	HAL_NVIC_EnableIRQ(USART1_IRQn);
}

void USART1_IRQHandler() {
	HAL_UART_IRQHandler(&uart_handle);
}

void HAL_UART_RxCpltCallback(UART_HandleTypeDef *huart) {
}

void tim2_init() {
	tim2_handle.Instance = TIM2;
	tim2_handle.Init.Prescaler = 10800 - 1;
	tim2_handle.Init.Period = 10000 / 4 - 1;
	tim2_handle.Init.ClockDivision = TIM_CLOCKDIVISION_DIV1;
	tim2_handle.Init.CounterMode = TIM_COUNTERMODE_UP;

	HAL_TIM_Base_Init(&tim2_handle);

	HAL_NVIC_SetPriority(TIM2_IRQn, 4, 2);
	HAL_NVIC_EnableIRQ(TIM2_IRQn);
}

void TIM2_IRQHandler() {
	HAL_TIM_IRQHandler(&tim2_handle);
}

void HAL_TIM_PeriodElapsedCallback(TIM_HandleTypeDef *htim) {
	if (crossing_state == OPEN) {
		HAL_GPIO_TogglePin(GPIOA, GPIO_PIN_15);
	} else if (crossing_state == SECURING || crossing_state == OPENING) {
		flashing_slower++;
		if (flashing_slower % 2 == 0) {
			HAL_GPIO_TogglePin(GPIOA, GPIO_PIN_15);
		}
	} else if (crossing_state == SECURED) {
		HAL_GPIO_WritePin(GPIOA, GPIO_PIN_15, GPIO_PIN_RESET);
	}
}

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
	if (crossing_state == OPEN) {
		flashing_slower = 0;
		crossing_state = SECURING;
		HAL_UART_Transmit_IT(&uart_handle, entered_securing, 25);
	} else if (crossing_state == SECURED) {
		flashing_slower = 0;
		crossing_state = OPENING;
		HAL_UART_Transmit_IT(&uart_handle, entered_opening, 24);
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

