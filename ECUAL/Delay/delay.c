/*
 * delay.c
 *
 * Created: 20/02/2023 04:50:56 PM
 *  Author: Mahmoud
 */ 

// include header file of driver
#include "delay.h"

// global variables declaration

// functions definitions
void delay_ms(uint64_t t_delay)		// delay function
{
	uint64_t t_init;
	uint8_t NofOverflows=1, overFlowCounter=0;
	if(t_delay<T_MAXDELAY)
	{
		// timer initial value if delay time is less than maximum delay time
		t_init=(T_MAXDELAY-t_delay)/T_TICK; 
 	}
	else if(t_delay==T_MAXDELAY)
	{
		// timer initial value to zero at delay time equals maximum delay time
		t_init=0; 
	}
	else
	{
		// at delay time > maximum delay time in one overflow
		NofOverflows=ceil(t_delay/T_MAXDELAY); // number of required overflows
		t_init=256-((t_delay/T_TICK)/NofOverflows); // timer initial value for first over flow 
	}
	//initialize timer to operate on normal mode
	TIMER0_init();
	// set timer initial value
	TIMER0_set(t_init);
	// start timer with CLK/1024 prescaler
	TIMER0_start();
	// loop until all overflows occur
	while( overFlowCounter < NofOverflows )
	{
		// busy loop until timer overflow flag is 1 or timer stops by clearing counter register 
		while( TIMER0_get()==0 && TCCR0!=0);
		// clear timer flag
		TIMER0_clear();
		// increment counter
		overFlowCounter++;
	}
	//stop timer
	TIMER0_stop();
}
