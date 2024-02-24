/*
 * HC_SR04.h
 *
 * Created: 9/24/2023 7:27:13 PM
 *  Author: pc.Nagdy
 */ 


#ifndef HC_SR04_H_
#define HC_SR04_H_
#include "dio.h"
#define trigger_port   DIO_PORTC  //PORTB,PORTC,PORTD
#define ECO_port       DIO_PORTD  //PORTB,PORTC,PORTD
#define trigger_pin    5    //0 ----> 7
#define ECO_pin        6    //0 ----> 7

void HC_SR04_Init(void);
void trigger_pulse(void);
u16 HC_SR04_get_distance(void);

#endif /* HC_SR04_H_ */
