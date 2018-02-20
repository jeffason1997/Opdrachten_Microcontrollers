/*
 * Opdracht3.c
 *
 * Created: 20-2-2018 11:50:18
 * Author : jeffr
 */ 

#define F_CPU 8000000		//this is 8MHz

#include <avr/io.h>
#include <util/delay.h>
#define  BIT(x)  (1<<(x))



void wait(int ms){
	for (int i=0; i<ms; i++)
	{
		_delay_ms( 1 );		// library function (max 30 ms at 8MHz)
	}
}

int main(void)
{
	DDRD = 0b11111111;
	int i = 0b00000001;					
	int down = 0;		//0 is down, 1 is up

    while (1) 
    {
		PORTD = i;				
		
		if(i & 0b00000001) {
			down = 0;
		}			
		
		if(i & 0b10000000) { 
			down = 1;
		}			
		
		if(down == 0) { 
			i = i << 1;
		} else { 
			i = i >> 1;
		}			
		
		wait( 50 );
    }
}

