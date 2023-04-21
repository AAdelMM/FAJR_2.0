/*
 * APP.c
 *
 * Created: 4/6/2023 2:52:23 PM
 *  Author: Ahmed Adel
 */ 
 
#include "APP.h"
 
   
void appStart(){
  	 shiftInit();
	 lcd_init(); // Initialize the LCD
	  uint8_t i=0;
	  //application main loop
	  while (1) {
		  
		  lcd_command(0x80); // Set cursor at the beginning of the first line
		  lcd_string("Empironics..."); // Display a string on the LCD
		  //PORTD |= (1 << SR_CLK_PIN);
		  PORTC |=(1 << 1);          //clock for lcd
		  //PORTD &= ~(1 << SR_CLK_PIN);
		  PORTC &= ~(1 << 1);
		  _delay_ms(1000); // Wait for 1 second
		  
		  //lcd_command(0xC0); // Set cursor at the beginning of the second line
		  lcd_set_cursor(1,5);
		  lcd_number(i);
		  dis_shiftOut(sevenSegment[i]);
		  if(i>7){
			exc_shiftOut(callsNumber[i-8]);
			inc_shiftOut(0);
		  }else{
			inc_shiftOut(callsNumber[i]);
			exc_shiftOut(0);
		  }
		 moveTEST(i);
		  
		//  lcd_string("Ahmed"); // Display another string on the LCD
		  _delay_ms(1000); // Wait for 1 second
		  lcd_command(0x01);
		  _delay_ms(1000);
		  
		  
		  i++;
		  if(i>15){
			i = 0;
		  }
		//  PORTC |=(1 << DIS_CLK_PIN);
		 // dis_shiftOut(sevenSegment[2]);
		  
	  }
}