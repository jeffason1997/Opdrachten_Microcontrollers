/*
 * Opdracht4.c
 *
 * Created: 20-2-2018 12:03:44
 * Author : jeffr
 */ 
#define F_CPU 8000000

#include <avr/io.h>
#include <util/delay.h>


void wait(int ms){
	for (int i=0; i<ms; i++)
	{
		_delay_ms( 1 );		// library function (max 30 ms at 8MHz)
	}
}

typedef struct { 	   // struct to capsulize a pattern
	int bits;	// given bit configuration for the leds
	int row;   // given row configuration for the row of the leds
	int delay;  // delay in ms
} PATTERN;

PATTERN pattern[] = { // Animation of patterns, step by step
	{0b10000001, 0, 300}, {0b01000010, 1, 100}, {0b00100100, 2, 100},
	{0b00101000, 3, 100}, {0b00010000, 2, 100}, {0b00100100, 1, 100}, {0b01000010, 0, 300},
	{0b00000000, 10, 0}
};

void choiseLed(int i, int c){
	if(pattern[i].row == 0 ){
		PORTA = pattern[c].bits;
		PORTD = pattern[c].bits;
	} else if (pattern[i].row == 1){
		PORTB = pattern[c].bits;
		PORTC = pattern[c].bits;
	} else if (pattern[i].row == 2){
		PORTC = pattern[c].bits;
		PORTB = pattern[c].bits;
	} else if (pattern[i].row == 3){
		PORTD = pattern[c].bits;
		PORTA = pattern[c].bits;
	}
}

int main( void )
{

	DDRA = 0xFF;				// All pins PORTA to PORTD are set to output
	DDRB = 0xFF;
	DDRC = 0xFF;
	DDRD = 0xFF;
	int i = 0;
	int dir = 0;
	while (1)
	{	
		if( pattern[i].delay == 300 ) {  
			if (dir!=1){ dir=1;} 
			else{ dir=-1;}
		}
		choiseLed(i,i);
		wait(pattern[i].delay);   
		choiseLed(i,7);
		i+=dir;
	}

	return 1;
}