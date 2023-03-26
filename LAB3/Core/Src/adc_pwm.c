/*
 * adc_pwm.c
 *
 *  Created on: Mar 12, 2023
 *      Author: mkdjs
 */

#include "adc_pwm.h"

void tim4_init()
{
	 TIM4->ARR = (uint32_t)((TIM4_FREQ / (5 * 1000)) - 1);
	 TIM4->CCR1 = (uint32_t)((0 * ((TIM4->ARR) + 1)) / 100);
	 TIM4->CCR2 = (uint32_t)((0 * ((TIM4->ARR) + 1)) / 100);
	 TIM4->CCR4 = (uint32_t)((0 * ((TIM4->ARR) + 1)) / 100);
	 HAL_TIM_PWM_Start(&htim4, TIM_CHANNEL_1);
	 HAL_TIM_PWM_Start(&htim4, TIM_CHANNEL_2);
	 HAL_TIM_PWM_Start(&htim4, TIM_CHANNEL_4);
}

uint32_t adc_val = 0;
uint8_t emerg_flag[3] = {0, 0, 0};
volatile HAL_StatusTypeDef adc_poll_res;

void adc_ch_read()
{
	HAL_ADC_Start(&hadc1);
	adc_poll_res = HAL_ADC_PollForConversion(&hadc1, 100);
	if (adc_poll_res == HAL_OK) {
		adc_val = HAL_ADC_GetValue(&hadc1);
		//TIM4->CCR1 = (uint32_t)(((adc_val * 100 / 4095) * ((TIM4->ARR) + 1)) / 100);
		if (adc_val < 1700 /*&& emerg_flag[0] != 1*/) {
			if (emerg_flag[0] != 1) {
				emerg_flag[0] = 1;
			}
			TIM4->CCR1 = (uint32_t)(((3500 * 100 / 4095) * ((TIM4->ARR) + 1)) / 100);
		} else if (adc_val >= 1700 /*&& emerg_flag[0] != 0*/) {
			if (emerg_flag[0] != 0) {
				emerg_flag[0] = 0;
			}
			TIM4->CCR1 = (uint32_t)(((100 * 100 / 4095) * ((TIM4->ARR) + 1)) / 100);
		}
	}
	HAL_ADC_Start(&hadc1);
	adc_poll_res = HAL_ADC_PollForConversion(&hadc1, 100);
	if (adc_poll_res == HAL_OK) {
		adc_val = HAL_ADC_GetValue(&hadc1);
		//TIM4->CCR2 = (uint32_t)(((adc_val * 100 / 4095) * ((TIM4->ARR) + 1)) / 100);
		if (adc_val > 1000 /*&& emerg_flag[1] != 1*/) {
			if (emerg_flag[1] != 1) {
				emerg_flag[1] = 1;
			}
			TIM4->CCR2 = (uint32_t)(((3500 * 100 / 4095) * ((TIM4->ARR) + 1)) / 100);
		} else if (adc_val <= 1000 /*&& emerg_flag[1] != 0*/) {
			if (emerg_flag[1] != 0) {
				emerg_flag[1] = 0;
			}
			TIM4->CCR2 = (uint32_t)(((100 * 100 / 4095) * ((TIM4->ARR) + 1)) / 100);
		}
	}
	HAL_ADC_Start(&hadc1);
	adc_poll_res = HAL_ADC_PollForConversion(&hadc1, 100);
	if (adc_poll_res == HAL_OK) {
		adc_val = HAL_ADC_GetValue(&hadc1);
		TIM4->CCR4 = (uint32_t)(((adc_val * 100 / 4095) * ((TIM4->ARR) + 1)) / 100);
		if (adc_val > 3500 && emerg_flag[2] != 1) {
			emerg_flag[2] = 1;
		} else if (adc_val <= 3450 && emerg_flag[2] != 0) {
			emerg_flag[2] = 0;
		}
	}
	HAL_ADC_Stop(&hadc1);
}

uint32_t last_time = 0;

void emergency()
{
	uint8_t emerg = emerg_flag[0] + emerg_flag[1] + emerg_flag[2];
	if (emerg) {
		switch (emerg)
		{
			case 0x1:
				if (HAL_GetTick() - last_time > 500) {
					last_time = HAL_GetTick();
					HAL_GPIO_TogglePin(GPIOD, GPIO_PIN_14);
				}
				break;
			case 0x2:
				if (HAL_GetTick() - last_time > 200) {
					last_time = HAL_GetTick();
					HAL_GPIO_TogglePin(GPIOD, GPIO_PIN_14);
				}
				break;
			case 0x3:
				if (HAL_GetTick() - last_time > 100) {
					last_time = HAL_GetTick();
					HAL_GPIO_TogglePin(GPIOD, GPIO_PIN_14);
				}
				break;
			default:
				HAL_GPIO_WritePin(GPIOD, GPIO_PIN_14, GPIO_PIN_RESET);
				break;
		}
	} else {
		HAL_GPIO_WritePin(GPIOD, GPIO_PIN_14, GPIO_PIN_RESET);
	}
}
