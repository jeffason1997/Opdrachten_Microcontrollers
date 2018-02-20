/**
 * \file
 *
 * \brief Empty user application template
 *
 */

/**
 * \mainpage User Application template doxygen documentation
 *
 * \par Empty user application template
 *
 * Bare minimum empty user application template
 *
 * \par Content
 *
 * -# Include the ASF header files (through asf.h)
 * -# "Insert system clock initialization code here" comment
 * -# Minimal main function that starts with a call to board_init()
 * -# "Insert application code here" comment
 *
 */

/*
 * Include header files for all drivers that have been imported from
 * Atmel Software Framework (ASF).
 */
/*
 * Support and FAQ: visit <a href="http://www.atmel.com/design-support/">Atmel Support</a>
 */
#include <asf.h>
#include <util/delay.h>
#define BIT(x)	(1<<(x))

void wait( int ms )

{
	for (int i=0; i<ms; i++)
	{
		_delay_ms( 1 );		// library function (max 30 ms at 8MHz)
	}
}

void opdracht1(){
	DDRD= 0b11111111;
	
	PORTD^=(BIT(7)|BIT(6));
}

void opdracht2(){
	DDRC = 0b00000000;
	
	if(PORTC.BIT == 0){
		PORTD = 0xFF;
	} else {
		PORTD = 0x00;
	}
}

void ToCall(){
	opdracht2();
}

int main (void)
{
	/* Insert system clock initialization code here (sysclk_init()). */
	
	while(1){
		ToCall();
		wait(500);
	}

	/* Insert application code here, after the board has been initialized. */
}
