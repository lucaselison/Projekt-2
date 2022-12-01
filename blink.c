#include "header.h"

//Funktionsdeklarationer för slow, medium och fast blink.

void blink_slow()
{
	if(diod == STATE_SLOW)
	{
		LED3_OFF;
		LED1_ON;
		_delay_ms(500);
		LED1_OFF;
		LED2_ON;
		_delay_ms(500);
		LED2_OFF;
		LED3_ON;
		_delay_ms(500);
		
		return;
	}
}

void blink_medium()
{
	if(diod == STATE_MEDIUM)
	{
		LED3_OFF;
		LED1_ON;
		_delay_ms(250);
		LED1_OFF;
		LED2_ON;
		_delay_ms(250);
		LED2_OFF;
		LED3_ON;
		_delay_ms(250);
		
		return;
	}
}

void blink_fast()
{
	if(diod == STATE_FAST)
	{
		LED3_OFF;
		LED1_ON;
		_delay_ms(50);
		LED1_OFF;
		LED2_ON;
		_delay_ms(50);
		LED2_OFF;
		LED3_ON;
		_delay_ms(50);
		
		return;
	}
}