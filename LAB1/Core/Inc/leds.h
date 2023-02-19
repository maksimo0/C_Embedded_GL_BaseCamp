/*
 * leds.h
 *
 *  Created on: Feb 18, 2023
 *      Author: mkdjs
 */

#ifndef INC_LEDS_H_
#define INC_LEDS_H_

#include "stm32f4xx_hal.h"

#define LEDS_QUANTITY	4

typedef struct {
	uint32_t cnt;
	uint32_t period;
	uint32_t pulse;
	GPIO_TypeDef *port;
	uint16_t pin;
} led_t;

void led_init(led_t *led, uint32_t period, uint32_t pulse, uint32_t pin);
void led_write(led_t *led, GPIO_PinState state);
void led_stop();

#endif /* INC_LEDS_H_ */
