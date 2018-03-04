/*
 * lcd.c
 *
 * Created: 4-3-2018 19:37:54
 *  Author: jeffr
 */ 

#define F_CPU 8000000

#include <avr/io.h>
#include <avr/delay.h>
#include <string.h>
#include "lcd.h"

void init() {
	// return home
	lcd_command( 0x02 );
	// mode: 4 bits interface data, 2 lines, 5x8 dots
	lcd_command( 0x28 );
	// display: on, cursor off, blinking off
	lcd_command( 0x0c );
	// entry mode: cursor to right, no shift
	lcd_command( 0x06 ); //was 0x06
	// RAM adress: 0, first position, line 1
	lcd_command( 0x80 );
}

void display_text(char *str) {
	_delay_ms(1);
	for(int i = 0; i < strlen(str); i++) {
		lcd_writeChar(str[i]);
	}
}

void set_cursor(int pos){
	_delay_ms(1);
	for(int i = 0; i < pos; i++) {
		lcd_command(0b00010100);
	}
}

void display_clear() {
	_delay_ms(1);
	lcd_command(0x01);
}

void lcd_writeChar( unsigned char dat )
{
	PORTC = dat & 0xF0;			// hoge nibble
	PORTC = PORTC | 0x0C;		// data (RS=1),
								// start (EN=1)
	_delay_ms(1);				// wait 1 ms
	PORTC = 0x04;				// stop (EN = 0)
	PORTC = (dat & 0x0F) << 4;	// lage nibble
	PORTC = PORTC | 0x0C;		// data (RS=1),
								// start (EN=1)
	_delay_ms(1);				// wait 1 ms
	PORTC = 0x00;				// stop
								// (EN=0 RS=0)
}

void lcd_command ( unsigned char dat )
{
	PORTC = dat & 0xF0;			// hoge nibble
	PORTC = PORTC | 0x08;		// data (RS=0),
								// start (EN=1)
	_delay_ms(1);				// wait 1 ms
	PORTC = 0x04;				// stop (EN = 0)
	PORTC = (dat & 0x0F) << 4;	// lage nibble
	PORTC = PORTC | 0x08;		// data (RS=0),
								// start (EN=1)
	_delay_ms(1);				// wait 1 ms
	PORTC = 0x00;				// stop
								// (EN=0 RS=0)
}