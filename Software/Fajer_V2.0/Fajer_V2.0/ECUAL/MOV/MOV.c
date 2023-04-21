/*
 * MOV.c
 *
 * Created: 4/20/2023 4:56:49 AM
 *  Author: Ahmed Adel
 */ 

 #include "MOV.h"
 

 

 void moveTEST(uint8_t relay){
	DDRC |= (1 << Delta);
	DDRB = 0xFF; // movement pins as outputs
	if(relay > 8){
		PORTB = 0x00;
		PORTC &= ~(1 << Delta);
	}
	switch (relay)
	{
		case 0:
			PORTB = 0x00;
			PORTC &= ~(1<< Delta);
			PORTB |= (1 << Lamp);
			break;
		case 1:
			PORTB = 0x00;
			PORTB |= (1 << Cam);
			break;
		case 2:
			PORTB = 0x00;
			PORTB |= (1 << Fast);
			break;
		case 3:
			PORTB = 0x00;
			PORTB |= (1 << Slow);
			break;
		case 4:
			PORTB = 0x00;
			PORTB |= (1 << PhN);
			PORTB |= (1 << Down);
			break;
		case 5:
			PORTB = 0x00;
			PORTB |= (1 << PhN);
			PORTB |= (1 << Up);
			break;
		case 6:
			PORTB = 0x00;
			PORTB |= (1 << PhN);
			break;
		case 7:
			PORTB = 0x00;
			PORTB |= (1 << Star);
			break;
		case 8:
			PORTB = 0x00;
			PORTC |= (1 << Delta);
			break;
		default:
			PORTB = 0x00;
			PORTC &= (1 << Delta);
	}
 }