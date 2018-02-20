/*
 * Opdracht2.c
 *
 * Created: 20-2-2018 11:38:46
 * Author : jeffr
 */ 
 #define F_CPU 8000000 

#include <avr/io.h>
#include <util/delay.h>
#define  BIT(x)  (1<<(x))


int main(void)
{
	DDRD = 0xFF;
	DDRC = 0x00;
    /* Replace with your application code */
    while (1) 
    {
		if(PINC == 0x01){
			PORTD |= BIT(7);
		} else {
			PORTD &= ~BIT(7);
		}
		_delay_ms(30);
    }
	return 1;
}

