/**********************************************************************************************************************
 *  FILE DESCRIPTION
 *  -----------------------------------------------------------------------------------------------------------------*/
/**        \file  FileName.c
 *        \brief  
 *
 *      \details  
 *
 *
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/
#include <util/delay.h>
#include "std_types.h"
#include "bit_math.h"
#include "dio.h"
#include "dio_types.h"
#include "button.h"
#include "button_types.h"
/**********************************************************************************************************************
 *  LOCAL MACROS CONSTANT\FUNCTION
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  LOCAL DATA 
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  GLOBAL DATA
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  LOCAL FUNCTION PROTOTYPES
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  LOCAL FUNCTIONS
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  GLOBAL FUNCTIONS
 *********************************************************************************************************************/


/******************************************************************************
 * \Syntax          : Std_ReturnType FunctionName(AnyType parameterName)
 * \Description     : Describe this service
 *
 * \Sync\Async      : Synchronous
 * \Reentrancy      : Non Reentrant
 * \Parameters (in) : parameterName   Parameter Describtion
 * \Return value:   : Std_ReturnType  E_OK
 *                                    E_NOT_OK
 *******************************************************************************/
void button_init(button_id_t buttonId)
{
	switch(buttonId)
	{

	case BUTTON1:
		dio_vidConfigChannel(HPB1_PIN, INPUT);
#if(BUTTON1_MODE == HPB_PULL_UP)
		dio_vidEnablePullUp(HPB1_PIN);
#endif
		break;

	case BUTTON2:
		dio_vidConfigChannel(HPB2_PIN, INPUT);
#if(BUTTON2_MODE == HPB_PULL_UP)
		dio_vidEnablePullUp(HPB2_PIN);
#endif
		break;

	case BUTTON3:
		dio_vidConfigChannel(HPB3_PIN, INPUT);
#if(BUTTON3_MODE == HPB_PULL_UP)
		dio_vidEnablePullUp(HPB3_PIN);
#endif
		break;

	case BUTTON4:
		dio_vidConfigChannel(HPB4_PIN, INPUT);
#if(BUTTON4_MODE == HPB_PULL_UP)
		dio_vidEnablePullUp(HPB4_PIN);
#endif
		break;

	}
}


button_status_t button_getStatus(button_id_t buttonId)
{
	button_status_t state = RELEASED;

	switch(buttonId)
	{
	case BUTTON1:
		state = dio_dioLevelReadChannel(HPB1_PIN);
		if (state == STD_LOW)
		{
			_delay_ms(100);
			state = dio_dioLevelReadChannel(HPB1_PIN);
		}
		break;

	case BUTTON2:
		state = dio_dioLevelReadChannel(HPB2_PIN);
		if (state == STD_LOW)
		{
			_delay_ms(100);
			state = dio_dioLevelReadChannel(HPB2_PIN);
		}
		break;

	case BUTTON3:
		state = dio_dioLevelReadChannel(HPB3_PIN);

		if (state == STD_LOW)
		{
			_delay_ms(100);
			state = dio_dioLevelReadChannel(HPB3_PIN);
		}
		break;

	case BUTTON4:
		state = dio_dioLevelReadChannel(HPB4_PIN);

		if (state == STD_LOW)
		{
			_delay_ms(100);
			state = dio_dioLevelReadChannel(HPB4_PIN);
		}
		break;
	}

	return state;

}

/**********************************************************************************************************************
 *  END OF FILE: FileName.c
 *********************************************************************************************************************/
