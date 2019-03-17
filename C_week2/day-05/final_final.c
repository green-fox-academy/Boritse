/**
 ******************************************************************************
 * @file    main.c
 * @author  Ac6
 * @version V1.0
 * @date    01-December-2013
 * @brief   Default main function.
 ******************************************************************************
 */

/*
 Reaction tester game:
  1. The board says via UART: "Let's play a game! Are you ready?" Flash the green LED in this stage, with 1 Hz frequency.
  2. If the user push the button, start the game with turning the led off immediately.
  3. Delay a random time between 1-10s timeframe. Use the random generator of the board to make this time.
  4. After the random time elapsed, turn on the led, and start measure the reaction time.
  5. You need to measure the time that is elapsed between the LED turned on and the button pressed. Use the Systick timer for this.
  6. Print out the result for the user.
*/


#include "stm32f7xx.h"
#include "stm32746g_discovery.h"

GPIO_InitTypeDef GPIOTxConfig;
GPIO_InitTypeDef GPIORxConfig;

UART_HandleTypeDef uart_handle;

GPIO_InitTypeDef leds;

RNG_HandleTypeDef rng_handle;

void init();
uint8_t HAL_delay_with_interrupt(uint32_t Delay, uint8_t counter);

int main(void) {

	BSP_PB_Init(BUTTON_KEY, BUTTON_MODE_GPIO);

	HAL_Init();

	init();

	__HAL_RCC_GPIOA_CLK_ENABLE()
	;
	GPIOTxConfig.Pin = GPIO_PIN_9;
	GPIOTxConfig.Mode = GPIO_MODE_AF_PP;
	GPIOTxConfig.Pull = GPIO_NOPULL;
	GPIOTxConfig.Speed = GPIO_SPEED_FAST;
	GPIOTxConfig.Alternate = GPIO_AF7_USART1;
	HAL_GPIO_Init(GPIOA, &GPIOTxConfig);

	__HAL_RCC_GPIOB_CLK_ENABLE()
	;
	GPIORxConfig.Pin = GPIO_PIN_7;
	GPIORxConfig.Mode = GPIO_MODE_AF_PP;
	GPIORxConfig.Pull = GPIO_NOPULL;
	GPIORxConfig.Speed = GPIO_SPEED_FAST;
	GPIORxConfig.Alternate = GPIO_AF7_USART1;
	HAL_GPIO_Init(GPIOA, &GPIORxConfig);

	__HAL_RCC_USART1_CLK_ENABLE()
	;

	uart_handle.Instance = USART1;
	uart_handle.Init.BaudRate = 115200;
	uart_handle.Init.WordLength = UART_WORDLENGTH_8B;
	uart_handle.Init.StopBits = UART_STOPBITS_1;
	uart_handle.Init.Parity = UART_PARITY_NONE;
	uart_handle.Init.HwFlowCtl = UART_HWCONTROL_NONE;
	uart_handle.Init.Mode = UART_MODE_TX_RX;

	BSP_COM_Init(COM1, &uart_handle);

	__HAL_RCC_GPIOF_CLK_ENABLE()
	;

	leds.Pin = GPIO_PIN_10;
	leds.Mode = GPIO_MODE_OUTPUT_PP;
	leds.Pull = GPIO_NOPULL;
	leds.Speed = GPIO_SPEED_HIGH;

	HAL_GPIO_Init(GPIOF, &leds);

	uint8_t start_with[] = "Let's play a game! Are you ready?\n";
	HAL_UART_Transmit(&uart_handle, (uint8_t*) start_with, 34, HAL_MAX_DELAY);

	uint8_t counter = 0;
	uint32_t random_number = HAL_RNG_GetRandomNumber(&rng_handle) % 9001 + 1000;
	uint8_t loop = 1;

	while (loop) {

		while (!counter) {
			HAL_GPIO_WritePin(GPIOF, GPIO_PIN_10, GPIO_PIN_SET);
			counter = HAL_delay_with_interrupt(500, counter);
			HAL_GPIO_WritePin(GPIOF, GPIO_PIN_10, GPIO_PIN_RESET);
			counter = HAL_delay_with_interrupt(500, counter);
		}

		HAL_Delay(random_number);
		uint32_t game_start = HAL_GetTick();
		HAL_GPIO_WritePin(GPIOF, GPIO_PIN_10, GPIO_PIN_SET);

		counter = 0;
		uint32_t button_pressed = 0;

		while (!counter) {
			if (BSP_PB_GetState(BUTTON_KEY)) {
				button_pressed = HAL_GetTick();
				HAL_GPIO_WritePin(GPIOF, GPIO_PIN_10, GPIO_PIN_RESET);
				counter++;
			}
		}

		uint32_t reaction_time = button_pressed - game_start;
		uint8_t result[10];
		uint8_t result_message[] = "your reaction time was: ";

		HAL_UART_Transmit(&uart_handle, (uint8_t*) result_message, 25,
		HAL_MAX_DELAY);
		sprintf(result, "%lu\n", reaction_time);
		HAL_UART_Transmit(&uart_handle, (uint8_t*) result, strlen(result),
				HAL_MAX_DELAY);

		loop = 0;
	}
}

void init() {

	__HAL_RCC_USART1_CLK_ENABLE()
	;

	uart_handle.Instance = USART1;
	uart_handle.Init.BaudRate = 115200;
	uart_handle.Init.WordLength = UART_WORDLENGTH_8B;
	uart_handle.Init.StopBits = UART_STOPBITS_1;
	uart_handle.Init.Parity = UART_PARITY_NONE;
	uart_handle.Init.HwFlowCtl = UART_HWCONTROL_NONE;
	uart_handle.Init.Mode = UART_MODE_TX_RX;

	BSP_COM_Init(COM1, &uart_handle);

	__HAL_RCC_RNG_CLK_ENABLE()
	;

	rng_handle.Instance = RNG;

	HAL_RNG_Init(&rng_handle);
}


uint8_t HAL_delay_with_interrupt(uint32_t Delay, uint8_t counter) {
	uint32_t tickstart = HAL_GetTick();
	uint32_t wait = Delay;
	/* Add a freq to guarantee minimum wait*/
	if (wait < HAL_MAX_DELAY) {
		wait += (uint32_t) (HAL_GetTickFreq());
	}

	while ((HAL_GetTick() - tickstart) < wait) {
		if (BSP_PB_GetState(BUTTON_KEY)) {
			HAL_GPIO_WritePin(GPIOF, GPIO_PIN_10, GPIO_PIN_RESET);
			counter++;
		}
	}
	return counter;
}
