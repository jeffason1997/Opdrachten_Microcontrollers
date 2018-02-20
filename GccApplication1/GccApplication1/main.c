/*
 * GccApplication1.c
 *
 * Created: 20-2-2018 08:51:09
 * Author : jeffr
 */ 

#include <avr/io.h>
#include <util/delay.h>
#define BIT(x)	(1<<(x))	

void wait (int ms){
	for (int i=0; i<ms; i++)
	{
		_delay_ms( 1 );		// library function (max 30 ms at 8MHz)
	}
}

int main(void)
{
	
	DDRD = 0b11111111;
	PORTD = 0xFF;
	int i=0;
	
    /* Replace with your application code */
    while (1) 
    {
		if(i==0){
		PORTD ^= (BIT(i));
		} else {
			PORTD ^= (BIT(i-1)|BIT(i));
		}
		i++;
		wait( 500 );
    }
}

