//this code to control shift register cd4094
//create function to define port and pins
//create function to send data

//PD7 for strobe
//PD5 for data
//PD6 for clock

#include "SHIFT.h"


/*In this code, we first define the pins that we will be using to control the shift register. 
 We then define a function called shiftOut that will simulate the SPI signals by manually shifting out each bit of the data byte using the clock and data pins.
 In the main function, 
 we first initialize the pins and then send some data to the shift register using the shiftOut function. 
 We then wait for a bit using the _delay_ms function, and send some more data to the shift register. 
 Finally, we reset the output by setting the latch pin low, sending a byte of zeros to the shift register, and then setting the latch pin high.

 Note that this is just a basic example, and you may need to modify the code to suit your specific needs. 
 For example, you may need to adjust the clock speed or the data format depending on your shift register's requirements.*/


// Initialize pins
void shiftInit(void) {
	 DDRD |= (1 << DIS_CLK_PIN) | (1 << SR_DATA_PIN) | (1 << SR_LATCH_PIN); //set PORTD.6 & PORTD.5 & PORTD.7 as output
	 DDRC |= (1 << LCD_CLK_PIN) | (1 << INC_CLK_PIN) | (1 << EXC_CLK_PIN); //set PORTC.1 & PORTD.2 & PORTD.3 as output
	 PORTD &= ~(1 << DIS_CLK_PIN) | (1 << SR_DATA_PIN) | (1 << SR_LATCH_PIN);
	 PORTC &= ~(1 << LCD_CLK_PIN) | (1 << INC_CLK_PIN) | (1 << EXC_CLK_PIN);
}
// Function to shift out LCD data through shift register
void lcd_shiftOut(uint8_t data) {
	// Shift out the data byte
	for (uint8_t i = 0; i < 8; i++) {
		if (data & (1 << i)) {
			PORTD |= (1 << SR_DATA_PIN);
			} else {
			PORTD &= ~(1 << SR_DATA_PIN);
		}
		
		PORTC |=(1 << LCD_CLK_PIN);         
		PORTC &= ~(1 << LCD_CLK_PIN);
	}
	
	// Set latch pin high
	PORTD |= (1 << SR_LATCH_PIN);
}

void dis_shiftOut(uint8_t data){
	// Shift out the data byte
	for (uint8_t i = 0; i < 8; i++) {
		if (data & (1 << i)) {
			PORTD |= (1 << SR_DATA_PIN);
			} else {
			PORTD &= ~(1 << SR_DATA_PIN);
		}
		
		PORTD |= (1 << DIS_CLK_PIN);
		PORTD &= ~(1 << DIS_CLK_PIN);
	}
	
	// Set latch pin high
	PORTD |= (1 << SR_LATCH_PIN);
}

void lcd_shiftReset(void) {
	PORTD &= ~(1 << SR_LATCH_PIN);
}

void inc_shiftOut(uint8_t data){
	for (uint8_t i = 0; i < 8; i++) {
		if (data & (1 << i)) {
			PORTD |= (1 << SR_DATA_PIN);
			} else {
			PORTD &= ~(1 << SR_DATA_PIN);
		}
		
		PORTC |= (1 << INC_CLK_PIN);
		PORTC &= ~(1 << INC_CLK_PIN);
	}
	
	// Set latch pin high
	PORTD |= (1 << SR_LATCH_PIN);
}
void exc_shiftOut(uint8_t data){
	for (uint8_t i = 0; i < 8; i++) {
		if (data & (1 << i)) {
			PORTD |= (1 << SR_DATA_PIN);
			} else {
			PORTD &= ~(1 << SR_DATA_PIN);
		}
		
		PORTC |= (1 << EXC_CLK_PIN);
		PORTC &= ~(1 << EXC_CLK_PIN);
	}
	
	// Set latch pin high
	PORTD |= (1 << SR_LATCH_PIN);
}





