TaskHandle_t xHandle1 = NULL;
TaskHandle_t xHandle2 = NULL;
SemaphoreHandle_t Semaphore;


void prvSetupHardware(void)
{
	lcd_vidInit();
	Semaphore = xSemaphoreCreateBinary();
	if (Semaphore != NULL)
	{
		xSemaphoreGive(Semaphore);
	}
}


void TASK1( void * pvParameters )
{
	u8 *buffer ;

	buffer = pcTaskGetName(xHandle1);

	while (1)
	{
		if (xSemaphoreTake(Semaphore ,1000) == pdTRUE)
		{
			lcd_vidClrDislay();
			lcd_vidDisplyStr(buffer);
			vTaskDelay(1000);
			xSemaphoreGive(Semaphore);
			vTaskDelay(1);
		}
		else
		{
			lcd_vidClrDislay();
		}
	}
}

void TASK2( void * pvParameters )
{
	u8 *buffer ;
	buffer = pcTaskGetName(xHandle2);

	while (1)
	{
		if (xSemaphoreTake(Semaphore ,1000) == pdTRUE)
		{
			lcd_vidClrDislay();
			lcd_vidDisplyStr(buffer);

			vTaskDelay(1000);
			xSemaphoreGive(Semaphore);
			vTaskDelay(1);
		}


		else
		{
			lcd_vidClrDislay();
		}

	}
}


int main()
{
	prvSetupHardware();


	xTaskCreate(
			TASK1,       	/* Function that implements the task. */
			"TASK1",        /* Text name for the task. */
			100,     		/* Stack size in words, not bytes. */
			( void * ) 0,   /* Parameter passed into the task. */
			2,				/* Priority at which the task is created. */
			&xHandle1 );    /* Used to pass out the created task's handle. */

	xTaskCreate(
			TASK2,       	/* Function that implements the task. */
			"TASK2",        /* Text name for the task. */
			100,      		/* Stack size in words, not bytes. */
			( void * ) 0,   /* Parameter passed into the task. */
			1,				/* Priority at which the task is created. */
			&xHandle2 );   	/* Used to pass out the created task's handle. */

	vTaskStartScheduler();
}
