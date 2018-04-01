/*
 * Opdracht1w4.c
 *
 * Created: 21-3-2018 19:26:32
 * Author : jeffr
 */ 

 #define F_CPU 8000000

#include <avr/io.h>
#include <util/delay.h>
#include <avr/interrupt.h>

void wait( int ms )
{
	for (int tms=0; tms<ms; tms++)
	{
		_delay_ms( 1 );
	}
}

int main(void){
DDRA = 0xFF;
DDRB = 0xFF;
DDRF = 0x00;

ADMUX = 0b01100011;
ADCSRA = 0b11100110;

/* Replace with your application code */
	while (1)
	{
		PORTB = ADCL;
		PORTA = ADCH;
	}
}

