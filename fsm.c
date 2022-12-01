#include "header.h"

//Hade kunnat använda statiska funktioner men valde att inte använda det.

void fsm_reset(void)
{
	diod = STATE_OFF;
	LEDS_OFF;
	return;
}

void fsm_update(void)
{
	switch(diod) 
	
	{
		case STATE_OFF:
		{
			if(BUTTON2_IS_PRESSED)
			{
				diod = STATE_SLOW;
			}
			else if(BUTTON3_IS_PRESSED)
			{
				diod = STATE_MEDIUM;
			}
			else if(BUTTON1_IS_PRESSED)
			{
				diod = STATE_ON;
			}
			else if(BUTTON5_IS_PRESSED)
			{
				diod = STATE_FAST;
			}
			break;
		}
		case STATE_ON:
		{
			if(BUTTON2_IS_PRESSED)
			{
				diod = STATE_OFF;
			}
			else if(BUTTON3_IS_PRESSED)
			{
				diod = STATE_SLOW;
			}
			else if(BUTTON1_IS_PRESSED)
			{
				diod = STATE_FAST;
			}
			else if(BUTTON5_IS_PRESSED)
			{
				diod = STATE_MEDIUM;
			}
			break;
		}
		
		case STATE_SLOW:
		{
			if(BUTTON2_IS_PRESSED)
			{
				diod = STATE_MEDIUM;
			}
			else if(BUTTON3_IS_PRESSED)
			{
				diod = STATE_FAST;
			}
			else if(BUTTON1_IS_PRESSED)
			{
				diod = STATE_OFF;
			}
			else if(BUTTON5_IS_PRESSED)
			{
				diod = STATE_ON;
			}
			break;
		}
		
		case STATE_MEDIUM:
		{
			if(BUTTON2_IS_PRESSED)
			{
				diod = STATE_FAST;
			}
			else if(BUTTON3_IS_PRESSED)
			{
				diod = STATE_ON;
			}
			else if(BUTTON1_IS_PRESSED)
			{
				diod = STATE_SLOW;
			}
			else if(BUTTON5_IS_PRESSED)
			{
				diod = STATE_OFF;
			}
			break;
		}
		
		case STATE_FAST:
		{
			if(BUTTON2_IS_PRESSED)
			{
				diod = STATE_ON;
			}
			else if(BUTTON3_IS_PRESSED)
			{
				diod = STATE_OFF;
			}
			else if(BUTTON1_IS_PRESSED)
			{
				diod = STATE_MEDIUM;
			}
			else if(BUTTON5_IS_PRESSED)
			{
				diod = STATE_SLOW;
			}
			break;
		}
	}
	
}

void fsm_set_output(void)
{
	
	if (diod == STATE_OFF) LEDS_OFF;
	else if (diod == STATE_ON) LEDS_ON;
	else if (diod == STATE_SLOW) blink_slow();
	else if (diod == STATE_MEDIUM) blink_medium();
	else if (diod == STATE_FAST) blink_fast();
	
	else fsm_reset();
	
	
	return;
}