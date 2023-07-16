/*
 * LCD.c
 *
 * Created: 4/6/2023 2:43:32 PM
 *  Author: Ahmed Adel
 */ 
 #include "./LCD.h"
 #include <stdio.h>

 void lcd_init(void)
 {
	//set LCD data port as output
	//LCD_PORT = 0x00; // use it when lcd connected directly
	DDRD |= (1 << LCD_RS); 
	DDRA |= (1 << LCD_EN); 
	PORTA &= ~(1 << LCD_EN); //set PA3 low
	shiftInit();
	//wait for LCD to power up
	_delay_ms(100);

	// send initialization commands to LCD

	lcd_command(0x38); //8-bit mode, 2-line display, 5*8 font
	lcd_command(0x0C); // Display on, cursor off, blink off
	lcd_command(0x01); //clear display
	lcd_command(0x06); //increment cursor, no shift 
	
 }

 void lcd_command(unsigned char cmd) //sending commands to LCD to control enable and disable it
 {
	
	//LCD_PORT = cmd; //to pass data to LCD
	lcd_shiftOut(cmd);
	PORTD &= ~(1 << LCD_RS); //set RS pin low for command mode
	PORTA |= (1 << LCD_EN); //set EN high to enable LCd
	_delay_ms(10);
	PORTA &= ~(1 << LCD_EN); //set EN low to disable LCD
	_delay_us(50);
 }

 void lcd_data(unsigned char data)
 {
	//LCD_PORT = data; //send data using whole port
	lcd_shiftOut(data); //send data using shift register
	PORTD |= (1 << LCD_RS); //set RS high for data mode
	PORTA |= (1 << LCD_EN); // Set EN pin high to enable LCD
	_delay_us(10);
	PORTA &= ~(1 << LCD_EN); // Set EN pin low to disable LCD
	_delay_us(50);
 }

 void lcd_string(char *str)
 {
	while(*str)
	{
		lcd_data(*str++);
	}
 }
 void lcd_number(int num) {
	 // Display an integer number on the LCD
	 char str[16];
	 sprintf(str, "%d", num);

	 for (int i = 0; i < 16; i++) {
		 if (str[i] == '\0') {
			 break; // End of string
		 }
		 lcd_data(str[i]);
	 }
 }
 // set cursor position row,col row value 0,1
 void lcd_set_cursor(uint8_t row, uint8_t col) {
	 // Set the cursor position to the specified row and column
	 if (row == 0) {
		 // Set the DDRAM address for the first row
		 lcd_command(0x80 + col);
		 } else if (row == 1) {
		 // Set the DDRAM address for the second row
		 lcd_command(0x80 + 0x40 + col);
	 }
 }

 /*Example
 
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
 */