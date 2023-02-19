/*
 * leds.c
 *
 *  Created on: Feb 18, 2023
 *      Author: mkdjs
 */

#include "leds.h"

void led_init(led_t *led, uint32_t period, uint32_t pulse, uint32_t pin)
{
	led->period	= period;
	led->pulse	= pulse;
	led->port	= GPIOD;
	led->pin	= (0x0001 << pin);
}

void led_write(led_t *led, GPIO_PinState state)
{
	HAL_GPIO_WritePin(led->port, led->pin, state);
}
