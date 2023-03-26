/*
 * adc_pwm.h
 *
 *  Created on: Mar 12, 2023
 *      Author: mkdjs
 */

#ifndef INC_ADC_PWM_H_
#define INC_ADC_PWM_H_

#include "stm32f4xx_hal.h"

#define TIM4_FREQ	4000000

extern ADC_HandleTypeDef hadc1;
extern TIM_HandleTypeDef htim4;

void tim4_init();
void adc_ch_read();
void emergency();

#endif /* INC_ADC_PWM_H_ */
