/*
 * uart_control.h
 *
 *  Created on: Mar 18, 2023
 *      Author: mkdjs
 */

#ifndef INC_UART_CONTROL_H_
#define INC_UART_CONTROL_H_

#include "stm32f4xx_hal.h"
#include <string.h>
#include <stdio.h>

#define TIM4_FREQ	4000000

extern ADC_HandleTypeDef hadc1;
extern UART_HandleTypeDef huart3;

void ext_temp_sensor();
void uart();

#endif /* INC_UART_CONTROL_H_ */
