/*
 * SHAFT_COLL.h
 *
 * Created: 4/22/2023 8:41:10 AM
 *  Author: Ahmed Adel
 */ 


#ifndef SHAFT_COLL_H_
#define SHAFT_COLL_H_

#include "../../MCAL/DIO/DIO.h"
#define A PA4 //S0
#define B PA5 //S1
#define C PA6 //S2
#define D PA7 //S3
#define S 0
#define SUP 1
#define SDN 2
#define OW 3
#define AUX 4
#define DOP 5
#define DCL 6
#define FIRE 7
#define FRK 8
#define LOC 9
#define UPL 10
#define DNL 11
#define SLIP 12
#define MTR 13
#define SAF 14
#define MUX_CTRL_PORT PORTA
#define MUX_CTRL_DDR DDRA
#define MUX_OUTPUT_PIN PINC
#define MUX_OUTPUT_BIT PC6

#define SEL PD3
#define SEL_PIN PIND
#define STP PD2
#define STP_PIN PIND
#define Shaft_input PC6


unsigned char muxData[15] ;
uint8_t shaftInputValue;

int shaftSignal(void);
void sendMuxData(uint8_t *mux);
void init_mux(void);
void set_mux_channel(uint8_t channel);



#endif /* SHAFT_COLL_H_ */