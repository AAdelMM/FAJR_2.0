/*
 * SHAFT_COLL.c
 *
 * Created: 4/22/2023 8:40:53 AM
 *  Author: Ahmed Adel
 */ 

 /*In this module we send A B C D signal to multiplexer to get output that indicate which input is active.*/
 
 #include "SHAFT_COLL.h"
 /*Make function to send input name and return back value if on or off..*/
 /*We have A B C D ports if we send binary 1 then we can read first input */
 unsigned char muxData[15] = {S,SUP,SDN,MTR,SAF,DOP,DCL,FIRE,FRK,LOC,UPL,DNL,SLIP,};

 int shaftSignal(void)
{
	
	 init_mux();
	 shiftInit();
	 lcd_init(); // Initialize the LCD
	 DDRC &= ~(1 << Shaft_input); // assign pinc6 as input
	 DDRD &= ~(1 << STP) & ~(1 << SEL);
	 PORTC |= (1 << Shaft_input); // enable pull up resistor
	 
	 uint8_t shaftInputValue = (PINC & (1 << PINC6)) >> PINC6; //save reading pin value in variable
	 while (1) 
	 {
		 // Select channel 3 of the multiplexer
		 for(int i=0; i<15; i++)
		 {
			 _delay_ms(50);
			 set_mux_channel(i);
			 if(!(MUX_OUTPUT_PIN & (1 << MUX_OUTPUT_BIT))) //reading input pin if not high mean low signal
			 {
				 switch(i)
				 {
					 case 0:
					 lcd_command(0x01); //clear display
					 lcd_command(0x80); // Set cursor at the beginning of the first line
					 lcd_string("Inspection"); // Display a string on the LCD
					 PORTC |=(1 << 1);          //clock for lcd
					 PORTC &= ~(1 << 1);
					 break;
					 case 1:
					 lcd_command(0x01); //clear display
					 lcd_command(0x80); // Set cursor at the beginning of the first line
					 lcd_string("InsUp"); // Display a string on the LCD
					 PORTC |=(1 << 1);          //clock for lcd
					 PORTC &= ~(1 << 1);
					 break;
					 case 2:
					 lcd_command(0x01); //clear display
					 lcd_command(0x80); // Set cursor at the beginning of the first line
					 lcd_string("InsDN"); // Display a string on the LCD
					 PORTC |=(1 << 1);          //clock for lcd
					 PORTC &= ~(1 << 1);
					 break;
					 case 3:
					 lcd_command(0x01); //clear display
					 lcd_command(0x80); // Set cursor at the beginning of the first line
					 lcd_string("Overload"); // Display a string on the LCD
					 PORTC |=(1 << 1);          //clock for lcd
					 PORTC &= ~(1 << 1);
					 break;
					 case 4:
					 lcd_command(0x01); //clear display
					 lcd_command(0x80); // Set cursor at the beginning of the first line
					 lcd_string("AUX"); // Display a string on the LCD
					 PORTC |=(1 << 1);          //clock for lcd
					 PORTC &= ~(1 << 1);
					 break;
					 case 5:
					 lcd_command(0x01); //clear display
					 lcd_command(0x80); // Set cursor at the beginning of the first line
					 lcd_string("DOP"); // Display a string on the LCD
					 PORTC |=(1 << 1);          //clock for lcd
					 PORTC &= ~(1 << 1);
					 break;
					 case 6:
					 lcd_command(0x01); //clear display
					 lcd_command(0x80); // Set cursor at the beginning of the first line
					 lcd_string("DCL"); // Display a string on the LCD
					 PORTC |=(1 << 1);          //clock for lcd
					 PORTC &= ~(1 << 1);
					 break;
					 case 7:
					 lcd_command(0x01); //clear display
					 lcd_command(0x80); // Set cursor at the beginning of the first line
					 lcd_string("FIRE"); // Display a string on the LCD
					 PORTC |=(1 << 1);          //clock for lcd
					 PORTC &= ~(1 << 1);
					 break;
					 case 8:
					 lcd_command(0x01); //clear display
					 lcd_command(0x80); // Set cursor at the beginning of the first line
					 lcd_string("FRK"); // Display a string on the LCD
					 PORTC |=(1 << 1);          //clock for lcd
					 PORTC &= ~(1 << 1);
					 break;
					 case 9:
					 lcd_command(0x01); //clear display
					 lcd_command(0x80); // Set cursor at the beginning of the first line
					 lcd_string("LOC"); // Display a string on the LCD
					 PORTC |=(1 << 1);          //clock for lcd
					 PORTC &= ~(1 << 1);
					 break;
					 case 10:
					 lcd_command(0x01); //clear display
					 lcd_command(0x80); // Set cursor at the beginning of the first line
					 lcd_string("UPL"); // Display a string on the LCD
					 PORTC |=(1 << 1);          //clock for lcd
					 PORTC &= ~(1 << 1);
					 break;
					 case 11:
					 lcd_command(0x01); //clear display
					 lcd_command(0x80); // Set cursor at the beginning of the first line
					 lcd_string("DNL"); // Display a string on the LCD
					 PORTC |=(1 << 1);          //clock for lcd
					 PORTC &= ~(1 << 1);
					 break;
					 case 12:
					 lcd_command(0x01); //clear display
					 lcd_command(0x80); // Set cursor at the beginning of the first line
					 lcd_string("SLIP"); // Display a string on the LCD
					 PORTC |=(1 << 1);          //clock for lcd
					 PORTC &= ~(1 << 1);
					 break;
					 case 13:
					 lcd_command(0x01); //clear display
					 lcd_command(0x80); // Set cursor at the beginning of the first line
					 lcd_string("MTR"); // Display a string on the LCD
					 PORTC |=(1 << 1);          //clock for lcd
					 PORTC &= ~(1 << 1);
					 break;
					 case 14:
					 lcd_command(0x01); //clear display
					 lcd_command(0x80); // Set cursor at the beginning of the first line
					 lcd_string("Safety ok"); // Display a string on the LCD
					 PORTC |=(1 << 1);          //clock for lcd
					 PORTC &= ~(1 << 1);
					 break;
				 }

			 }
		 }
		 if(!(SEL_PIN & (1 << SEL))) //reading input pin if not high mean low signal
		 {
			lcd_command(0x01); //clear display
			lcd_command(0x80); // Set cursor at the beginning of the first line
			lcd_string("SEL"); // Display a string on the LCD
			PORTC |=(1 << 1);          //clock for lcd
			PORTC &= ~(1 << 1);
		 }
		 if(!(STP_PIN & (1 << STP))) //reading input pin if not high mean low signal
		 {
			 lcd_command(0x01); //clear display
			 lcd_command(0x80); // Set cursor at the beginning of the first line
			 lcd_string("LEVEL"); // Display a string on the LCD
			 PORTC |=(1 << 1);          //clock for lcd
			 PORTC &= ~(1 << 1);
		 }
		 
		 // Do something with the selected channel
	 }
	
 }

	
void init_mux() {
	MUX_CTRL_DDR |= (1 << PA4) | (1 << PA5) | (1 << PA6) | (1 << PA7);
	// Set pins PA4-PA7 as output pins for the multiplexer control
}

void set_mux_channel(uint8_t channel) {
	//MUX_CTRL_PORT &= ~(1 << PA4); // Set the first control pin LOW
	PORTA &= ~(1 << A) & ~(1 << B) & ~(1 << C) & ~(1 << D);
	MUX_CTRL_PORT |= (((channel ) & 0x0F) << 4); // Set the remaining control pins according to the desired channel
}