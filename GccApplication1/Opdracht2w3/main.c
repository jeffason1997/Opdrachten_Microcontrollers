/*
 * Opdracht2w3.c
 *
 * Created: 4-3-2018 20:57:37
 * Author : jeffr
 */ 

#define F_CPU 8000000
#include <avr/io.h>
#include <avr/delay.h>
#include <avr/interrupt.h>
#include "lcd.h"

static char text[] = "Pushed: ";
int pushed = 0;
int pushedTen = 0;

int main(void)
{
	DDRB = 0xFF;
	DDRC = 0xFF;
	DDRD = 0x00;
	
	TCNT2 = -1;
	TIMSK |= (1 << 6);
	SREG |= (1 << 7);
	TCCR2 = 0b0000111;
	sei();
	
	PORTC = 0x00;
	
	init();
	display_clear();
	displayUpdate();
	while (1)
	{
		
	}
	
	return 0;
}


ISR ( TIMER2_OVF_vect ) {
	if(pushed<9){
	pushed++;
	} else {
	pushed = 0;
	pushedTen++;
	updateText();
	}
	displayUpdate();
	TCNT2 = -1;
}

void displayUpdate() {
	display_clear();
	display_text(text);
	lcd_writeChar(pushed+'0');
}

void updateText(){
	text[8]=pushedTen+'0';
}