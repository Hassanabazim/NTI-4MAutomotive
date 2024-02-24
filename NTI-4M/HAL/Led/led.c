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

#include "std_types.h"
#include "bit_math.h"
#include "dio_types.h"
#include "dio.h"
#include "led.h"
#include "led_types.h"
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
void led_init(led_id_t ledId)
{
	switch(ledId)
	{
	case led_red:
		dio_vidConfigChannel(HLED_RED_PIN,OUTPUT);
		break;

	case led_yellow:
		dio_vidConfigChannel(HLED_YELLOW_PIN,OUTPUT);
		break;


	case led_green:
		dio_vidConfigChannel(HLED_GREEN_PIN,OUTPUT);
		break;


	case led_blue:
		dio_vidConfigChannel(HLED_BLUE_PIN,OUTPUT);
		break;
	}	
}

void led_on(led_id_t ledId)
{
	switch(ledId)
	{
	case led_red:
#if(HLED_RED == HLED_FORWARD_DIR)
		dio_vidWriteChannel(HLED_RED_PIN,STD_HIGH);

#elif(HLED_RED == HLED_REVERSE_DIR)
		dio_vidWriteChannel(HLED_RED_PIN,STD_LOW);

#else
#error ("WRONG LED DIRECTION");
#endif

		break;

	case led_yellow:
#if(HLED_RED == HLED_FORWARD_DIR)
		dio_vidWriteChannel(HLED_YELLOW_PIN,STD_HIGH);

#elif(HLED_RED == HLED_REVERSE_DIR)
		dio_vidWriteChannel(HLED_YELLOW_PIN,STD_LOW);

#else
#error ("WRONG LED DIRECTION");
#endif
		break;


	case led_green:
#if(HLED_RED == HLED_FORWARD_DIR)
		dio_vidWriteChannel(HLED_GREEN_PIN,STD_HIGH);

#elif(HLED_RED == HLED_REVERSE_DIR)
		dio_vidWriteChannel(HLED_GREEN_PIN,STD_LOW);
#else
#error ("WRONG LED DIRECTION");
#endif
		break;


	case led_blue:
#if(HLED_RED == HLED_FORWARD_DIR)
		dio_vidWriteChannel(HLED_BLUE_PIN,STD_HIGH);

#elif(HLED_RED == HLED_REVERSE_DIR)
		dio_vidWriteChannel(HLED_BLUE_PIN,STD_LOW);

#else
#error ("WRONG LED DIRECTION");
#endif
		break;
	}	
}
void led_off(led_id_t ledId)
{
	switch(ledId)
	{
	case led_red:
#if(HLED_RED == HLED_FORWARD_DIR)
		dio_vidWriteChannel(HLED_RED_PIN,STD_LOW);
#elif(HLED_RED == HLED_REVERSE_DIR)
		dio_vidWriteChannel(HLED_RED_PIN,STD_HIGH);
#else
#error ("WRONG LED DIRECTION");
#endif
		break;

	case led_yellow:
#if(HLED_RED == HLED_FORWARD_DIR)
		dio_vidWriteChannel(HLED_YELLOW_PIN,STD_LOW);

#elif(HLED_RED == HLED_REVERSE_DIR)
		dio_vidWriteChannel(HLED_YELLOW_PIN,STD_HIGH);
#else
#error ("WRONG LED DIRECTION");
#endif
		break;


	case led_green:
#if(HLED_RED == HLED_FORWARD_DIR)
		dio_vidWriteChannel(HLED_GREEN_PIN,STD_LOW);
#elif(HLED_RED == HLED_REVERSE_DIR)
		dio_vidWriteChannel(HLED_GREEN_PIN,STD_HIGH);
#else
#error ("WRONG LED DIRECTION");
#endif
		break;


	case led_blue:
#if(HLED_RED == HLED_FORWARD_DIR)
		dio_vidWriteChannel(HLED_BLUE_PIN,STD_LOW);
#elif(HLED_RED == HLED_REVERSE_DIR)
		dio_vidWriteChannel(HLED_BLUE_PIN,STD_HIGH);
#else
#error ("WRONG LED DIRECTION");
#endif
		break;
	}	
}

void led_toggle(led_id_t ledId)
{
	switch(ledId)
	{
	case led_red:
	dio_vidFlipChannel(HLED_RED_PIN);
	break;

	case led_yellow:
		dio_vidFlipChannel(HLED_YELLOW_PIN);
		break;


	case led_green:
		dio_vidFlipChannel(HLED_GREEN_PIN);
		break;


	case led_blue:
		dio_vidFlipChannel(HLED_BLUE_PIN);
		break;
	}	
}


/**********************************************************************************************************************
 *  END OF FILE: FileName.c
 *********************************************************************************************************************/
