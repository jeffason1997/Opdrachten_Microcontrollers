/*
 * Opdracht1W3.c
 *
 * Created: 4-3-2018 19:37:02
 * Author : jeffr
 */ 

#define F_CPU 8000000

#include <avr/io.h>
#include <util/delay.h>

#include <stdio.h>
#include <stdlib.h>

#include "lcd.h"

 static char text[] = "J.Lantinga";

int main(void)
{
    DDRD = 0xFF;
    DDRC = 0xFF;
    PORTC = 0x00;
    /* Replace with your application code */
    
    init();
    display_clear();
	set_cursor(0);
    display_text(text);

    while (1)
    {
	   
    }
    
    return 0;
}