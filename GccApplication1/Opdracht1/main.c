/*
 * Opdracht1.c
 *
 * Created: 20-2-2018 10:54:05
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
	DDRD= 0b11111111;
	PORTD^=BIT(6);


    while (1) 
    {
		PORTD^=(BIT(7)|BIT(6));
		wait( 500 );
	
    }
	return 1;
}

