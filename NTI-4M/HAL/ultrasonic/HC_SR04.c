
/*
 * HC_SR04.c
 *
 * Created: 9/24/2023 11:40:00 PM
 *  Author: pc.Nagdy
 */ 
#define F_CPU 16000000UL
#include <avr/delay.h>
#include "../../../NTI-4M/HAL/ultrasonic/HC_SR04.h"
#include "std_types.h"
#include <avr/io.h>
#include <avr/interrupt.h>

volatile u16 echo_count,echo_count1,echo_time_us,distance_cm;
volatile u8 flagecho;
void HC_SR04_Init(void)
{
	dio_vidConfigChannel(trigger_port, trigger_pin, OUTPUT);
	dio_vidConfigChannel(ECO_port, ECO_pin, INPUT);
}
void trigger_pulse(void)
{
	dio_vidWriteChannel(trigger_port, trigger_pin, STD_HIGH);
	_delay_us(10);
	dio_vidWriteChannel(trigger_port, trigger_pin, STD_LOW);
}

u16 HC_SR04_get_distance(void)
{
	TCNT1=0;
	echo_count=0;
	echo_count1=0;
	flagecho=0;
	trigger_pulse();
	sei();
	TCCR1B |=(1<<ICES1);
	TCCR1B |=((1<<CS11)|(1<<CS10));
	TIMSK |=(1<<TICIE1);
	_delay_ms(40);
	echo_time_us =((64*1000000)/F_CPU)*echo_count;
	distance_cm = echo_time_us/58;
	return distance_cm;
	
}

ISR(TIMER1_CAPT_vect)
{
	
	if (flagecho==0)
	{
		TCCR1B &=~(1<<ICES1);
		echo_count1=ICR1;
		flagecho=1;
	}
		else
	{
		echo_count=ICR1-echo_count1;
		TCCR1B &=~((1<<CS11)|(1<<CS10));
		TIMSK &=~(1<<TICIE1);
		cli();
	}
	}
	