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

GPIO_InitTypeDef volume_up_button;
GPIO_InitTypeDef volume_down_button;
GPIO_InitTypeDef switch_up_button;
GPIO_InitTypeDef switch_down_button;

TIM_HandleTypeDef tim2_handle;

UART_HandleTypeDef uart_handle;

TIM_OC_InitTypeDef sConfig;

GPIO_InitTypeDef PA15_LED_config;

typedef enum button_state {
	PUSHED, RELEASED
} button_state_t;

button_state_t volume_up_state = RELEASED;
button_state_t volume_down_state = RELEASED;
button_state_t switch_up_state = RELEASED;
button_state_t switch_down_state = RELEASED;

volatile int timer_start = 0;
volatile int time_difference = 0;

uint8_t volume = 25;
float MHz = 93.1;
float radio_channels[5] = { 88.1, 89.5, 90.9, 92.1, 92.9 };

void extern_button_init();
void pa15_led_init();
void tim2_init();
void uart_init();

static void Error_Handler(void);
static void SystemClock_Config(void);

int main(void) {
	HAL_Init();

	__HAL_RCC_GPIOF_CLK_ENABLE()
	;
	__HAL_RCC_GPIOA_CLK_ENABLE()
	;
	__HAL_RCC_GPIOB_CLK_ENABLE()
	;
	__HAL_RCC_TIM2_CLK_ENABLE()
	;
	__HAL_RCC_USART1_CLK_ENABLE()
	;

	Error_Handler();
	SystemClock_Config();

	extern_button_init();
	tim2_init();
	pa15_led_init();
	uart_init();

	uint8_t positive_message[] = "I'm set to a channel\n";
	uint8_t negative_message[] = "I'm not set to a channel\n";

	while (1) {

		if(MHz == radio_channels[0] || MHz == radio_channels[1] || MHz == radio_channels[2] || MHz == radio_channels[3] || MHz == radio_channels[4] ) {
			HAL_UART_Transmit(&uart_handle, positive_message, 21, HAL_MAX_DELAY);
			HAL_Delay(2000);
		} else{
			HAL_UART_Transmit(&uart_handle, negative_message, 25, HAL_MAX_DELAY);
			HAL_Delay(2000);
		}

		if(MHz > 92)
			HAL_GPIO_WritePin(GPIOA, GPIO_PIN_15, SET);

	/*HAL_UART_Transmit(&uart_handle, &volume, 1, HAL_MAX_DELAY);
	 HAL_UART_Transmit(&uart_handle, &space, 1, HAL_MAX_DELAY);
	 HAL_Delay(2000);
	 HAL_UART_Transmit(&uart_handle, (uint8_t *) &MHz, 1, HAL_MAX_DELAY);
	 HAL_UART_Transmit(&uart_handle, &space, 1, HAL_MAX_DELAY);
	 HAL_Delay(2000);*/
}
}

void extern_button_init() {
volume_up_button.Pin = GPIO_PIN_10; /* this is about PIN 10 */
volume_up_button.Mode = GPIO_MODE_IT_RISING_FALLING; /* configure as input */
/* we don't need internal pull-up or -down resistor, we use an external one */
volume_up_button.Pull = GPIO_NOPULL;
volume_up_button.Speed = GPIO_SPEED_HIGH; /* high-speed */

HAL_GPIO_Init(GPIOF, &volume_up_button);

volume_down_button.Pin = GPIO_PIN_0; /* this is about PIN 10 */
volume_down_button.Mode = GPIO_MODE_IT_RISING_FALLING; /* configure as input */
/* we don't need internal pull-up or -down resistor, we use an external one */
volume_down_button.Pull = GPIO_NOPULL;
volume_down_button.Speed = GPIO_SPEED_HIGH; /* high-speed */

HAL_GPIO_Init(GPIOA, &volume_down_button);

switch_up_button.Pin = GPIO_PIN_7; /* this is about PIN 10 */
switch_up_button.Mode = GPIO_MODE_IT_RISING_FALLING; /* configure as input */
/* we don't need internal pull-up or -down resistor, we use an external one */
switch_up_button.Pull = GPIO_NOPULL;
switch_up_button.Speed = GPIO_SPEED_HIGH; /* high-speed */

HAL_GPIO_Init(GPIOF, &switch_up_button);

switch_down_button.Pin = GPIO_PIN_4; /* this is about PIN 10 */
switch_down_button.Mode = GPIO_MODE_IT_RISING_FALLING; /* configure as input */
/* we don't need internal pull-up or -down resistor, we use an external one */
switch_down_button.Pull = GPIO_NOPULL;
switch_down_button.Speed = GPIO_SPEED_HIGH; /* high-speed */

HAL_GPIO_Init(GPIOB, &switch_down_button);

HAL_NVIC_SetPriority(EXTI15_10_IRQn, 4, 1);
HAL_NVIC_SetPriority(EXTI9_5_IRQn, 5, 1);
HAL_NVIC_SetPriority(EXTI0_IRQn, 3, 1);
HAL_NVIC_SetPriority(EXTI4_IRQn, 2, 1);

HAL_NVIC_EnableIRQ(EXTI15_10_IRQn);
HAL_NVIC_EnableIRQ(EXTI9_5_IRQn);
HAL_NVIC_EnableIRQ(EXTI0_IRQn);
HAL_NVIC_EnableIRQ(EXTI4_IRQn);
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
tim2_handle.Init.Period = 10000 - 1; /* 10000 x 0.1 ms = 1 second period */
tim2_handle.Init.ClockDivision = TIM_CLOCKDIVISION_DIV1;
tim2_handle.Init.CounterMode = TIM_COUNTERMODE_UP;

/* configure the timer */
HAL_TIM_Base_Init(&tim2_handle);

/* starting the timer */
HAL_TIM_Base_Start(&tim2_handle);
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
}

void EXTI15_10_IRQHandler() {
HAL_GPIO_EXTI_IRQHandler(volume_up_button.Pin);
}

void EXTI9_5_IRQHandler() {
HAL_GPIO_EXTI_IRQHandler(switch_up_button.Pin);
}

void EXTI0_IRQHandler() {
HAL_GPIO_EXTI_IRQHandler(volume_down_button.Pin);
}

void EXTI4_IRQHandler() {
HAL_GPIO_EXTI_IRQHandler(switch_down_button.Pin);
}

void HAL_GPIO_EXTI_Callback(uint16_t GPIO_Pin) {
if (GPIO_Pin == volume_up_button.Pin) {
	if (volume_up_state == RELEASED) {
		volume_up_state = PUSHED;
		timer_start = HAL_GetTick();
	} else if (volume_up_state == PUSHED) {
		volume_up_state = RELEASED;
		time_difference = HAL_GetTick() - timer_start;
		if (time_difference < 1000 && volume < 100) {
			volume++;
		} else if (time_difference >= 1000 && volume < 95) {
			volume += 5;
		} else {
			volume = 100;
		}
	}
} else if (GPIO_Pin == volume_down_button.Pin) {
	if (volume_down_state == RELEASED) {
		volume_down_state = PUSHED;
		timer_start = HAL_GetTick();
	} else if (volume_down_state == PUSHED) {
		volume_down_state = RELEASED;
		time_difference = HAL_GetTick() - timer_start;
		if (time_difference < 1000 && volume > 0) {
			volume--;
		} else if (time_difference >= 1000 && volume < 5) {
			volume = 0;
		} else {
			volume -= 5;
		}
	}
} else if (GPIO_Pin == switch_up_button.Pin) {
	if (switch_up_state == RELEASED) {
		switch_up_state = PUSHED;
		timer_start = HAL_GetTick();
	} else if (switch_up_state == PUSHED) {
		switch_up_state = RELEASED;
		time_difference = HAL_GetTick() - timer_start;
		if (time_difference < 1000) {
			if (MHz >= 87.5 && MHz < 108.00) {
				MHz += 0.1;
			} else if (MHz == 108.00) {
				MHz = 87.5;
			}
		} else {
			if (MHz < radio_channels[0]) {
				MHz = radio_channels[0];
			} else if (MHz >= radio_channels[0] && MHz < radio_channels[1]) {
				MHz = radio_channels[1];
			} else if (MHz >= radio_channels[1] && MHz < radio_channels[2]) {
				MHz = radio_channels[2];
			} else if (MHz >= radio_channels[2] && MHz < radio_channels[3]) {
				MHz = radio_channels[3];
			} else if (MHz >= radio_channels[3] && MHz < radio_channels[4]) {
				MHz = radio_channels[4];
			} else if (MHz > radio_channels[4]) {
				MHz = radio_channels[0];
			}
		}
	}
} else if (GPIO_Pin == switch_down_button.Pin) {
	if (switch_down_state == RELEASED) {
		switch_down_state = PUSHED;
		timer_start = HAL_GetTick();
	} else if (switch_down_state == PUSHED) {
		switch_down_state = RELEASED;
		time_difference = HAL_GetTick() - timer_start;
		if (time_difference < 1000) {
			if (MHz > 87.5 && MHz <= 108.00) {
				MHz -= 0.1;
			} else if (MHz == 87.5) {
				MHz = 108.00;
			}
		}
	} else {
		if (MHz > radio_channels[4]) {
			MHz = radio_channels[4];
		} else if (MHz > radio_channels[3] && MHz <= radio_channels[4]) {
			MHz = radio_channels[3];
		} else if (MHz > radio_channels[2] && MHz <= radio_channels[3]) {
			MHz = radio_channels[2];
		} else if (MHz > radio_channels[1] && MHz <= radio_channels[2]) {
			MHz = radio_channels[1];
		} else if (MHz > radio_channels[0] && MHz <= radio_channels[1]) {
			MHz = radio_channels[0];
		} else if (MHz < radio_channels[0]) {
			MHz = radio_channels[4];
		}
	}
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
