#include "header.h"

/* Statiska funktioner: */
static inline void init_ports(void);
static inline void init_interrupts(void);

enum state diod = STATE_OFF;

void setup(void)
{
	init_ports();
	init_interrupts();
	fsm_reset();
	return;
}


static inline void init_ports()
{
	DDRB = (1 << LED1) | (1 << LED2) | (1 << LED3);
	PORTB = (1 << BUTTON1) | (1 << BUTTON2) | (1 << BUTTON3);
	PORTD = (1 << BUTTON4) | (1 << BUTTON5);
	return;
}

static inline void init_interrupts()
{
	sei();
	PCICR = (1 << PCIE0);
	PCMSK0 = (1 << BUTTON1) | (1 << BUTTON2) | (1 << BUTTON3);
	
	EICRA = (1 << ISC00) | (1 << ISC01);
	EIMSK = (1 << INT0) | (1 << INT1);
}