/*
 * SHIFT.h
 *
 * Created: 4/6/2023 2:45:18 PM
 *  Author: Ahmed Adel
 */ 


#ifndef SHIFT_H_
#define SHIFT_H_
#include "../../MCAL/DIO/DIO.h"
#include "../7SEG/_7seg.h"
#include "../CALLS/CALLS.h"

// Define pins
#define DIS_CLK_PIN PD6    //set PORTD.6 as  display clock pin
#define LCD_CLK_PIN PC1    // set PORTC.1 as lcd clock pin
#define INC_CLK_PIN PC2    // set PORTC.2 as internal calls clock pin
#define EXC_CLK_PIN PC3    // set PORTC.3 as external calls clock pin
#define SR_DATA_PIN PD5   //set PORTD.5 as data pin
#define SR_LATCH_PIN PD7  //set PORTD.7 as latch pin


void shiftInit(void);         //use to initialize pins as output
void lcd_shiftOut(uint8_t data); //to shift out data to lcd 
void inc_shiftOut(uint8_t data); //to shift out data to internal calls
void exc_shiftOut(uint8_t data); //to shift out data to external calls
void dis_shiftOut(uint8_t data); //to shift out data to display 
void shiftReset(void);


#endif /* SHIFT_H_ */