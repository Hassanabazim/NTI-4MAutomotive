/*
 * MEXTI_prog.c
 *
 *  Created on: Jun 7, 2023
 *      Author: Hassa
 */


#include "std_types.h"
#include "bit_math.h"
#include "MEXTI_int.h"
#include "MEXTI_priv.h"

void (*callBackArr[3])(void) = {NULL, NULL, NULL};

void MEXTI_enEnable(MEXTI_ID_t copy_u8IntID, MEXTI_Trigger_t copy_u8IntTrig)
{
	switch (copy_u8IntID)
	{
	case MEXTI_INT0_ID:
		// APPLY MASK
		MCUCR_REG &= MEXTI_INT0_SC_MASK;
		// Insert Value
		MCUCR_REG |= copy_u8IntTrig;
		break;
	case MEXTI_INT1_ID:
		MCUCR_REG &= MEXTI_INT1_SC_MASK;
		MCUCR_REG |= copy_u8IntTrig << MEXTI_INT1_SC_SH;
		break;
	case MEXTI_INT2_ID:
		CLEAR_BIT(MCUCSR_REG,ISC2_BIT);
		MCUCSR_REG |= CHECK_BIT(copy_u8IntTrig,0) << ISC2_BIT;
		break;

	}
	SET_BIT(GICR_REG,copy_u8IntID);
}


void MEXTI_enDisable(MEXTI_ID_t copy_u8IntID)
{

	if (copy_u8IntID >= MEXTI_INT2_ID && copy_u8IntID <= MEXTI_INT1_ID)
	{
		CLEAR_BIT(GICR_REG,copy_u8IntID);
	}
}

void MEXTI_enSetCalBack(MEXTI_ID_t copy_u8IntID, void(*ptrfn)(void))
{
	switch (copy_u8IntID)
	{
	case MEXTI_INT0_ID:
		callBackArr[0] = ptrfn;
		break;
	case MEXTI_INT1_ID:
		callBackArr[1] = ptrfn;
		break;
	case MEXTI_INT2_ID:
		callBackArr[2] = ptrfn;
		break;
	}

}

ISR(EXT_INT_0)
{
	if (callBackArr[0] != NULL)
	{
		callBackArr[0]();
	}
}


ISR(EXT_INT_1)
{
	if (callBackArr[1] != NULL)
	{
		callBackArr[1]();
	}
}

ISR(EXT_INT_2)
{
	if (callBackArr[2] != NULL)
	{
		callBackArr[2]();
	}
}
