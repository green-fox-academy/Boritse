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

//void uart_init();
//void leds_init();

GPIO_InitTypeDef GPIOTxConfig;
GPIO_InitTypeDef GPIORxConfig;

UART_HandleTypeDef uart_handle;

GPIO_InitTypeDef leds;

static void Error_Handler(void)
{}

static void SystemClock_Config(void)
{
    RCC_OscInitTypeDef RCC_OscInitStruct = {0};
    RCC_ClkInitTypeDef RCC_ClkInitStruct = {0};

    /**Configure the main internal regulator output voltage */
    __HAL_RCC_PWR_CLK_ENABLE();
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
    RCC_ClkInitStruct.ClockType = RCC_CLOCKTYPE_HCLK|RCC_CLOCKTYPE_SYSCLK | RCC_CLOCKTYPE_PCLK1|RCC_CLOCKTYPE_PCLK2;
    RCC_ClkInitStruct.SYSCLKSource = RCC_SYSCLKSOURCE_PLLCLK;
    RCC_ClkInitStruct.AHBCLKDivider = RCC_SYSCLK_DIV1;
    RCC_ClkInitStruct.APB1CLKDivider = RCC_HCLK_DIV4;
    RCC_ClkInitStruct.APB2CLKDivider = RCC_HCLK_DIV2;

    if (HAL_RCC_ClockConfig(&RCC_ClkInitStruct, FLASH_LATENCY_7) != HAL_OK) {
        Error_Handler();
    }
}

RNG_HandleTypeDef rng_handle;

void init()
{
    SystemClock_Config();

    __HAL_RCC_USART1_CLK_ENABLE();

    uart_handle.Instance = USART1;
    uart_handle.Init.BaudRate = 115200;
    uart_handle.Init.WordLength = UART_WORDLENGTH_8B;
    uart_handle.Init.StopBits = UART_STOPBITS_1;
    uart_handle.Init.Parity = UART_PARITY_NONE;
    uart_handle.Init.HwFlowCtl = UART_HWCONTROL_NONE;
    uart_handle.Init.Mode = UART_MODE_TX_RX;

    BSP_COM_Init(COM1, &uart_handle);

    __HAL_RCC_RNG_CLK_ENABLE();

    rng_handle.Instance = RNG;

    HAL_RNG_Init(&rng_handle);
}


uint8_t HAL_delay_with_interrupt(uint32_t Delay, uint8_t counter);

int main(void){

	BSP_PB_Init(BUTTON_KEY, BUTTON_MODE_GPIO);

	//void uart_init();

	HAL_Init();

	init();

	__HAL_RCC_GPIOA_CLK_ENABLE();
	GPIOTxConfig.Pin = GPIO_PIN_9;
	GPIOTxConfig.Mode = GPIO_MODE_AF_PP;
	GPIOTxConfig.Pull = GPIO_NOPULL;
	GPIOTxConfig.Speed = GPIO_SPEED_FAST;
	GPIOTxConfig.Alternate = GPIO_AF7_USART1;
	HAL_GPIO_Init(GPIOA, &GPIOTxConfig);

	__HAL_RCC_GPIOB_CLK_ENABLE();
	GPIORxConfig.Pin = GPIO_PIN_7;
	GPIORxConfig.Mode = GPIO_MODE_AF_PP;
	GPIORxConfig.Pull = GPIO_NOPULL;
	GPIORxConfig.Speed = GPIO_SPEED_FAST;
	GPIORxConfig.Alternate = GPIO_AF7_USART1;
	HAL_GPIO_Init(GPIOA, &GPIORxConfig);

	__HAL_RCC_USART1_CLK_ENABLE();

	uart_handle.Instance = USART1;
	uart_handle.Init.BaudRate = 115200;
	uart_handle.Init.WordLength = UART_WORDLENGTH_8B;
	uart_handle.Init.StopBits = UART_STOPBITS_1;
	uart_handle.Init.Parity = UART_PARITY_NONE;
	uart_handle.Init.HwFlowCtl = UART_HWCONTROL_NONE;
	uart_handle.Init.Mode = UART_MODE_TX_RX;

	BSP_COM_Init(COM1, &uart_handle);

	//void leds_init();

	__HAL_RCC_GPIOF_CLK_ENABLE();

	leds.Pin = GPIO_PIN_10; /* setting up 2 pins at once with | operator */
	leds.Mode = GPIO_MODE_OUTPUT_PP; /* configure as output, in push-pull mode */
	leds.Pull = GPIO_NOPULL; /* we don't need internal pull-up or -down resistor */
	leds.Speed = GPIO_SPEED_HIGH;

	HAL_GPIO_Init(GPIOF, &leds);

	uint8_t start_with[] = "Let's play a game! Are you ready?\n";

	HAL_UART_Transmit(&uart_handle, (uint8_t*) start_with, 34, HAL_MAX_DELAY);

	uint8_t counter=0;

	uint32_t random_number = HAL_RNG_GetRandomNumber(&rng_handle) % 9000 + 1001;

	while(1){

		while(counter==0){
			HAL_GPIO_WritePin(GPIOF, GPIO_PIN_10, GPIO_PIN_SET);
			counter = HAL_delay_with_interrupt(500, counter);
			HAL_GPIO_WritePin(GPIOF, GPIO_PIN_10, GPIO_PIN_RESET);
			counter = HAL_delay_with_interrupt(500, counter);
		}

		HAL_Delay(random_number);
		HAL_GPIO_WritePin(GPIOF, GPIO_PIN_10, GPIO_PIN_SET);

	}
}

uint8_t HAL_delay_with_interrupt(uint32_t Delay, uint8_t counter)
{
  uint32_t tickstart = HAL_GetTick();
  uint32_t wait = Delay;
  /* Add a freq to guarantee minimum wait*/
  if (wait < HAL_MAX_DELAY)
  {
    wait += (uint32_t)(HAL_GetTickFreq());
  }

  while ((HAL_GetTick() - tickstart) < wait)
  {
	  if(BSP_PB_GetState(BUTTON_KEY)){
		  HAL_GPIO_WritePin(GPIOF, GPIO_PIN_10, GPIO_PIN_RESET);
		  counter++;
	  }
  }
  return counter;
}

/*void uart_init(){

	GPIO_InitTypeDef GPIOTxConfig;
	GPIO_InitTypeDef GPIORxConfig;

	UART_HandleTypeDef uart_handle;

	HAL_Init();

	__HAL_RCC_GPIOA_CLK_ENABLE();
	GPIOTxConfig.Pin = GPIO_PIN_9;
	GPIOTxConfig.Mode = GPIO_MODE_AF_PP;
	GPIOTxConfig.Pull = GPIO_NOPULL;
	GPIOTxConfig.Speed = GPIO_SPEED_FAST;
	GPIOTxConfig.Alternate = GPIO_AF7_USART1;
	HAL_GPIO_Init(GPIOA, &GPIOTxConfig);

	__HAL_RCC_GPIOB_CLK_ENABLE();
	GPIORxConfig.Pin = GPIO_PIN_7;
	GPIORxConfig.Mode = GPIO_MODE_AF_PP;
	GPIORxConfig.Pull = GPIO_NOPULL;
	GPIORxConfig.Speed = GPIO_SPEED_FAST;
	GPIORxConfig.Alternate = GPIO_AF7_USART1;
	HAL_GPIO_Init(GPIOA, &GPIORxConfig);

	__HAL_RCC_USART1_CLK_ENABLE();

	uart_handle.Instance = USART1;
	uart_handle.Init.BaudRate = 115200;
	uart_handle.Init.WordLength = UART_WORDLENGTH_8B;
	uart_handle.Init.StopBits = UART_STOPBITS_1;
	uart_handle.Init.Parity = UART_PARITY_NONE;
	uart_handle.Init.HwFlowCtl = UART_HWCONTROL_NONE;
	uart_handle.Init.Mode = UART_MODE_TX_RX;

	BSP_COM_Init(COM1, &uart_handle);
}

void leds_init(){
	GPIO_InitTypeDef leds;

	__HAL_RCC_GPIOF_CLK_ENABLE();

	leds.Pin = GPIO_PIN_10;
	leds.Mode = GPIO_MODE_OUTPUT_PP;
	leds.Pull = GPIO_NOPULL;
	leds.Speed = GPIO_SPEED_HIGH;

	HAL_GPIO_Init(GPIOF, &leds);
}*/
