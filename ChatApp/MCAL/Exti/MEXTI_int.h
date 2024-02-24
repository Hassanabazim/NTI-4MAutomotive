/*
 * MEXTI_int.h
 *
 *  Created on: Jun 7, 2023
 *      Author: Hassa
 */


#ifndef MEXTI_MEXTI_INT_H_
#define MEXTI_MEXTI_INT_H_

typedef enum
{
	MEXTI_INT0_ID = 6,
	MEXTI_INT1_ID = 7,
	MEXTI_INT2_ID = 5
}MEXTI_ID_t;

typedef enum
{
	MEXTI_LOW_LEVEL = 0,
	MEXTI_ANY_CHANGE = 1,
	MEXTI_FAILING_EDGE = 2,
	MEXTI_RISING_EDGE = 3,
}MEXTI_Trigger_t;


void MEXTI_enEnable(MEXTI_ID_t copy_u8IntID, MEXTI_Trigger_t copy_u8IntTrig);
void MEXTI_enDisable(MEXTI_ID_t copy_u8IntID);
void MEXTI_enSetCalBack(MEXTI_ID_t copy_u8IntID, void(*ptrfn)(void));

#define  EXT_INT_0 __vector_1
#define  EXT_INT_1 __vector_2
#define  EXT_INT_2 __vector_3


//ISR definition
#define ISR(INT_VECT)void INT_VECT(void) __attribute__ ((signal,used));\
void INT_VECT(void)

#endif /* MEXTI_MEXTI_INT_H_ */
