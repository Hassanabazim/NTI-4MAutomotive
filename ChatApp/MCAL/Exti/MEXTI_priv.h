/*
 * MEXTI_priv.h
 *
 *  Created on: Jun 7, 2023
 *      Author: Hassa
 */

#ifndef MEXTI_MEXTI_PRIV_H_
#define MEXTI_MEXTI_PRIV_H_

#define GICR_REG 	(*((volatile u8*)0x5B))  // Interrupts Enable
#define GIFR_REG 	(*((volatile u8*)0x5A))  // Interrupt Flags
#define MCUCR_REG 	(*((volatile u8*)0x55))  // INT0,INT1 sense Modes
#define MCUCSR_REG 	(*((volatile u8*)0x54)) // INT2 sense Mode

//MCUCR_REG
#define ISC00_BIT	0
#define ISC01_BIT 	1
#define ISC10_BIT	2
#define ISC11_BIT 	3

// MCUCSR_REG
#define ISC2_BIT		6

//GICR_REG
#define INT0	6
#define INT1	7
#define INT2	5

#define MEXTI_INT1_SC_SH 2

#define MEXTI_INT0_SC_MASK 0b11111100
#define MEXTI_INT1_SC_MASK 0b11110011



#endif /* MEXTI_MEXTI_PRIV_H_ */
