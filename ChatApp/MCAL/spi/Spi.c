/***********************************************
 *  File		: Spi.c
 *	Module		: SPI
 *	Target		: ATMEGA32
 *	Author		: mFawzi
 *  Description	:
 *
 *************************************************/
#include "Spi.h"

void Spi_vidMasterInit(void)
{
	/*	configure SPI MOSI Pin as output	*/
	dio_vidConfigChannel(DIO_PORTB, DIO_PIN5, OUTPUT);
	/*	configure SPI SS Pin as output	*/
	dio_vidConfigChannel(DIO_PORTB, DIO_PIN4, OUTPUT);
	/*	configure SPI SCK Pin as output	*/
	dio_vidConfigChannel(DIO_PORTB, DIO_PIN7, OUTPUT);
	/*	configure SPI MISO Pin as input	*/
	dio_vidConfigChannel(DIO_PORTB, DIO_PIN6, INPUT);
	/*	initialize SPI SS pin with HIGH (No slave selected) */
	dio_vidWriteChannel(DIO_PORTB, DIO_PIN4, STD_HIGH);
	/*	enable SPI Module	*/
	SET_BIT(SPI_SPCR_REG,SPI_SPE_BIT_NO);
	/*	enable SPI Module in Master mode	*/
	SET_BIT(SPI_SPCR_REG,SPI_MSTR_BIT_NO);
	/*	set SCK frequency by F_CPU/16	*/
	/*	Set SPI Speed	1MHZ*/
	SPI_SPCR_REG |= SPI_SCK_FREQ_FCPU_DIV_4;
}

void Spi_vidSlaveInit(void)
{
	/*	configure SPI MOSI Pin as input	*/
	dio_vidConfigChannel(DIO_PORTB, DIO_PIN5, INPUT);
	/*	configure SPI SS Pin as input	*/
	dio_vidConfigChannel(DIO_PORTB, DIO_PIN4, INPUT);
	/*	configure SPI SCK Pin as input	*/
	dio_vidConfigChannel(DIO_PORTB, DIO_PIN7, INPUT);
	/*	configure SPI MISO Pin as output	*/
	dio_vidConfigChannel(DIO_PORTB, DIO_PIN6, OUTPUT);
	/*	enable SPI Module	*/
	SET_BIT(SPI_SPCR_REG,SPI_SPE_BIT_NO);
	/*	enable SPI Module in Slave mode	*/
	CLEAR_BIT(SPI_SPCR_REG,SPI_MSTR_BIT_NO);
}

void Spi_MasterWrite(u8 data)
{
	u8 loc_flush_byte;
	/*	load SPI data register with a byte to send	*/
	SPI_SPDR_REG = data;
	/*	wait until byte sent	*/
	while(CHECK_BIT(SPI_SPSR_REG,SPI_SPIF_BIT_NO) == 0)
	{
		;
	}
	/*	flush the data register	*/
	loc_flush_byte = SPI_SPDR_REG;
}
u8 Spi_u8MasterRead(void)
{
	u8 loc_dummy_byte=0xFF;
	/*	load SPI data register with a byte to send	*/
	SPI_SPDR_REG = loc_dummy_byte;
	/*	wait until byte received	*/
	while(CHECK_BIT(SPI_SPSR_REG,SPI_SPIF_BIT_NO) == 0)
	{
		;
	}
	/*	read the data register	*/
	return SPI_SPDR_REG;
}

u8 Spi_u8MasterTranseve(u8 data)
{
	/*	load SPI data register with a byte to send	*/
	SPI_SPDR_REG = data;
	/*	wait until byte sent	*/
	while(CHECK_BIT(SPI_SPSR_REG,SPI_SPIF_BIT_NO) == 0)
	{
		;
	}
	/*	flush the data register	*/
	return SPI_SPDR_REG;
}

u8 Spi_u8SlaveRead(void)
{

	/*	wait until byte received	*/
	while(CHECK_BIT(SPI_SPSR_REG,SPI_SPIF_BIT_NO) == 0)
	{
		;
	}

	/*	read the data register	*/
	return SPI_SPDR_REG;
}

void Spi_vidSlaveWrite(u8 data)
{
	SPI_SPDR_REG = data;
}
