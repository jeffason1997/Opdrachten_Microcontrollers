/*
 * Opdracht4w2.c
 *
 * Created: 21-2-2018 21:09:47
 * Author : jeffr
 */ 

 #define F_CPU 8000000
#include <avr/io.h>
#include <util/delay.h>

void wait( int ms )
{
	for (int i=0; i<ms; i++)
	{
		_delay_ms( 1 );		// library function (max 30 ms at 8MHz)
	}
}

typedef struct { 
	unsigned char data;
	unsigned int delay ;
} PATTERN_STRUCT; 

PATTERN_STRUCT pattern[] = { 
	{0x40,100}, {0x02,200},{0x01,200},{0x20,200},{0x40,200},{0x04,200},{0x08,200},{0x10,200},{0x40,100},{0x00,0}
};

PATTERN_STRUCT pattern2[] = {
	{0x01,100},{0x22,200},{0x40,200},{0x14,200},{0x08,200},{0x14,200},{0x40,200},{0x22,200},{0x01,100},{0x00,0}
};

int main(void)
{
	DDRD=0xFF;
	PORTD = 0x00;
    /* Replace with your application code */
    while (1) 
    {
		int times1 = 0;
		while (times1!=2)
		{
			int index = 0;
			while( pattern[index].delay != 0 ) 
			{
				PORTD = pattern[index].data;
				wait(pattern[index].delay);
				index++;
			}
		times1++;
		}
		int times2 = 0;
		 while (times2!=2){
			int index2 = 0;
			while( pattern2[index2].delay!=0)
			{
				PORTD = pattern2[index2].data;
				wait(pattern2[index2].delay);
				index2++;
			}
			times2++;
		}
	}
}
// 0b00000001		streepje boven			0x01	1
// 0b00000010		streepje rechtsboven	0x02	2
// 0b00000100		streepje rechtsonder	0x04	4
// 0b00001000		streepje onder			0x08	8
// 0b00010000		streepje linksonder		0x10	16
// 0b00100000		streepje linksboven		0x20	32
// 0b01000000		streepje midden			0x40	64


