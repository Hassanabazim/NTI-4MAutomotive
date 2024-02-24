/**********************************************************************************************************************
 *  FILE DESCRIPTION
 *  -----------------------------------------------------------------------------------------------------------------*/
/**        \file  keypad.c
 *        \brief  
 *
 *      \details  
 *
 *
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  INCLUDES
 
 *********************************************************************************************************************/
#define F_CPU 16000000UL
#include "keypad.h"
#include "keypad_cfg.h"
#include <util/delay.h>
/**********************************************************************************************************************
*  LOCAL MACROS CONSTANT\FUNCTION
*********************************************************************************************************************/

/**********************************************************************************************************************
 *  LOCAL DATA 
 *********************************************************************************************************************/
static u8 keys_value[4][4]=
{
		{'1','2','3','A'},
		{'4','5','6','B'},
		{'7','8','9','C'},
		{'F','0','E','D'}
};
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
* \Syntax          : void keypad_vidInit(void)        
* \Description     : keypad HW initialization                                
*                                                                             
* \Sync\Async      : Synchronous                                               
* \Reentrancy      : Non Reentrant                                             
* \Parameters (in) : None                                                                         
* \Return value:   : None                               
*******************************************************************************/
void keypad_vidInit(void)
{
	/*	ROW channel direction -> output	*/
	dio_vidConfigChannel(KEYPAD_ROW1_PORT,KEYPAD_ROW1_CHANNEL,OUTPUT);
	dio_vidConfigChannel(KEYPAD_ROW2_PORT,KEYPAD_ROW2_CHANNEL,OUTPUT);
	dio_vidConfigChannel(KEYPAD_ROW3_PORT,KEYPAD_ROW3_CHANNEL,OUTPUT);
	dio_vidConfigChannel(KEYPAD_ROW4_PORT,KEYPAD_ROW4_CHANNEL,OUTPUT);
	
	/*	COLUMN channel direction -> input	*/
	dio_vidConfigChannel(KEYPAD_COL1_PORT,KEYPAD_COL1_CHANNEL,INPUT);
	dio_vidConfigChannel(KEYPAD_COL2_PORT,KEYPAD_COL2_CHANNEL,INPUT);
	dio_vidConfigChannel(KEYPAD_COL3_PORT,KEYPAD_COL3_CHANNEL,INPUT);
	dio_vidConfigChannel(KEYPAD_COL4_PORT,KEYPAD_COL4_CHANNEL,INPUT);
	/*	force logic 0 to ROWs	*/
	dio_vidWriteChannel(KEYPAD_ROW1_PORT,KEYPAD_ROW1_CHANNEL,STD_LOW);
	dio_vidWriteChannel(KEYPAD_ROW2_PORT,KEYPAD_ROW2_CHANNEL,STD_LOW);
	dio_vidWriteChannel(KEYPAD_ROW3_PORT,KEYPAD_ROW3_CHANNEL,STD_LOW);
	dio_vidWriteChannel(KEYPAD_ROW4_PORT,KEYPAD_ROW4_CHANNEL,STD_LOW);
}


boolean keypad_bolIsPressed(void)
{
	if (
		dio_dioLevelReadChannel(KEYPAD_COL1_PORT,KEYPAD_COL1_CHANNEL)&&
		dio_dioLevelReadChannel(KEYPAD_COL2_PORT,KEYPAD_COL2_CHANNEL)&&
		dio_dioLevelReadChannel(KEYPAD_COL3_PORT,KEYPAD_COL3_CHANNEL)&&
		dio_dioLevelReadChannel(KEYPAD_COL4_PORT,KEYPAD_COL4_CHANNEL)
		)
	{
	 return FALSE;
	}
	else
	{
	 return TRUE;
	}
}
u8 keypad_GetCol(void)
{
	u8 loc_col = 0;
	if      (dio_dioLevelReadChannel(KEYPAD_COL1_PORT,KEYPAD_COL1_CHANNEL) == STD_LOW)
	{
		loc_col = 1;	
	}
	else if (dio_dioLevelReadChannel(KEYPAD_COL2_PORT,KEYPAD_COL2_CHANNEL) == STD_LOW)
	{
	   loc_col = 2;	
	}
	else if (dio_dioLevelReadChannel(KEYPAD_COL3_PORT,KEYPAD_COL3_CHANNEL) == STD_LOW)
	{
	   loc_col = 3;	
	}
	else if (dio_dioLevelReadChannel(KEYPAD_COL4_PORT,KEYPAD_COL4_CHANNEL) == STD_LOW)
	{
	   loc_col = 4;	
	}
	else
	{
		/*	do nothing	*/
	}
	dio_vidWriteChannel(KEYPAD_ROW1_PORT,KEYPAD_ROW1_CHANNEL,STD_HIGH);
	dio_vidWriteChannel(KEYPAD_ROW2_PORT,KEYPAD_ROW2_CHANNEL,STD_HIGH);
	dio_vidWriteChannel(KEYPAD_ROW3_PORT,KEYPAD_ROW3_CHANNEL,STD_HIGH);
	dio_vidWriteChannel(KEYPAD_ROW4_PORT,KEYPAD_ROW4_CHANNEL,STD_HIGH);
	
	return loc_col;
}

u8 keypad_GetRow(u8 col)
{
	u8 loc_row =0;
	
	dio_vidWriteChannel(KEYPAD_ROW1_PORT,KEYPAD_ROW1_CHANNEL,STD_LOW);
	if (keypad_GetCol() == col)
	{
		loc_row = 1;	
	}
	dio_vidWriteChannel(KEYPAD_ROW1_PORT,KEYPAD_ROW1_CHANNEL,STD_HIGH);
	dio_vidWriteChannel(KEYPAD_ROW2_PORT,KEYPAD_ROW2_CHANNEL,STD_LOW);
	if (keypad_GetCol() == col)
	{
		loc_row = 2;	
	}
	dio_vidWriteChannel(KEYPAD_ROW2_PORT,KEYPAD_ROW2_CHANNEL,STD_HIGH);
	dio_vidWriteChannel(KEYPAD_ROW3_PORT,KEYPAD_ROW3_CHANNEL,STD_LOW);
	if (keypad_GetCol() == col)
	{
		loc_row = 3;	
	}
	dio_vidWriteChannel(KEYPAD_ROW3_PORT,KEYPAD_ROW3_CHANNEL,STD_HIGH);
	dio_vidWriteChannel(KEYPAD_ROW4_PORT,KEYPAD_ROW4_CHANNEL,STD_LOW);
	if (keypad_GetCol() == col)
	{
		loc_row = 4;	
	}
	dio_vidWriteChannel(KEYPAD_ROW1_PORT,KEYPAD_ROW1_CHANNEL,STD_LOW);
	dio_vidWriteChannel(KEYPAD_ROW2_PORT,KEYPAD_ROW2_CHANNEL,STD_LOW);
	dio_vidWriteChannel(KEYPAD_ROW3_PORT,KEYPAD_ROW3_CHANNEL,STD_LOW);
	dio_vidWriteChannel(KEYPAD_ROW4_PORT,KEYPAD_ROW4_CHANNEL,STD_LOW);
	return loc_row;
}
/*	it shall be called periodically	*/
u8 keypad_u8GetKey(void)
{
	u8 loc_row = 0;
	u8 loc_col = 0;
	
	if (TRUE == keypad_bolIsPressed())
	{
		//loc_col = 1;
		//loc_row = 1;
		loc_col = keypad_GetCol();
		loc_row = keypad_GetRow(loc_col);
		_delay_ms(250);	/*	press time	*/	
		return 	keys_value[loc_row-1][loc_col-1];
	}
	else
	{
		return 0xFF;
	}
}


/**********************************************************************************************************************
 *  END OF FILE: FileName.c
 *********************************************************************************************************************/
