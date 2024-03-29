/**********************************************************************************************************************

 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *         File:  led.h
 *       Module:  -
 *
 *  Description:  <Write File DESCRIPTION here>     
 *  
 *********************************************************************************************************************/
#ifndef BUTTON_H_
#define BUTTON_H_

/**********************************************************************************************************************
 * INCLUDES
 *********************************************************************************************************************/
#include "button_types.h"
#include "dio.h"

/**********************************************************************************************************************
 *  GLOBAL CONSTANT MACROS
 *********************************************************************************************************************/
#define HPB1_PIN		DIO_PORTD, DIO_PIN3
#define HPB2_PIN		DIO_PORTD, DIO_PIN5
#define HPB3_PIN		DIO_PORTD, DIO_PIN6	
#define HPB4_PIN		DIO_PORTD, DIO_PIN7



/**********************************************************************************************************************
 *  PRIVAITE MACROS
 *********************************************************************************************************************/
#define HPB_PULL_UP			1
#define HPB_PULL_DOWN		0


/**********************************************************************************************************************
 *  CONFIGURATION MODE
 *********************************************************************************************************************/
#define BUTTON1_MODE 	HPB_PULL_UP
#define BUTTON2_MODE 	HPB_PULL_UP
#define BUTTON3_MODE 	HPB_PULL_UP
#define BUTTON4_MODE 	HPB_PULL_UP


/**********************************************************************************************************************
 *  GLOBAL DATA PROTOTYPES
 *********************************************************************************************************************/

 
/**********************************************************************************************************************
 *  GLOBAL FUNCTION PROTOTYPES
 *********************************************************************************************************************/
void button_init(button_id_t buttonId);
button_status_t button_getStatus(button_id_t buttonId);

#endif  /* BUTTON_H */

/**********************************************************************************************************************
 *  END OF FILE: button.h
 *********************************************************************************************************************/
