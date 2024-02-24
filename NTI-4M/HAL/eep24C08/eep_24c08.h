/*
 * eep_24c08.h
 *
 * Created: 9/22/2023 3:50:02 PM
 *  Author: reBuyTech
 */ 


#ifndef EEP_24C08_H_
#define EEP_24C08_H_

#define EEP24C0C_BLOCK_SIZE				(256)
void eep24c08_init(void);
void eep24c08_writeByte(u8 byte, u16 addr);
void eep24c08_writePage(u8 page[], u8 baseAddr, u8 length);

u8 eep24c08_readCurrAddr(u8 pageNo);
u8 eep24c08_readByte(u16 addr);
#endif /* EEP_24C08_H_ */
