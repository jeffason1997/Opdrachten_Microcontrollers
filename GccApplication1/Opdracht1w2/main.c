/*
 * Opdracht1w2.c
 *
 * Created: 21-2-2018 20:00:06
 * Author : jeffr
 */ 
 #define F_CPU 8000000
#include <avr/io.h>
#include <util/delay.h>
#include <avr/interrupt.h>


/******************************************************************/
void wait( int ms )
{
	for (int i=0; i<ms; i++)
	{
		_delay_ms( 1 );		// library function (max 30 ms at 8MHz)
	}
}


ISR( INT0_vect )
{
    PORTD ^= (1<<6);		
}

ISR( INT1_vect )
{
    PORTD ^= (1<<5);		
}

int main( void )
{
	// Init I/O
	DDRD = 0xF0;			// PORTD(7:4) output, PORTD(3:0) input	

	// Init Interrupt hardware
	EICRA = 0x0B;			// INT1 falling edge, INT0 rising edge
	EIMSK = 0x03;			// Enable INT1 & INT0
	SREG |= 0x80;
	
	sei();				

	while (1)
	{
		//PORTD ^= (1<<7);	// Toggle PORTD.7
		//wait( 500 );								
	}

	return 1;
}
