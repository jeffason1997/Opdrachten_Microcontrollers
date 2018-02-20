/*
 * Opdracht6.c
 *
 * Created: 20-2-2018 14:25:41
 * Author : jeffr
 */ 

#define F_CPU 8000000

#include <avr/io.h>
#include <util/delay.h>


enum STATES {START, S1, S2, S3, END};
enum BUTTON {PoD5, PoD6, PoD7};

void stateHandler(int*, int);

int main(void)
{
	DDRA = 0xFF;
	DDRB = 0xFF;
	DDRC = 0xFF;
	DDRD = 0x00;
	int currentState = START;
    
    while (1) 
    {
		if(PIND & 0x20){
			stateHandler(&currentState, PoD5);
		} else if (PIND & 0x40){
			stateHandler(&currentState, PoD6);
		} else if (PIND & 0x80){
			stateHandler(&currentState, PoD7);
		}

		switch(currentState){
			case START: PORTA = 0x17; PORTB = 0x15; PORTC = 0x1D;
			break;
			case S1: PORTA = 0x12; PORTB = 0x1F; PORTC = 0x10;
			break;
			case S2: PORTA = 0x1D; PORTB = 0x15; PORTC = 0x17;
			break;
			case S3: PORTA = 0x15; PORTB = 0x15; PORTC = 0xF1F;
			break;
			case END: PORTA = 0x1F; PORTB = 0x15; PORTC = 0x15;
			break;
		}

		_delay_ms(500);

    }
}

void stateHandler(int* state, int button){

	switch(*state){
		case START: 
			switch(button){
				case PoD5: *state = S2; break;
				case PoD6: *state = S3; break;
			}
			break;

		case S1:
			switch(button){
				case PoD5: *state = S2; break;
				case PoD7: *state = START; break;
			}
			break;

		case S2:
			switch(button){
				case PoD5: *state = S3; break;
				case PoD6: *state = S1; break;
				case PoD7: *state = START; break;
			}
			break;

		case S3:
			switch(button){
				case PoD5: *state = END; break;
				case PoD6: *state = END; break;
				case PoD7: *state = START; break;
			}
			break;

		case END:
			switch(button){
				case PoD7: *state = START; break;
			}
			break;
	}
}

