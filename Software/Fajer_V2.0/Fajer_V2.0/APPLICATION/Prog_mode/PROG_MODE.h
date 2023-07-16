/*
 * PROG_MODE.h
 *
 * Created: 4/22/2023 8:42:24 AM
 *  Author: Ahmed Adel
 */ 


#ifndef PROG_MODE_H_
#define PROG_MODE_H_

#include "../../ECUAL/LCD/LCD.h"
#include "../../MCAL/DIO/DIO.h"

#define Enter PA0
#define plus PA1
#define mins PA2
uint8_t pSelect;
void program(void); //main programming mode function
void parameterSelect(uint8_t pSelect); //function to select which parameter to change
void doorMode(void); // p0
void displayType(void); // p1
void lightTimer(void); // p2
void doorNumber(void); // p3
void callCollective(void); // p4
void inspSpeed(void); // p5
//missing programming function here // p6
void dopTimer(void); // p7
void dclTimer(void); // p8
void waitTimer(void); // p9
void slowTimer(void); // p10
void fastTimer(void); // p11
void lockError(void); // p12
void camTimer(void); // p13
void camTrials(void); // 14
void timeOut(void); // p15
void setPassword(void); // p16
void correction(void); // p17
//uint8_t *pSelect = 0;

//char Program_list[20][16] = {"Door Mode", "Display mode", "Light Time", "Door Number" };
uint8_t p;

#endif /* PROG_MODE_H_ */