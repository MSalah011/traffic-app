/*
 * interrupt.c
 *
 * Created: 22/02/2023 10:50:55 PM
 *  Author: Mahmoud
 */ 

#include "interrupt.h"

void INT_sei(void) //enable global interrupts
{
	sei();
}
void INT0_rising(void)		// choose external interrupt sense (rising edge)
{
	MCUCR |= (1<<ISC00) | (1<<ISC00); 
}
void INT0_enable(void)		// Enable external interrupt 0 (INT0)
{
	GICR |= (1<<INT0);
}