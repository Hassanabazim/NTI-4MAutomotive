void ledON( void * pvParameters )
{
	u8 *buffer ;
	buffer = pcTaskGetName(xHandleLed1);
	while (1)
	{

		led_on(led_blue);
		led_off(led_red);
		lcd_vidClrDislay();
		lcd_vidDisplyStr(buffer);

		vTaskSuspend(xHandleLed2);
		vTaskDelay(1000);
		vTaskResume(xHandleLed2);
		vTaskSuspend(xHandleLed1);
		}
}

void ledOFF( void * pvParameters )
{
	u8 *buffer ;
	buffer = pcTaskGetName(xHandleLed2);
	while (1)
	{

		led_on(led_red);
		led_off(led_blue);
		lcd_vidClrDislay();
		lcd_vidDisplyStr(buffer);

		vTaskSuspend(xHandleLed1);
		vTaskDelay(1000);
		vTaskResume(xHandleLed1);

	}
}




int main()
{
	prvSetupHardware();


	xTaskCreate(
			ledON,       /* Function that implements the task. */
			"LED_ON",          /* Text name for the task. */
			100,      /* Stack size in words, not bytes. */
			( void * ) 0,    /* Parameter passed into the task. */
			2,/* Priority at which the task is created. */
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

