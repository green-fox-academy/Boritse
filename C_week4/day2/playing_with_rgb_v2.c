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

#define UART_PUTCHAR int __io_putchar(int ch)

typedef enum{
	GREEN, BLUE, RED
}button_mode_t;

char* button_names[] = {"GREEN", "BLUE", "RED"};

button_mode_t button_mode = GREEN;

UART_HandleTypeDef UartHandle;
GPIO_InitTypeDef PA15_LED_config;
GPIO_InitTypeDef I0_LED_config;
GPIO_InitTypeDef B4_LED_config;
volatile TIM_HandleTypeDef tim2_handle;
volatile TIM_HandleTypeDef tim3_handle;
volatile TIM_HandleTypeDef tim5_handle;
volatile TIM_HandleTypeDef* temp_tim_handle = &tim2_handle;
TIM_OC_InitTypeDef sConfig;
volatile uint32_t temp_channel = TIM_CHANNEL_1;

GPIO_InitTypeDef gpio_adc_pin;
ADC_HandleTypeDef adc_handle;
ADC_ChannelConfTypeDef adc_channel_config;

int adc_val;

void pa15_led_init();
void tim_init();

static void Error_Handler(void);
static void SystemClock_Config(void);

int main(void) {
	HAL_Init();

	SystemClock_Config();

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

	__HAL_RCC_GPIOA_CLK_ENABLE()
	;
	gpio_adc_pin.Mode = GPIO_MODE_ANALOG;
	gpio_adc_pin.Pin = GPIO_PIN_0;
	gpio_adc_pin.Speed = GPIO_SPEED_FAST;
	gpio_adc_pin.Pull = GPIO_NOPULL;
	HAL_GPIO_Init(GPIOA, &gpio_adc_pin);

	__HAL_RCC_ADC3_CLK_ENABLE()
	;
	adc_handle.Instance = ADC3;
	HAL_ADC_Init(&adc_handle);

	adc_channel_config.Channel = ADC_CHANNEL_0;
	adc_channel_config.SamplingTime = ADC_SAMPLETIME_56CYCLES;
	HAL_ADC_ConfigChannel(&adc_handle, &adc_channel_config);

	__HAL_RCC_GPIOI_CLK_ENABLE();
	__HAL_RCC_GPIOB_CLK_ENABLE();
	__HAL_RCC_TIM2_CLK_ENABLE();
	__HAL_RCC_TIM3_CLK_ENABLE();
	__HAL_RCC_TIM5_CLK_ENABLE();
	pa15_led_init();
	tim_init();

	HAL_TIM_PWM_Start(&tim2_handle, TIM_CHANNEL_1);
	__HAL_TIM_SET_COMPARE(&tim2_handle, TIM_CHANNEL_1, 100);

	HAL_TIM_PWM_Start(&tim3_handle, TIM_CHANNEL_1);
	__HAL_TIM_SET_COMPARE(&tim3_handle, TIM_CHANNEL_1, 100);

	HAL_TIM_PWM_Start(&tim5_handle, TIM_CHANNEL_4);
	__HAL_TIM_SET_COMPARE(&tim5_handle, TIM_CHANNEL_4, 100);

	BSP_PB_Init(BUTTON_KEY, BUTTON_MODE_EXTI);

	HAL_NVIC_SetPriority(EXTI15_10_IRQn, 4, 1);
	HAL_NVIC_EnableIRQ(EXTI15_10_IRQn);

	while (1) {
		//HAL_Delay(250);
		HAL_ADC_Start(&adc_handle);
		if (HAL_ADC_PollForConversion(&adc_handle, 10) == HAL_OK) {
			adc_val = HAL_ADC_GetValue(&adc_handle);
			if(button_mode == GREEN){
				__HAL_TIM_SET_COMPARE(&tim2_handle, TIM_CHANNEL_1, adc_val / 42);
			}else if(button_mode == BLUE){
				__HAL_TIM_SET_COMPARE(&tim5_handle, TIM_CHANNEL_4, adc_val / 42);
			}else{
				__HAL_TIM_SET_COMPARE(&tim3_handle, TIM_CHANNEL_1, adc_val / 42);
			}

			//printf("ADC value: %d, button mode: %s.\n", adc_val, button_names[button_mode]);
		}
	}
}

UART_PUTCHAR
{
	HAL_UART_Transmit(&UartHandle, (uint8_t*) &ch, 1, 0xFFFF);
	return ch;
}

void EXTI15_10_IRQHandler() {
	HAL_GPIO_EXTI_IRQHandler(GPIO_PIN_11);
}

void HAL_GPIO_EXTI_Callback(uint16_t GPIO_Pin) {
	if(button_mode == GREEN){
		button_mode = BLUE;
	}else if(button_mode == BLUE){
		button_mode = RED;
	}else{
		button_mode = GREEN;
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
	tim3_handle.Init.Prescaler = 108 - 1; /* 108000000/10800=10000 -> speed of 1 count-up: 1/10000 sec = 0.1 ms */
	tim3_handle.Init.Period = 100 - 1; /* 10000 x 0.1 ms = 1 second period */
	tim3_handle.Init.ClockDivision = TIM_CLOCKDIVISION_DIV1;
	tim3_handle.Init.CounterMode = TIM_COUNTERMODE_UP;

	HAL_TIM_PWM_Init(&tim3_handle);

	HAL_TIM_PWM_ConfigChannel(&tim3_handle, &sConfig, TIM_CHANNEL_1);

	tim5_handle.Instance = TIM5;
	tim5_handle.Init.Prescaler = 108 - 1; /* 108000000/10800=10000 -> speed of 1 count-up: 1/10000 sec = 0.1 ms */
	tim5_handle.Init.Period = 100 - 1; /* 10000 x 0.1 ms = 1 second period */
	tim5_handle.Init.ClockDivision = TIM_CLOCKDIVISION_DIV1;
	tim5_handle.Init.CounterMode = TIM_COUNTERMODE_UP;

	HAL_TIM_PWM_Init(&tim5_handle);

	HAL_TIM_PWM_ConfigChannel(&tim5_handle, &sConfig, TIM_CHANNEL_4);
}

void pa15_led_init() {
	PA15_LED_config.Pin = GPIO_PIN_15;
	PA15_LED_config.Mode = GPIO_MODE_AF_PP; /* configure as output, in push-pull mode */
	PA15_LED_config.Pull = GPIO_NOPULL;
	PA15_LED_config.Speed = GPIO_SPEED_HIGH;
	PA15_LED_config.Alternate = GPIO_AF1_TIM2; /* this alternate function we need to use TIM2 in output compare mode */

	HAL_GPIO_Init(GPIOA, &PA15_LED_config);

	I0_LED_config.Pin = GPIO_PIN_0;
	I0_LED_config.Mode = GPIO_MODE_AF_PP; /* configure as output, in push-pull mode */
	I0_LED_config.Pull = GPIO_NOPULL;
	I0_LED_config.Speed = GPIO_SPEED_HIGH;
	I0_LED_config.Alternate = GPIO_AF2_TIM5; /* this alternate function we need to use TIM2 in output compare mode */

	HAL_GPIO_Init(GPIOI, &I0_LED_config);

	B4_LED_config.Pin = GPIO_PIN_4;
	B4_LED_config.Mode = GPIO_MODE_AF_PP; /* configure as output, in push-pull mode */
	B4_LED_config.Pull = GPIO_NOPULL;
	B4_LED_config.Speed = GPIO_SPEED_HIGH;
	B4_LED_config.Alternate = GPIO_AF2_TIM3; /* this alternate function we need to use TIM2 in output compare mode */

	HAL_GPIO_Init(GPIOB, &B4_LED_config);
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
