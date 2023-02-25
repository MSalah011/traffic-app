/*
 * ext_int.c
 *
 * Created: 22/02/2023 11:41:36 PM
 *  Author: Mahmoud
 */ 
#include "ext_int.h"

void ExtInt0_init(void) //initalizes external interrupt 0 on rising edge
{
	INT_sei(); //enable global interrupts
	INT0_rising();		// choose external interrupt sense (rising edge)
	INT0_enable();		// Enable external interrupt 0 (INT0)
}