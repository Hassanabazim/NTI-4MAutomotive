/*
 * main.c
 *
 *  Project: Chat Application with UART and SPI
 *      Author: Hassan Abdelazeam Abdelsalam
 */


#include "dio.h"
#include "Spi.h"
#include "uart.h"
#include "led.h"
#include "lcd.h"
#include "MEXTI_int.h"
#include <util/delay.h>


#define BUFFER_SIZE		25	// Master Slave Buffer Size

#define MASTER			1
#define SLAVE			2

#define MCU				SLAVE // Select between the Master and Slave


// global var to select between master and slave
dio_level_t slave_write = STD_LOW ;


#if (MCU == MASTER)
int main (void)
{
	dio_vidConfigChannel(DIO_PORTA, DIO_PIN4, INPUT);	// (Green LED)DIO Interrupt pin flag
	led_init(led_blue);									// (Blue LED)MasterRecieve lED ON
	lcd_vidInit();										// Lcd initialize

	/* Initialize master buffer and it's index */
	u8 master_buffer[BUFFER_SIZE] = {0}, master_index = 0;

	/*	intiallize the UART with 9600 baudrate and TX,RX Interrupt enable */
	UART_Init(UART_BAUDRATE_9600);
	/*	enable the global interrupt with the asm code */
	asm("sei");

	/*	Enable the Master mode and Active low the Slave Select */
	Spi_vidMasterInit();
	dio_vidWriteChannel(DIO_PORTB, DIO_PIN4, STD_LOW);

	/* choose between the MasterSlave and SlaveMaster Direction*/
	/*****************MasterSlave Direction************/
	while(1)
	{
		/*	set the index with zero to prevent duplicate the buffer
		 * 	so it will overwrite in every msg instead of has multiple buffers */
		master_index = 0;

		/* Turn off the Master Indication led every time data After been received */
		led_off(led_blue);

		/*	check if the slave_write was High or Low to select the Direction */
		slave_write = dio_dioLevelReadChannel(DIO_PORTA, DIO_PIN4);

		if (slave_write == STD_LOW)
		{
			/*	checks if the Master received the data so the flag will be true
			 * and master mode is on, while master waiting the data if the slave
			 * write is High will break and Execute the salveMaster block,*/
			while((uart_isMessageReceived() == FALSE)&&(slave_write == STD_LOW))
			{
				slave_write = dio_dioLevelReadChannel(DIO_PORTA, DIO_PIN4);
			}
			if (slave_write == STD_HIGH)continue;

			/*	Store the received data in the Rx Master buffer */
			uart_receiveMessage(master_buffer);

			/*	once the data in the buffer, spi master will send the data byte by byte
			 * with some delay that's for simulation mode and once the buffer get the
			 * end character '# will substitute with Null and if Null break the transmit*/
			for (master_index = 0; master_index < 100 ; master_index++)
			{
				Spi_MasterWrite(master_buffer[master_index]);
				_delay_ms(20);
				if(master_buffer[master_index] == '\0')break;
			}
		}
		/*****************SlaveMaster Direction************/
		else
		{
			while (1)
			{
				/*	check if the slave write was High or LOW and if Low Break */
				slave_write = dio_dioLevelReadChannel(DIO_PORTA, DIO_PIN4);
				if (slave_write == STD_LOW)break;

				/* check if was on slave mode every byte read and count up index
				 * with some delay for simulation and if the byte was Null break
				 * clear and display buffer on lcd and send it via Master Tx
				 * turn on the master led indication once received the byte*/
				while (slave_write == STD_HIGH)
				{
					master_buffer[master_index] =  Spi_u8MasterRead();
					_delay_ms(20);
					if (master_buffer[master_index] == '\0')
					{
						lcd_vidClrDislay();
						lcd_vidDisplyStr(master_buffer);
						uart_sendMessage(master_buffer);
						led_on(led_blue);
						break;
					}
					master_index++;
				}
			}
		}
	}
}

#elif (MCU == SLAVE)

// callback interrupt function
void slave_trigger(void);

int main ()
{
	led_init(led_yellow);								// SlaveRead Receieve LED
	dio_vidConfigChannel(DIO_PORTA, DIO_PIN4, OUTPUT);	//(Green LED)DIO Interrupt pin flag
	lcd_vidInit();

	/* Initialize the buffer and the index with zero */
	u8 slave_buffer[BUFFER_SIZE] = {0}, slave_Index = 0 ;

	/* enable UART with Baudrate 9600 and TX,RX INT enable	*/
	UART_Init(UART_BAUDRATE_9600);

	/* Callback fun of EXTI interrupt, enable EXTI_INT0 and choose the Falling Mode */
	MEXTI_enSetCalBack(MEXTI_INT1_ID, slave_trigger);
	MEXTI_enEnable(MEXTI_INT1_ID, MEXTI_FAILING_EDGE);

	/* enable the global interrupt with asm instruction */
	asm("sei");

	/* Enable the SPI in Slave Mode */
	Spi_vidSlaveInit();

	while (1)
	{
		/* turn off the Slave Receive once byte been received */
		led_off(led_yellow);
		/*	check if the slave write is high or low */
		slave_write = dio_dioLevelReadChannel(DIO_PORTA, DIO_PIN4);

		/* reset the buffer to overwrite on it */
		slave_Index = 0;

		/************* MasterSlave Direction***************/
		if (slave_write == STD_LOW)
		{
			/*	in the MasterSlave Direction, the salve expected that flag was low
			 * so it become high it break, then slave read from master with some delay
			 * for simulation purpose, and update the index, if last byte was Null break
			 * turn on Led clear and display the msg on lcd and send it by uart to slave Rx*/
			while (1)
			{
				slave_write = dio_dioLevelReadChannel(DIO_PORTA, DIO_PIN4);
				if (slave_write == STD_HIGH)break;
				slave_buffer[slave_Index] =  Spi_u8SlaveRead();
				_delay_ms(20);
				if (slave_buffer[slave_Index] == '\0')
				{
					led_on(led_yellow);
					lcd_vidClrDislay();
					lcd_vidDisplyStr(slave_buffer);
					uart_sendMessage(slave_buffer);
					break;
				}
				slave_Index++;
			}
		}
		else
		{
			/*	wait till the slave receive the msg and save it on the buffer*/
			while (uart_isMessageReceived() == FALSE);
			uart_receiveMessage(slave_buffer);

			/*	send each byte of the buffer by slave writing on the bus
			 * master send dummy data and get the slave data, bet each byte is
			 * a delay for simulation purposes and if the last character was Null break
			 * and set LOW on the Dio Interrupt Flag to enable the master to write on again
			 * if the slave want to send another msg it has to trigger the Interrupt */
			for (slave_Index = 0; slave_Index < 100 ; slave_Index++)
			{
				Spi_vidSlaveWrite(slave_buffer[slave_Index]);
				_delay_ms(20);
				if(slave_buffer[slave_Index] == '\0')
				{
					dio_vidWriteChannel(DIO_PORTA, DIO_PIN4, STD_LOW);
					break;
				}
			}
		}
	}
}
void slave_trigger(void)
{
	/* set a DIO pin High (Interrupt flag)	*/
	dio_vidWriteChannel(DIO_PORTA, DIO_PIN4, STD_HIGH);
}
#endif
