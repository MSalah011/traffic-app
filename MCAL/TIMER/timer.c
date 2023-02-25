/*
 * timer.c
 *
 * Created: 01/01/1980 01:14:28 AM
 *  Author: Mahmoud
 */ 

// include header file of driver
#include "timer.h"

// global variables declaration

// functions definitions

void TIMER0_init() // initialize timer
{
	// set to normal mode
	TCCR0=0x00;
}

void TIMER0_start()	// start timer
{
	// set prescaler to CLK/1024
	TCCR0 |=(1<<CS00)|(1<<CS02); 
}

void TIMER0_stop()				// stop timer
{
	// clear timer control register
	TCCR0 = 0x00;
}
void TIMER0_clear(void)				// clear timer flag
{
	// overwrite overflow flag by 1 to clear it to 0
	TIFR |= (1<<TOV0);
}
void TIMER0_set(uint64_t t_init)	// set timer initial value
{
	//set timer initial value
	TCNT0=t_init;
}
uint8_t TIMER0_get(void)		// get timer flag value
{
	return READ_BIT(TIFR, TOV0);
}