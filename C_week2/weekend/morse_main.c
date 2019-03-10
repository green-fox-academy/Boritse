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

GPIO_InitTypeDef GPIOTxConfig;
GPIO_InitTypeDef GPIORxConfig;

GPIO_InitTypeDef leds;

UART_HandleTypeDef uart_handle;

void long_signal();
void short_signal();
void ascii_code(char single_letter);

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
	uart_handle.Instance = USART1;
	uart_handle.Init.BaudRate = 115200;
	uart_handle.Init.WordLength = UART_WORDLENGTH_8B;
	uart_handle.Init.StopBits = UART_STOPBITS_1;
	uart_handle.Init.Parity = UART_PARITY_NONE;
	uart_handle.Init.HwFlowCtl = UART_HWCONTROL_NONE;
	uart_handle.Init.Mode = UART_MODE_TX_RX;

	BSP_COM_Init(COM1, &uart_handle);

	leds.Pin = GPIO_PIN_10; /* setting up 2 pins at once with | operator */
	leds.Mode = GPIO_MODE_OUTPUT_PP; /* configure as output, in push-pull mode */
	leds.Pull = GPIO_NOPULL; /* we don't need internal pull-up or -down resistor */
	leds.Speed = GPIO_SPEED_HIGH;

	HAL_GPIO_Init(GPIOF, &leds);

	char single_character;

	while (1) {
		//HAL_UART_Transmit(&uart_handle, (uint8_t*) result_message, 25,HAL_MAX_DELAY);
		while (HAL_UART_Receive(&uart_handle, (uint8_t*) &single_character, 1, HAL_MAX_DELAY) == HAL_OK){
			if(single_character==' ' || single_character=='\n') {
				HAL_Delay(1000);
			}else {
				ascii_code(single_character);
				HAL_Delay(500);
			}
		}
	}
}

void long_signal(){
	HAL_GPIO_WritePin(GPIOF, GPIO_PIN_10, GPIO_PIN_SET);
	HAL_Delay(750);
	HAL_GPIO_WritePin(GPIOF, GPIO_PIN_10, GPIO_PIN_RESET);
	HAL_Delay(250);
}

void short_signal(){
	HAL_GPIO_WritePin(GPIOF, GPIO_PIN_10, GPIO_PIN_SET);
	HAL_Delay(250);
	HAL_GPIO_WritePin(GPIOF, GPIO_PIN_10, GPIO_PIN_RESET);
	HAL_Delay(250);
}

void ascii_code(char single_letter){
	switch(single_letter){
		case('a'):
			short_signal();
			long_signal();
			break;
		case('b'):
			long_signal();
			short_signal();
			short_signal();
			short_signal();
			break;
		case('c'):
			long_signal();
			short_signal();
			long_signal();
			short_signal();
			break;
		case('d'):
			long_signal();
			short_signal();
			short_signal();
			break;
		case('e'):
			short_signal();
			break;
		case('f'):
			short_signal();
			short_signal();
			long_signal();
			short_signal();
			break;
		case('g'):
			long_signal();
			long_signal();
			short_signal();
			break;
		case('h'):
			short_signal();
			short_signal();
			short_signal();
			short_signal();
			break;
		case('i'):
			short_signal();
			short_signal();
			break;
		case('j'):
			short_signal();
			long_signal();
			long_signal();
			long_signal();
			break;
		case('k'):
			long_signal();
			short_signal();
			long_signal();
			break;
		case('l'):
			short_signal();
			long_signal();
			short_signal();
			short_signal();
			break;
		case('m'):
			long_signal();
			long_signal();
			break;
		case('n'):
			long_signal();
			short_signal();
			break;
		case('o'):
			long_signal();
			long_signal();
			long_signal();
			break;
		case('p'):
			short_signal();
			long_signal();
			long_signal();
			short_signal();
			break;
		case('q'):
			long_signal();
			long_signal();
			short_signal();
			long_signal();
			break;
		case('r'):
			short_signal();
			long_signal();
			short_signal();
			break;
		case('s'):
			short_signal();
			short_signal();
			short_signal();
			break;
		case('t'):
			long_signal();
			break;
		case('u'):
			short_signal();
			short_signal();
			long_signal();
			break;
		case('v'):
			short_signal();
			short_signal();
			short_signal();
			long_signal();
			break;
		case('w'):
			short_signal();
			long_signal();
			long_signal();
			break;
		case('x'):
			long_signal();
			short_signal();
			short_signal();
			long_signal();
			break;
		case('y'):
			long_signal();
			short_signal();
			long_signal();
			long_signal();
			break;
		case('z'):
			long_signal();
			long_signal();
			short_signal();
			short_signal();
			break;
	}
}
