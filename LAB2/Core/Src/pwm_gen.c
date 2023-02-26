/*
 * pwm_gen.c
 *
 *  Created on: Feb 26, 2023
 *      Author: mkdjs
 */

#include "pwm_gen.h"

#define TIM4_FREQ	4000000

extern TIM_HandleTypeDef htim4;

volatile uint8_t duty = 5;
volatile uint8_t freq = 5;
volatile uint8_t signal_flag = 0;

void tim4_init()
{
	 TIM4->ARR = (uint32_t)((TIM4_FREQ / (freq * 1000)) - 1);
	 TIM4->CCR1 = (uint32_t)((50 * ((TIM4->ARR) + 1)) / 100);
	 HAL_TIM_PWM_Start(&htim4, TIM_CHANNEL_1);
}

void pwm_gen_stop()
{
	HAL_TIM_PWM_Stop(&htim4, TIM_CHANNEL_1);
	HAL_TIM_PWM_Stop(&htim4, TIM_CHANNEL_2);
	HAL_TIM_PWM_Stop(&htim4, TIM_CHANNEL_3);
	HAL_TIM_PWM_Stop(&htim4, TIM_CHANNEL_4);
}

void pwm_gen_process()
{
	pwm_gen_stop();
	TIM4->ARR = (uint32_t)((TIM4_FREQ / (freq * 1000)) - 1);
	switch (signal_flag)
		  {
		  	  case 0x0:
		  		  TIM4->CCR1 = (uint32_t)(((duty) * ((TIM4->ARR) + 1)) / 100);
		  		  HAL_TIM_PWM_Start(&htim4, TIM_CHANNEL_1);
		  		  break;
		  	  case 0x1:
		  		  TIM4->CCR2 = (uint32_t)(((duty) * ((TIM4->ARR) + 1)) / 100);
		  		  HAL_TIM_PWM_Start(&htim4, TIM_CHANNEL_2);
		  		  break;
		  	  case 0x2:
		  		  TIM4->CCR3 = (uint32_t)(((duty) * ((TIM4->ARR) + 1)) / 100);
		  		  HAL_TIM_PWM_Start(&htim4, TIM_CHANNEL_3);
		  		  break;
		  	  case 0x3:
		  		  TIM4->CCR4 = (uint32_t)(((duty) * ((TIM4->ARR) + 1)) / 100);
		  		  HAL_TIM_PWM_Start(&htim4, TIM_CHANNEL_4);
		  		  break;
		  	  case 0x4:
		  		  pwm_gen_stop();
		  		  break;
		  	  default:
		  		  break;
		  }
}


