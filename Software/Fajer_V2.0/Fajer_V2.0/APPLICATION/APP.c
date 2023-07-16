/*
 * APP.c
 *
 * Created: 4/6/2023 2:52:23 PM
 *  Author: Ahmed Adel
 */ 
 
#include "APP.h"

void checking(void){
	//initializing
	lcd_init();
	//reset lcd and calls signals
	
	//welcome screen with testing calls signals and 7 segment
	lcd_command(0x01); //clear display
	lcd_command(0x80); // Set cursor at the beginning of the first line
	lcd_string("Empironics"); // Display a string on the LCD
	PORTC |=(1 << 1);          //clock for lcd
	PORTC &= ~(1 << 1);
	for(uint8_t i=0; i<15; i++)
	{
		_delay_ms(50);
		inc_shiftOut(callsNumber[i]);
		exc_shiftOut(callsNumber[i]);
		dis_shiftOut(sevenSegment[i]);
	}
}  
void appStart(){
	//shaftSignal();	
	/*here the main application sequence
	************************************
	1- initialize all outputs and inputs
	2- reset lcd and calls signals 
	3- welcome screen with testing calls signals and 7 segment
	& check programming mode and enter it if active
	4- load saved data in eeprom
	5- display current floor and shaft status
	6- check if inspection state is not active run in inspection mode 
	7- check calls input and record calls then if safety is o.k run the elevator according to specific direction
	*/

	
	
	//checking programming mode 
	//if programming switch is active then go to programming mode 
	if(!(PINA & (1 << Enter)))
	{
		_delay_ms(500);
		program();
	}
}