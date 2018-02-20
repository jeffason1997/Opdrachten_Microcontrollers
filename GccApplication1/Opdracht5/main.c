/*
 * Opdracht5.c
 *
 * Created: 20-2-2018 13:13:20
 * Author : jeffr
 */ 

#define F_CPU 8000000		//this is 8MHz

#include <avr/io.h>
#include <util/delay.h>
#define  BIT(x)  (1<<(x))

enum speed {slow,normal,fast};

void wait(int ms){
	for (int i=0; i<ms; i++)
	{
		_delay_ms( 1 );		// library function (max 30 ms at 8MHz)
	}
}

int main(void)
{
	DDRB= 0x00;
	DDRD= 0b11111111;
	DDRA= 0b11111111;
	int i=0;
	int spe = slow;
	//PORTA=0b11000000;

	while (1)
	{
		if(PINC == 0x01){
			switch(spe){
				case slow: spe = normal; break;
				case normal: spe = fast;break;
				case fast: spe = slow;break;
			}
		}
		int delay=0;
		switch(spe){
			case slow: PORTA= 0b10000000; delay =500;break;
			case normal: PORTA= 0b11000000; delay =250;break;
			case fast: PORTA= 0b11100000; delay =125;break;
			};
		
		PORTD^=(BIT(4));
		wait(delay);
	}
	return 1;
}

