/*
 * buttons.c
 *
 *  Created on: Feb 19, 2023
 *      Author: mkdjs
 */

#include "buttons.h"

extern volatile uint8_t duty;
extern volatile uint8_t freq;
extern volatile uint8_t signal_flag;

void swt1()
{
	if (duty > 0) {
		duty -=5;
	}
}

void swt2()
{
	if (signal_flag < 5) {
		signal_flag++;
		if (signal_flag == 5) {
			signal_flag = 0;
		}
	}
}

void swt3()
{
	if (duty < 100) {
		duty += 5;
	}
}

void swt4()
{
	if (freq < 50) {
		freq += 5;
	}
}

void swt5()
{
	if (freq > 5) {
		freq -= 5;
	}
}

void HAL_GPIO_EXTI_Callback(uint16_t GPIO_Pin)
{
	pwm_gen_process();
}

