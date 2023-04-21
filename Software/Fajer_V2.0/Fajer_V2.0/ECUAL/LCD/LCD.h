/*
 * LCD.h
 *
 * Created: 4/6/2023 2:43:16 PM
 *  Author: Ahmed Adel
 */ 


#ifndef LCD_H_
#define LCD_H_
#include "../../MCAL/DIO/DIO.h"
#include "../SHIFT_REGISTER/SHIFT.h"


#define LCD_PORT PORTD //LCD data port
#define LCD_RS PD4 //LCD RS pin
#define LCD_EN PA3 //LCD EN pin

void lcd_init(void); //assign lcd pinout
void lcd_command(unsigned char cmd); //to send lcd commands
void lcd_data(unsigned char data); //to send data via lcd data pins
void lcd_string(char *str); // to display string 
void lcd_number(int num); // to display numbers
void lcd_set_cursor(uint8_t row, uint8_t col); // to set cursor position

#endif /* LCD_H_ */