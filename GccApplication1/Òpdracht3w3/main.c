/*
 * Òpdracht3w3.c
 *
 * Created: 4-3-2018 22:08:01
 * Author : jeffr
 */ 

#define F_CPU 8000000
#include <avr/io.h>
#include <avr/delay.h>
#include <avr/interrupt.h>

int counter = 0;

int main(void)
{
	DDRB = 0xFF;
	DDRC = 0xFF;
	DDRD = 0xFF;
	
	TCNT2 = 0;
	OCR2 = 125;
	TIMSK |= (1 << 7);
	SREG |= (1 << 7);
	TCCR2 = 0b00001011;
	sei();

	while (1)
	{
		
	}
}


ISR( TIMER2_COMP_vect )
{
	counter++;
	if(counter == 2500) {
		PORTD = 0x80;
		counter = 0;
	} else if(counter == 1500) {
		PORTD = 0x00;
		}
}