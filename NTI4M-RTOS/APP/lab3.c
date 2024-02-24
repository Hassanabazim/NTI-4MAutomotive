TaskHandle_t xHandleLed1 = NULL;
TaskHandle_t xHandleLed2 = NULL;



void prvSetupHardware(void)
{
	UART_Init(UART_BAUDRATE_9600);
}

void vApplicationIdleHook(void)
{
	UART_TransmitStrPoll("IDEL TASK");
	UART_TransmitStrPoll("\r\n");
}

void ledON( void * pvParameters )
{
	u8 *buffer ;

	buffer = pcTaskGetName(xHandleLed1);
	while (1)
	{
		UART_TransmitStrPoll(buffer);
		UART_TransmitStrPoll("\r\n");
		vTaskDelay(1000);

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
		UART_TransmitStrPoll(buffer);
		UART_TransmitStrPoll("\r\n");
		vTaskDelay(1000);

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