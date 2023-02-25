/*
 * interrupt.h
 *
 * Created: 01/02/2023 02:50:13 AM
 *  Author: Mahmoud
 */ 

#ifndef INTERRUPT_H_
#define INTERRUPT_H_

// utilities include
#include "../../Utilities/registers.h"
#include "../../Utilities/types.h"

/////////////////////////////////////////////////////////////////////////
///////*******************Interrupt vectors************************//////
/////////////////////////////////////////////////////////////////////////

/*		registers bits macros		 */

#define ISC00 0
#define ISC01 1
#define INT0 6

/*		External interrupt vectors		 */

// External interrupt request 0
#define EXT_INT_0 __vector_1

// global interrupts enable assembly code
#define sei() __asm__ __volatile__ ("sei" ::: "memory")

// ISR definition 
#define ISR(INT_VECT)void INT_VECT(void) __attribute__ ((signal,used)); \
void INT_VECT(void)

// Functions prototypes

void INT_sei(void); //enable global interrupts
void INT0_rising(void);		// choose external interrupt sense (rising edge)
void INT0_enable(void);		// Enable external interrupt 0 (INT0)

#endif /* INTERRUPT_H_ */