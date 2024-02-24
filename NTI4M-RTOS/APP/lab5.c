TaskHandle_t xHandle1 = NULL;
TaskHandle_t xHandle2 = NULL;
TaskHandle_t xHandle3 = NULL;
QueueHandle_t queue_1 = NULL;

void prvSetupHardware(void)
{
	lcd_vidInit();

	queue_1 = xQueueCreate(2, 20);
	if (queue_1 == NULL)
	{

	}
}

void TASK1( void * pvParameters )
{
	u8 ulVar [20] = "TASK1";

	while(1)
	{
		if (xQueueSend(queue_1 , ( void * ) ulVar,10) != pdPASS)
		{

		}
		else
		{

		}
		vTaskDelay(900);
	}
}

void TASK2( void * pvParameters )
{
	u8 u2Var [20] = "TASK2";
	while(1)
	{
		if (xQueueSend(queue_1 , ( void * ) u2Var,10) != pdPASS)
		{

		}
		else
		{

		}
		vTaskDelay(1000);
	}
}

void TASK3( void * pvParameters )
{
	u8 buffer[20];
	while (1)
	{
		if(xQueueReceive(queue_1,( void * ) buffer,10) == pdPASS)
		{
			lcd_vidClrDislay();
			lcd_vidDisplyStr(buffer);

		}
		vTaskDelay(450);
	}
}



int main()
{
	prvSetupHardware();


	xTaskCreate(TASK1, "TASK1", 200, (void*)0, 1, &xHandle1);
	xTaskCreate(TASK2, "TASK2", 200, (void*)0, 2, &xHandle2);
	xTaskCreate(TASK3, "TASK3", 200, (void*)0, 3, &xHandle3);


	vTaskStartScheduler();
}
