/*
 * MOV.h
 *
 * Created: 4/20/2023 4:56:32 AM
 *  Author: Ahmed Adel
 */ 


#ifndef MOV_H_
#define MOV_H_
#include "../../MCAL/DIO/DIO.h"

#define PhN PB0
#define Lamp PB1
#define Star PB2
#define Cam PB3
#define Up PB4
#define Down PB5
#define Slow PB6
#define Fast PB7
#define Delta PC0


void moveUP(void);
void moveDOWN(void);
void moveSLOW(void);
void moveFAST(void);
void light(void);
void arrowUP(void);
void arrowdown(void);
void moveTEST(uint8_t relay);



#endif /* MOV_H_ */