/*
 * DIO.h
 *
 * Created: 4/6/2023 2:41:22 PM
 *  Author: Ahmed Adel
 */ 


#ifndef DIO_H_
#define DIO_H_

#define F_CPU 8000000UL
#include <avr/io.h>
#include <util/delay.h>
#include <stdint.h>

void portInit(void);


#endif /* DIO_H_ */