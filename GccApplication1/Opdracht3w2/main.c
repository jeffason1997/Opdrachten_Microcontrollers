/*
 * Opdracht3w2.c
 *
 * Created: 21-2-2018 21:44:47
 * Author : jeffr
 */ 

 #define F_CPU 8000000
#include <avr/io.h>
#include <util/delay.h>
// 0b00000001		streepje boven
// 0b00000010		streepje rechtsboven
// 0b00000100		streepje rechtsonder
// 0b00001000		streepje onder
// 0b00010000		streepje linksonder
// 0b00100000		streepje linksboven
// 0b01000000		streepje midden
const unsigned char Numbers[17] = {
	0b00111111,	//0		
	0b00000110,	//1
	0b01011011,	//2
	0b01001111,	//3
	0b01100110,	//4
	0b01101101,	//5
	0b01111101,	//6
	0b00000111,	//7
	0b01111111,	//8
	0b01101111,	//9
	0b01110111,	//A
	0b01111100,	//b
	0b00111001,	//C
	0b01011110,	//d
	0b01111001,	//E
	0b01110001	//F
}; 

void display(int digit){
	if(digit>15){
		PORTD = 0b01111001;
	} else {
		PORTD = Numbers[digit];
	}
}

int main(void)
{
	int i = 0;
	DDRD=0xFF;
	DDRC=0x00;
    while (1) 
    {
		if(PINC == 0x01 && i<16)	{ i++;}
		else if (PINC==0x02 && i!=0)	{ i--;}
		display(i);
		_delay_ms(300);
    }
}

