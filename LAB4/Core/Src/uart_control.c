/*
 * uart_control.c
 *
 *  Created on: Mar 18, 2023
 *      Author: mkdjs
 */

#include "uart_control.h"

volatile HAL_StatusTypeDef adc_poll_res;
uint32_t adc_val = 0;
float temp = 0;
char temp_buf[5];

void ext_temp_sensor()
{
	HAL_ADC_Start(&hadc1);
	adc_poll_res = HAL_ADC_PollForConversion(&hadc1, 100);
	if (adc_poll_res == HAL_OK) {
		adc_val = HAL_ADC_GetValue(&hadc1);
		temp = 100 - ((float)adc_val * 3.3 / 4096.0) / (2.02 / 100.0);
		HAL_UART_Transmit(&huart3, (uint8_t *)"Temp - ", 7, 10);
		sprintf(temp_buf, "%.2f", temp);
		HAL_UART_Transmit(&huart3, (uint8_t *)temp_buf, sizeof(temp_buf), 10);
		HAL_UART_Transmit(&huart3, (uint8_t *)"\r\n", 2, 10);
	}
}

volatile uint8_t state_flag[4] = {0, 0, 0, 0};		//GREEN, ORANGE, RED, BLUE

void uart()
{
	uint8_t buf[1];
	HAL_StatusTypeDef res;

	res = HAL_UART_Receive(&huart3, buf, 1, 10);

	if (res == HAL_OK)
		switch (buf[0])
		{
			case 0x47: case 0x67:
				HAL_GPIO_TogglePin(GPIOD, GPIO_PIN_12);
				state_flag[0] = !state_flag[0];
				if (state_flag[0]) {
					HAL_UART_Transmit(&huart3, (uint8_t *)"Green - ON\r\n", 12, 10);
				} else {
					HAL_UART_Transmit(&huart3, (uint8_t *)"Green - OFF\r\n", 13, 10);
				}
				break;
			case 0x4F: case 0x6F:
				HAL_GPIO_TogglePin(GPIOD, GPIO_PIN_13);
				state_flag[1] = !state_flag[1];
				if (state_flag[1]) {
					HAL_UART_Transmit(&huart3, (uint8_t *)"Orange - ON\r\n", 13, 10);
				} else {
					HAL_UART_Transmit(&huart3, (uint8_t *)"Orange - OFF\r\n", 14, 10);
				}
				break;
			case 0x52: case 0x72:
				HAL_GPIO_TogglePin(GPIOD, GPIO_PIN_14);
				state_flag[2] = !state_flag[2];
				if (state_flag[2]) {
					HAL_UART_Transmit(&huart3, (uint8_t *)"Red - ON\r\n", 10, 10);
				} else {
					HAL_UART_Transmit(&huart3, (uint8_t *)"Red - OFF\r\n", 11, 10);
				}
				break;
			case 0x42: case 0x62:
				HAL_GPIO_TogglePin(GPIOD, GPIO_PIN_15);
				state_flag[3] = !state_flag[3];
				if (state_flag[3]) {
					HAL_UART_Transmit(&huart3, (uint8_t *)"Blue - ON\r\n", 11, 10);
				} else {
					HAL_UART_Transmit(&huart3, (uint8_t *)"Blue - OFF\n", 12, 10);
				}
				break;
			default:
				HAL_UART_Transmit(&huart3, (uint8_t *)"Unexpected cmd\r\n", 16, 10);
				break;
		}
}

