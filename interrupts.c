#include "header.h"

ISR (PCINT0_vect)
{
	{
	if(BUTTON1_IS_PRESSED || BUTTON2_IS_PRESSED || BUTTON3_IS_PRESSED)fsm_update();
	fsm_update();
	return;
	}
}
	
ISR (INT0_vect)
{
	fsm_reset();
	return;
}

ISR (INT1_vect)
{
	if(BUTTON5_IS_PRESSED)fsm_update();
	return;
}