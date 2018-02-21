/*
 * Opdracht2w2.c
 *
 * Created: 21-2-2018 21:40:00
 * Author : jeffr
 */ 


#define F_CPU 8000000

#include <avr/io.h>
#include <util/delay.h>
#include <avr/interrupt.h>

ISR( INT1_vect )
{
	PORTA = PORTA << 1;
}

ISR( INT2_vect )
{
	PORTA = PORTA >> 1;
}


int main( void )
{
	DDRD = 0x00;	
	DDRA = 0xFF;
	PORTA= 0x00;	

	EICRA |= 0x3C;			// INT1 Led goes down, INT2 Led goes up
	EIMSK |= 0x06;			// Enable INT1 & INT2
	
	sei();
	
	PORTC = 0x01;

	while (1)
	{

	}

	return 1;
}

