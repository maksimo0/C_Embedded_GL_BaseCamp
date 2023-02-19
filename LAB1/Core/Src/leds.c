/*
 * leds.c
 *
 *  Created on: Feb 18, 2023
 *      Author: mkdjs
 */

#include "leds.h"

extern led_t leds[];

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

void led_stop()
{
	for (uint8_t i = 0; i < LEDS_QUANTITY; i++) {
		led_write(&leds[i], 0);
	}
}
