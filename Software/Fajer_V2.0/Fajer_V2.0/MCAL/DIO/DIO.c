/*
 * DIO.c
 *
 * Created: 4/6/2023 2:41:10 PM
 *  Author: Ahmed Adel
 */ 
 #include "DIO.h"

 void portInit(){
	DDRB = 0xFF; // movement pins as outputs
 }