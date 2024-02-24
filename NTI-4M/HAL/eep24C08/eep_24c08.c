/*
 * eep_24c08.c
 *
 * Created: 9/22/2023 3:49:50 PM
 *  Author: reBuyTech
 */ 
#include "i2c.h"
#include "eep_24c08.h"
#include "dio.h"

void eep24c08_init(void)
{
	I2C_MasterInit();
}
void eep24c08_writeByte(u8 byte, u16 addr) // 0 - 1023
{


	u8 loc_pageNo = addr/EEP24C0C_BLOCK_SIZE;
	u8 loc_byteNo = addr%EEP24C0C_BLOCK_SIZE;
	u8 loc_blkAddr = (0x0A<<3)|(loc_pageNo);

	I2C_StartCondition();
	I2C_Send_SlaveAddressWriteOperation(loc_blkAddr);

	I2C_WriteByte(loc_byteNo);

	I2C_WriteByte(byte);


	I2C_StopCondition();


}

void eep24c08_writePage(u8 page[], u8 baseAddr, u8 length)
{

}

u8 eep24c08_readCurrAddr(u8 pageNo)
{

}
u8 eep24c08_readByte(u16 addr)
{
	dio_vidConfigChannel(DIO_PORTD, DIO_PIN0, OUTPUT);
	u8 loc_readByte =0;
	u8 loc_pageNo = addr/EEP24C0C_BLOCK_SIZE;
	u8 loc_byteNo = addr%EEP24C0C_BLOCK_SIZE;

	u8 loc_blkAddr = (0x0A<<3)|(loc_pageNo);

	I2C_StartCondition();
	I2C_Send_SlaveAddressWriteOperation(loc_blkAddr);
	I2C_WriteByte(loc_byteNo);
	if (I2C_RepeatedStartCondition() == TRUE)
	{
		dio_vidWriteChannel(DIO_PORTD, DIO_PIN0, STD_HIGH);

	}
	I2C_Send_SlaveAddressReadOperation(loc_blkAddr);
	loc_readByte = I2C_ReadByte();
	I2C_StopCondition();


	return loc_readByte;
}

