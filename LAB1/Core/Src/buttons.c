/*
 * buttons.c
 *
 *  Created on: Feb 19, 2023
 *      Author: mkdjs
 */

#include "buttons.h"
#include "leds.h"

extern volatile uint8_t speed_flag;
extern volatile uint8_t scheme_flag;
extern volatile uint8_t start_stop_flag;

void swt1()
{
	if (speed_flag < 3) {
		led_stop();
		speed_flag++;
	}
}

void swt2()
{
	start_stop_flag = (start_stop_flag == 0) ? 1 : 0;
}

void swt3()
{
	if (speed_flag > 1) {
		led_stop();
		speed_flag--;
	}
}

void swt4()
{
	led_stop();
	if (scheme_flag < 3) {
		scheme_flag++;
		if (scheme_flag == 3) {
			scheme_flag = 0;
		}
	}
}

void swt5()
{
	led_stop();
	if (scheme_flag >= 0) {
		scheme_flag--;
		if (scheme_flag == 255) {
			scheme_flag = 2;
		}
	}
}

