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

#define UART_PUTCHAR int __io_putchar(int ch)

GPIO_InitTypeDef GPIOTxConfig;
GPIO_InitTypeDef GPIORxConfig;

GPIO_InitTypeDef leds;

UART_HandleTypeDef UartHandle;

int main(void) {
	HAL_Init();

	/* enable GPIO clock */
	__HAL_RCC_GPIOA_CLK_ENABLE()
	;
	__HAL_RCC_GPIOB_CLK_ENABLE()
	;
	__HAL_RCC_GPIOF_CLK_ENABLE()
	;

	/* configure GPIO for UART transmit line */
	GPIOTxConfig.Pin = GPIO_PIN_9;
	GPIOTxConfig.Mode = GPIO_MODE_AF_PP;
	GPIOTxConfig.Pull = GPIO_NOPULL;
	GPIOTxConfig.Speed = GPIO_SPEED_FAST;
	GPIOTxConfig.Alternate = GPIO_AF7_USART1;

	HAL_GPIO_Init(GPIOA, &GPIOTxConfig);

	/* configure GPIO for UART receive line */
	GPIORxConfig.Pin = GPIO_PIN_7;
	GPIORxConfig.Mode = GPIO_MODE_AF_PP;
	GPIOTxConfig.Pull = GPIO_NOPULL;
	GPIORxConfig.Speed = GPIO_SPEED_FAST;
	GPIORxConfig.Alternate = GPIO_AF7_USART1;

	HAL_GPIO_Init(GPIOB, &GPIORxConfig);

	/* enable the clock of the used peripherial instance */
	__HAL_RCC_USART1_CLK_ENABLE()
	;

	/* defining the UART configuration structure */
	UartHandle.Instance = USART1;
	UartHandle.Init.BaudRate = 115200;
	UartHandle.Init.WordLength = UART_WORDLENGTH_8B;
	UartHandle.Init.StopBits = UART_STOPBITS_1;
	UartHandle.Init.Parity = UART_PARITY_NONE;
	UartHandle.Init.HwFlowCtl = UART_HWCONTROL_NONE;
	UartHandle.Init.Mode = UART_MODE_TX_RX;

	BSP_COM_Init(COM1, &UartHandle);

	leds.Pin = GPIO_PIN_10 | GPIO_PIN_8; /* setting up 2 pins at once with | operator */
	leds.Mode = GPIO_MODE_OUTPUT_PP; /* configure as output, in push-pull mode */
	leds.Pull = GPIO_NOPULL; /* we don't need internal pull-up or -down resistor */
	leds.Speed = GPIO_SPEED_HIGH;

	HAL_GPIO_Init(GPIOF, &leds);

	while (1) {

		//HAL_Delay(1000);

		//HAL_UART_Transmit(&UartHandle, (uint8_t*) hello, strlen(hello), 0xFFFF);
		int index_counter = 0;
		uint8_t input[15];
		uint8_t single_char;
		uint8_t on[3] = "on";
		uint8_t off[4] = "off";

		while (1) {

			//HAL_UART_Transmit(&UartHandle, (uint8_t*) hello, strlen(hello), 0xFFFF);
			while (HAL_UART_Receive(&UartHandle, (uint8_t*) &single_char, 1,
			HAL_MAX_DELAY) == HAL_OK) {
				if (single_char != '\n') {
					input[index_counter] = single_char;
					index_counter++;
				} else {
					input[index_counter] = '\0';
					if (strcmp(input, on) == 0) {
						HAL_GPIO_WritePin(GPIOF, GPIO_PIN_8, GPIO_PIN_RESET); /* setting the pin to 0 */
						HAL_GPIO_WritePin(GPIOF, GPIO_PIN_10, GPIO_PIN_SET);
					} else if (strcmp(input, off) == 0) {
						HAL_GPIO_WritePin(GPIOF, GPIO_PIN_10, GPIO_PIN_RESET); /* setting the pin to 0 */
						HAL_GPIO_WritePin(GPIOF, GPIO_PIN_8, GPIO_PIN_SET);
					} else {
						HAL_GPIO_WritePin(GPIOF, GPIO_PIN_10, GPIO_PIN_RESET);
						for (int i = 0; i < 3; i++) { /* setting the pin to 0 */
							HAL_GPIO_WritePin(GPIOF, GPIO_PIN_8, GPIO_PIN_SET);
							HAL_Delay(500);
							HAL_GPIO_WritePin(GPIOF, GPIO_PIN_8,
									GPIO_PIN_RESET);
							HAL_Delay(500);
						}
					}
					index_counter = 0;
				}
			}

		}
	}
}
