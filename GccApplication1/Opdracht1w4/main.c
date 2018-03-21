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

void init(){
	
	ADMUX = 0b11100000;

	ADCSRA = 0b11100110;
}

int main(void)
{
    DDRF = 0x00;

	DDRA = 0xFF;
	DDRB = 0xFF;

	init();

    while (1) 
    {
		PORTA = ADCL;
		PORTB = ADCH;

		_delay_ms(100);
    }
}

