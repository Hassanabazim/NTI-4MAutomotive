/*
 * main.c
 *
 *  Created on: Sep 9, 2023
 *      Author: Hassan abdelazeam abdelsalam
 */


#include <util/delay.h>
#include "std_types.h"
#include "dio.h"
#include "led.h"
#include "lcd.h"
#include "uart.h"
#include "Spi.h"



int main()
{

#if 	0
	lcd_vidInit();
	UART_Init(UART_BAUDRATE_9600);
	led_init(led_red);
	led_init(led_green);
	led_init(led_blue);
	led_init(led_yellow);


	while (1)
	{
		led_on(led_red);
		lcd_vidDisplyStr("LED RED IS ON ");
		UART_TransmitStrPoll("LED RED IS ON ");
		_delay_ms(1000);
		led_off(led_red);
		lcd_vidClrDislay();


		led_on(led_green);
		lcd_vidDisplyStr("LED GREEN IS ON ");
		UART_TransmitStrPoll("LED GREEN IS ON ");
		_delay_ms(1000);
		led_off(led_green);
		lcd_vidClrDislay();


		led_on(led_blue);
		lcd_vidDisplyStr("LED BLUE IS ON ");
		UART_TransmitStrPoll("LED BLUE IS ON ");
		_delay_ms(1000);
		led_off(led_blue);
		lcd_vidClrDislay();


		led_on(led_yellow);
		lcd_vidDisplyStr("LED YELLOW IS ON ");
		UART_TransmitStrPoll("LED YELLOW IS ON ");;
		_delay_ms(1000);
		led_off(led_yellow);
		lcd_vidClrDislay();


	}

#elif 0
	u8 buffer[10] = {0} ;
	//lcd_vidInit();
	UART_Init(UART_BAUDRATE_115200);
	//asm("sei");
	UART_TransmitChr(0xA5);
	UART_TransmitChr(0x52);
	//while(uart_isMessageReceived() == FALSE);
	//uart_receiveMessage(buffer);
	//lcd_vidDisplyStr(buffer);

	//lcd_vidInit();
	//lcd_vidDisplyStr("hassa");

	for (u8 i = 0 ; i < 10; i++)
	{
		buffer[i] = UART_ReceiveChr();
	}
	while (1)
	{

	}

#elif 0

	lcd_vidDisplyChar('H');
	while (1)
	{

	}
#elif 0

	Spi_vidSlaveInit();
	u8 data = Spi_u8SlaveRead();
	while (data != 'H');
	dio_vidWriteChannel(DIO_PORTC, DIO_PIN0, STD_HIGH);
	while(1)
	{

		lcd_vidDisplyChar(data);
		_delay_ms(500);
		lcd_vidClrDislay();

	}

#elif 0
	/******** I2C FRAME ************/

	I2C_MasterInit();

	I2C_StartCondition();

	I2C_Send_SlaveAddressWriteOperation(0b0001000);

	I2C_WriteByte(0x55);


	I2C_StopCondition();


	while (1)
	{

	}
#elif	0




	lcd_vidInit();
	u8 data ;


	eeprom_voidInit();
	eeprom_voidWriteByte(0x10, 1);


	_delay_ms(100);
	data = eeprom_voidReadByte(0x10);



	lcd_vidDisplyChar(data);
	while (1)
	{
	}

#elif 0


	u8 data ;
	DIO_DDRB_REG = 0xFF;
	eep24c08_init();
	eep24c08_writeByte('H', 0x4);



	_delay_ms(100);

	data = eep24c08_readByte(0x4);

	_delay_ms(100);

	eep24c08_writeByte('A', 0x5);

	_delay_ms(100);

	data = eep24c08_readByte(0x5);

	DIO_PORTB_REG = data;
	while (1)
	{

	}

#elif 	0



	asm("SEI");
	TCCR0_REG = 0x45;
	TIMSK_REG |= 0x02;
	OCR0_REG = 200;


	led_init(led_red);
	while (1)
	{
		if (flag == 1)
		{
			led_toggle(led_red);
			flag = 0;
		}
	}



#elif 0
	//TIMER_REGISTERS
#define TCCR0_REG 	(*((volatile u8*)0x53))
#define TCNT0_REG 	(*((volatile u8*)0x52))
#define OCR0_REG 	(*((volatile u8*)0x5C))
#define TIFR_REG 	(*((volatile u8*)0x58))
#define TIMSK_REG 	(*((volatile u8*)0x59))



	dio_vidConfigChannel( DIO_PORTB, DIO_PIN7, INPUT);
	dio_vidConfigChannel(DIO_PORTB, DIO_PIN3, OUTPUT);
	TCCR0_REG = 0x65;
	lcd_vidInit();


	while (1)
	{
		static u8 var = 0;
		OCR0_REG = var++ ;

		lcd_vidClrDislay();
		lcd_vidDisplayNum(var);
		_delay_ms(100);


	}






#elif 0
	u16 distance ;
	lcd_vidInit();
	HC_SR04_Init();

	while (1)
	{
		distance = HC_SR04_get_distance();
		lcd_vidDisplayNum(distance);
		_delay_ms(500);
		lcd_vidClrDislay();
	}

}
#endif
}

#if 0
ISR(TIMER0_OVF_vect)
{
	static u32 counter ;
	counter ++;

	if(counter == 61)
	{
		flag = 1;
		counter = 0	;
	}

}

ISR(TIMER0_COMP_vect)
{
	static u32 counter ;
	counter ++;

	if(counter == 78)
	{
		flag = 1;
		counter = 0	;
	}
}
#endif
