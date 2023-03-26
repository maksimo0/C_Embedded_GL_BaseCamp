/*
 * buttons.h
 *
 *  Created on: Feb 19, 2023
 *      Author: mkdjs
 */

#ifndef INC_BUTTONS_H_
#define INC_BUTTONS_H_

#include "stm32f4xx_hal.h"
#include "pwm_gen.h"

void swt1();
void swt2();
void swt3();
void swt4();
void swt5();

void HAL_GPIO_EXTI_Callback(uint16_t GPIO_Pin);

#endif /* INC_BUTTONS_H_ */
