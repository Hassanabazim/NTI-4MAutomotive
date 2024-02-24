/**************************************************
 *  File		: Uart.c
 *	Module		: UART
 *	Target		: ATMEGA32
 *	Author		: mFawzi
 *  Description	:
 ***************************************************/
#include "std_types.h"
#include "dio.h"
#include "uart.h"
#include <avr/interrupt.h>

#define UART_TX_BUFFER_SIZE		(100)
#define UART_RX_BUFFER_SIZE		(100)

u8 uart_rx_flag  ;

u8 uart_TxBufferIndex = 0;
u8 uart_TxBuffer[UART_TX_BUFFER_SIZE];

u8 uart_RxBufferIndex = 0;
u8 uart_RxBuffer[UART_RX_BUFFER_SIZE];

void UART_Init(u16 baudRate)
{
	/* Set baud rate */
	UART_UBRRH_REG = (u8)(baudRate>>8);
	UART_UBRRL_REG = (u8)baudRate;
	/* Enable receiver and transmitter */
	SET_BIT(UART_UCSRB_REG,RXEN_BIT_NO);  /* Enable Receiver*/
	SET_BIT(UART_UCSRB_REG,TXEN_BIT_NO);  /* Enable Transmitter */
	/* Set frame format: 8data, 1stop bit, Even Parity */
	UART_UCSRC_REG |= (1 << URSEL_BIT_NO)| UART_8_BIT_DATA | UART_EVEN_PARITY;

	/*	Enable Rx complete	*/
//	SET_BIT(UART_UCSRB_REG,RXC_BIT_NO);
	/*	Enable Tx complete	*/
//	SET_BIT(UART_UCSRB_REG,TXC_BIT_NO);
}

void UART_TransmitChr(u8 data)
{
	UART_UDR_REG = data;

	/* Wait for empty transmit buffer */
	while (CHECK_BIT(UART_UCSRA_REG,TXC_BIT_NO != 1))
		;
	/* Put data into buffer, sends the data */

	SET_BIT(UART_UCSRA_REG, TXC_BIT_NO);
}

u8 UART_ReceiveChr(void)
{
	/* Wait for data to be received */
	while (!(CHECK_BIT(UART_UCSRA_REG,RXC_BIT_NO)))
	{
		;
	}
	/* Get and return received data from buffer */
	return UART_UDR_REG;
}

void UART_TransmitStrPoll(u8 str[])
{
	while (*str != '\0')
	{
		UART_TransmitChr(*str);
		str++;
	}
}


void UART_Receivestr(u8 buffer[])
{
	u8 i = 0;
	while (1)
	{
		buffer[i] = UART_ReceiveChr();
		if (buffer[i] == '#')break;
		i++;
	}
}

void uart_sendByte(u8 byte)
{
	UART_UDR_REG = byte;
}

void uart_sendMessage(u8 mssg[])
{
	/*	copy mssg into uart_TxBuffer */
	for (u8 i = 0;i < UART_TX_BUFFER_SIZE; i++)
	{
		uart_TxBuffer[i] = mssg[i] ;
		if (mssg[i] == '\0')break;
	}
	/*	send first byte	*/
	UART_UDR_REG = uart_TxBuffer[uart_TxBufferIndex];

}

boolean uart_isMessageReceived(void)
{
	return uart_rx_flag;
}

void uart_receiveMessage(u8 mssg[])
{
	for (u8 i = 0; i < UART_RX_BUFFER_SIZE ; i++)
	{
		mssg[i] = uart_RxBuffer[i];
		if (uart_RxBuffer[i] == '\0')break;
	}
	uart_rx_flag = FALSE;
}




/*	Tx Complete ISR	*/
ISR(USART_TXC_vect)
{
	/* update new byte index	*/
	uart_TxBufferIndex ++;
	/*	check current byte is NULL?	*/
	if (uart_TxBuffer[uart_TxBufferIndex] != '\0')
	{
		/*	if not null send	*/
		UART_UDR_REG = uart_TxBuffer[uart_TxBufferIndex];
	}

}

/*	Rx Complete ISR	*/
ISR(USART_RXC_vect)
{
	uart_RxBuffer[uart_RxBufferIndex] = UART_UDR_REG;

	if (uart_RxBuffer[uart_RxBufferIndex] == '#')
	{
		uart_RxBuffer[uart_RxBufferIndex] = '\0';
		uart_RxBufferIndex = 0;
		uart_rx_flag = TRUE;
	}
	else
	{
		uart_RxBufferIndex ++;
	}

}

