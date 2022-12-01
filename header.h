//Headerguards
#ifndef HEADER_H_
#define HEADER_H_

#define F_CPU 16000000UL //Klockfrekvens p� 16MHz.

//Inkluderar de n�dv�ndiga bibliotek jag beh�ver.
#include <avr/io.h>        /* Inneh�ller information om I/O-register s�som DDRB och PORTB. */
#include <avr/interrupt.h> /* Inneh�ller information om avbrottsvektorer s�som PCINT0_vect. */
#include <util/delay.h> /* Inneh�ller information om delay mm. */

//Definerar de olika lysdioderna samt var de sitter.
#define LED1 PORTB0 
#define LED2 PORTB1 
#define LED3 PORTB2 

//Definerarar de olika knapparna samt var de sitter.
#define BUTTON1 PORTB3 
#define BUTTON2 PORTB4 
#define BUTTON3 PORTB5 

#define BUTTON4 PORTD2 //Reset
#define BUTTON5 PORTD3

#define LED1_ON PORTB |= (1 << LED1) // T�nder lysdiod 1 
#define LED2_ON PORTB |= (1 << LED2) // T�nder lysdiod 2 
#define LED3_ON PORTB |= (1 << LED3) // T�nder lysdiod 3 

#define LED1_OFF PORTB &= ~(1 << LED1) // Sl�cker lysdiod 1
#define LED2_OFF PORTB &= ~(1 << LED2) // Sl�cker lysdiod 2
#define LED3_OFF PORTB &= ~(1 << LED3) // Sl�cker lysdiod 3

#define LEDS_ON PORTB |= (1 << LED1) | (1 << LED2) | (1 << LED3)     //T�nder lysdioderna
#define LEDS_OFF PORTB &= ~((1 << LED1) | (1 << LED2) | (1 << LED3)) //Sl�cker lysdioderna

#define BUTTON1_IS_PRESSED (PINB & (1 << BUTTON1)) //Indikerar nedtryckning av knapp 1
#define BUTTON2_IS_PRESSED (PINB & (1 << BUTTON2)) //Indikerar nedtryckning av knapp 2
#define BUTTON3_IS_PRESSED (PINB & (1 << BUTTON3)) //Indikerar nedtryckning av knapp 3

#define BUTTON4_IS_PRESSED (PIND & (1 << BUTTON4)) //Indikerar nedtryckning av knapp 4 (Reset)
#define BUTTON5_IS_PRESSED (PIND & (1 << BUTTON5)) //Indikerar nedtryckning av knapp 5

/********************************************************************************
* bool: Datatyp som indikerar sant eller falskt. Denna datatyp �r vanlig i
*       flertalet programmeringsspr�k. I C utg�r bool dock inte en primitiv
*       datatyp, men kan implementeras via en enumeration som h�r eller via
*       inkludering av standardbiblioteket stdbool.h (f�r C99 och senare).
********************************************************************************/
typedef enum { false, true } bool;

//State: Datatyp f�r lagring av d�rrens aktuella tillst�nd.

enum state { STATE_OFF, STATE_SLOW, STATE_MEDIUM, STATE_FAST, STATE_ON };
	
extern enum state diod; 

/********************************************************************************
* setup: Initierar mikrodatorn vid start.
********************************************************************************/
void setup(void);

/********************************************************************************
* fsm_reset: �terst�ller d�rren till startl�get, vilket �r �ppet tillst�nd.
*            Lysdioderna uppdateras d�refter (endast lysdiod 1 h�lls t�nd).
********************************************************************************/
void fsm_reset(void);

/********************************************************************************
* fsm_uppdate: Uppdaterar d�rrens tillst�nd utefter aktuellt tillst�nd samt
*              vilken tryckknapp som trycks ned.
********************************************************************************/
void fsm_update(void);

void fsm_set_output(void);
void blink_slow();
void blink_medium();
void blink_fast();

#endif //HEADER_H_