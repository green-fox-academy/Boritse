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
Control 2 LED from via UART:
    1. when you get the "on" (with line break) command on UART from your PC, turn on the green LED on your board!
    2. when you get the "off" (with line break) command on UART from your PC, turn on the red LED on your board!!
    3. when you get a command, which is not ON and not OFF, flash the RED light 3 times!
 */

#include "stm32f7xx.h"
#include "stm32746g_discovery.h"
#include <string.h>

GPIO_InitTypeDef GPIOTxConfig;
GPIO_InitTypeDef GPIORxConfig;

GPIO_InitTypeDef leds;

UART_HandleTypeDef UartHandle;

int main(void) {
	HAL_Init();

	__HAL_RCC_GPIOA_CLK_ENABLE()
	;
	__HAL_RCC_GPIOB_CLK_ENABLE()
	;
	__HAL_RCC_GPIOF_CLK_ENABLE()
	;

	GPIOTxConfig.Pin = GPIO_PIN_9;
	GPIOTxConfig.Mode = GPIO_MODE_AF_PP;
	GPIOTxConfig.Pull = GPIO_NOPULL;
	GPIOTxConfig.Speed = GPIO_SPEED_FAST;
	GPIOTxConfig.Alternate = GPIO_AF7_USART1;

	HAL_GPIO_Init(GPIOA, &GPIOTxConfig);

	GPIORxConfig.Pin = GPIO_PIN_7;
	GPIORxConfig.Mode = GPIO_MODE_AF_PP;
	GPIOTxConfig.Pull = GPIO_NOPULL;
	GPIORxConfig.Speed = GPIO_SPEED_FAST;
	GPIORxConfig.Alternate = GPIO_AF7_USART1;

	HAL_GPIO_Init(GPIOB, &GPIORxConfig);

	__HAL_RCC_USART1_CLK_ENABLE()
	;

	UartHandle.Instance = USART1;
	UartHandle.Init.BaudRate = 115200;
	UartHandle.Init.WordLength = UART_WORDLENGTH_8B;
	UartHandle.Init.StopBits = UART_STOPBITS_1;
	UartHandle.Init.Parity = UART_PARITY_NONE;
	UartHandle.Init.HwFlowCtl = UART_HWCONTROL_NONE;
	UartHandle.Init.Mode = UART_MODE_TX_RX;

	BSP_COM_Init(COM1, &UartHandle);

	leds.Pin = GPIO_PIN_10 | GPIO_PIN_8;
	leds.Mode = GPIO_MODE_OUTPUT_PP;
	leds.Pull = GPIO_NOPULL;
	leds.Speed = GPIO_SPEED_HIGH;

	HAL_GPIO_Init(GPIOF, &leds);

	while (1) {

		int index_counter = 0;
		uint8_t input[15];
		uint8_t single_char;
		uint8_t on[3] = "on";
		uint8_t off[4] = "off";

		while (1) {

			while (HAL_UART_Receive(&UartHandle, (uint8_t*) &single_char, 1,
			HAL_MAX_DELAY) == HAL_OK) {
				if (single_char != '\n') {
					input[index_counter] = single_char;
					index_counter++;
				} else {
					input[index_counter] = '\0';
					if (strcmp(input, on) == 0) {
						HAL_GPIO_WritePin(GPIOF, GPIO_PIN_8, GPIO_PIN_RESET);
						HAL_GPIO_WritePin(GPIOF, GPIO_PIN_10, GPIO_PIN_SET);
					} else if (strcmp(input, off) == 0) {
						HAL_GPIO_WritePin(GPIOF, GPIO_PIN_10, GPIO_PIN_RESET);
						HAL_GPIO_WritePin(GPIOF, GPIO_PIN_8, GPIO_PIN_SET);
					} else {
						HAL_GPIO_WritePin(GPIOF, GPIO_PIN_10, GPIO_PIN_RESET);
						for (int i = 0; i < 3; i++) {
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
