/*
 * pwm_gen.h
 *
 *  Created on: Feb 26, 2023
 *      Author: mkdjs
 */

#ifndef INC_PWM_GEN_H_
#define INC_PWM_GEN_H_

#include "stm32f4xx_hal.h"

void tim4_init();

void pwm_gen_stop();
void pwm_gen_process();

#endif /* INC_PWM_GEN_H_ */
