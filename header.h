//Headerguards
#ifndef HEADER_H_
#define HEADER_H_

#define F_CPU 16000000UL //Klockfrekvens på 16MHz.

//Inkluderar de nödvändiga bibliotek jag behöver.
#include <avr/io.h>        /* Innehåller information om I/O-register såsom DDRB och PORTB. */
#include <avr/interrupt.h> /* Innehåller information om avbrottsvektorer såsom PCINT0_vect. */
#include <util/delay.h> /* Innehåller information om delay mm. */

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

#define LED1_ON PORTB |= (1 << LED1) // Tänder lysdiod 1 
#define LED2_ON PORTB |= (1 << LED2) // Tänder lysdiod 2 
#define LED3_ON PORTB |= (1 << LED3) // Tänder lysdiod 3 

#define LED1_OFF PORTB &= ~(1 << LED1) // Släcker lysdiod 1
#define LED2_OFF PORTB &= ~(1 << LED2) // Släcker lysdiod 2
#define LED3_OFF PORTB &= ~(1 << LED3) // Släcker lysdiod 3

#define LEDS_ON PORTB |= (1 << LED1) | (1 << LED2) | (1 << LED3)     //Tänder lysdioderna
#define LEDS_OFF PORTB &= ~((1 << LED1) | (1 << LED2) | (1 << LED3)) //Släcker lysdioderna

#define BUTTON1_IS_PRESSED (PINB & (1 << BUTTON1)) //Indikerar nedtryckning av knapp 1
#define BUTTON2_IS_PRESSED (PINB & (1 << BUTTON2)) //Indikerar nedtryckning av knapp 2
#define BUTTON3_IS_PRESSED (PINB & (1 << BUTTON3)) //Indikerar nedtryckning av knapp 3

#define BUTTON4_IS_PRESSED (PIND & (1 << BUTTON4)) //Indikerar nedtryckning av knapp 4 (Reset)
#define BUTTON5_IS_PRESSED (PIND & (1 << BUTTON5)) //Indikerar nedtryckning av knapp 5

/********************************************************************************
* bool: Datatyp som indikerar sant eller falskt. Denna datatyp är vanlig i
*       flertalet programmeringsspråk. I C utgör bool dock inte en primitiv
*       datatyp, men kan implementeras via en enumeration som här eller via
*       inkludering av standardbiblioteket stdbool.h (för C99 och senare).
********************************************************************************/
typedef enum { false, true } bool;

//State: Datatyp för lagring av dörrens aktuella tillstånd.

enum state { STATE_OFF, STATE_SLOW, STATE_MEDIUM, STATE_FAST, STATE_ON };
	
extern enum state diod; 

/********************************************************************************
* setup: Initierar mikrodatorn vid start.
********************************************************************************/
void setup(void);

/********************************************************************************
* fsm_reset: Återställer dörren till startläget, vilket är öppet tillstånd.
*            Lysdioderna uppdateras därefter (endast lysdiod 1 hålls tänd).
********************************************************************************/
void fsm_reset(void);

/********************************************************************************
* fsm_uppdate: Uppdaterar dörrens tillstånd utefter aktuellt tillstånd samt
*              vilken tryckknapp som trycks ned.
********************************************************************************/
void fsm_update(void);

void fsm_set_output(void);
void blink_slow();
void blink_medium();
void blink_fast();

#endif //HEADER_H_