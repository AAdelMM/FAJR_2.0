/*
 * _7seg.c
 *
 * Created: 4/8/2023 11:55:11 PM
 *  Author: Ahmed Adel
 */ 
#include "./_7seg.h"

 unsigned char sevenSegment[20] = {

	 //0b11000000, //0 negative
	 0b00111111, //0 positive
	 //0b11111001, //1 negative
	 0b00000110, //1 positive
	 //0b10100100, //2 negative
	 0b01011011, //2 positive
	 //0b10110000, //3 negative
	 0b01001111, //3 positive
	 //0b10011001, //4 negative
	 0b01100110, //4 positive
	 //0b10010010, //5 negative
	 0b01101101, //5 positive
	 //0b10000010, //6 negative
	 0b01111101, //6 positive
	 //0b11111000, //7 negative
	 0b00000111, //7 positive
	 //0b10000000, //8 negative
	 0b01111111, //8 positive
	 //0b10010000, //9 negative
	 0b01101111, //9 positive
	 //0b01000000, //10 negative
	 0b10111111, //10 positive
	 //0b01111001, //11 negative
	 0b10000110, //11 positive
	 //0b00100100, //12 negative
	 0b11011011, //12 positive
	 //0b00110000, //13 negative
	 0b11001111, //13 positive
	 //0b00011001, //14 negative
	 0b11100110, //14 positive
	 //0b00010010, //15 negative
	 0b11101101, //15 positive
	 //0b00000010, //16 negative
	 0b11111101, //16 positive
	 //0b01111000, //17 negative
	 0b10000111, //17 positive
	 //0b00000000, //18 negative
	 0b11111111, //18 positive
	 //0b00010000, //19 negative
	 0b11101111, //19 positive
 };
