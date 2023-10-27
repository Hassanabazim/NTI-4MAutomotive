/*
 * main.c
 *
 *
 *      Author: Hassan abdelazeam abdelsalam
 */


#include <util/delay.h>
#include "std_types.h"
#include "FreeRTOS.h"
#include "task.h"
#include "dio.h"
#include "led.h"
#include "lcd.h"
#include "uart.h"

void prvSetupHardware(void)
{
	led_init(led_red);
	led_init(led_blue);
	lcd_vidInit();
}

void ledON( void * pvParameters )
{
	while (1)
	{
		led_on(led_blue);
		led_off(led_red);
		lcd_vidDisplyStr("LED BLUE");
		vTaskDelay(1000);
		lcd_vidClrDislay();

	}
}

void ledOFF( void * pvParameters )
{
	while (1)
	{
		led_on(led_red);
		led_off(led_blue);
		lcd_vidDisplyStr("LED RED");
		vTaskDelay(1000);
		lcd_vidClrDislay();



	}
}

TaskHandle_t xHandleLed1 = NULL;
TaskHandle_t xHandleLed2 = NULL;


int main()
{
	prvSetupHardware();


	xTaskCreate(
			ledON,       /* Function that implements the task. */
			"LED_ON",          /* Text name for the task. */
			100,      /* Stack size in words, not bytes. */
			( void * ) 0,    /* Parameter passed into the task. */
			1,/* Priority at which the task is created. */
			&xHandleLed1 );      /* Used to pass out the created task's handle. */

	xTaskCreate(
			ledOFF,       /* Function that implements the task. */
			"LED_OFF",          /* Text name for the task. */
			100,      /* Stack size in words, not bytes. */
			( void * ) 0,    /* Parameter passed into the task. */
			1,/* Priority at which the task is created. */
			&xHandleLed2 );      /* Used to pass out the created task's handle. */


	vTaskStartScheduler();

}
