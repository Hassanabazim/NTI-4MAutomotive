/*
 * main.c
 *
 *
 *      Author: Hassan abdelazeam abdelsalam
 */


#include <util/delay.h>
#include "std_types.h"
#include "FreeRTOS.h"
#include "semphr.h"
#include "task.h"
#include "timers.h"
#include "dio.h"
#include "led.h"
#include "lcd.h"
#include "uart.h"


void TASK1(void);

TimerHandle_t xTimer = NULL;

u8 hr = 0, min = 0 , sec = 0;






int main()
{
	lcd_vidInit();

	xTimer = xTimerCreate("Timer", 1000, pdTRUE,( void * )0, TASK1);

	if( xTimer == NULL )
	{
		/* The timer was not created. */
	}
	else
	{
		if( xTimerStart( xTimer, 0 ) != pdPASS )
		{

		}
	}

	vTaskStartScheduler();
}

void TASK1(void)
{
	sec++;
	if (sec == 59)
	{
		min++;
		sec = 0;
		if (min == 59)
		{
			hr++;
			min = 0;
		}
	}
	lcd_vidClrDislay();
	lcd_vidDisplayNum(sec);
	lcd_vidDisplyChar(':');
	lcd_vidDisplayNum(min);
	lcd_vidDisplyChar(':');
	lcd_vidDisplayNum(hr);
}
