/*
 * delay.h
 *
 * Created: 20/02/2023 04:51:12 PM
 *  Author: Mahmoud
 */ 

#ifndef DELAY_H_
#define DELAY_H_
// math library include to use ceil function
#include <math.h>

//lower layers header files includes
/*		lower layers header files includes		*/
#include "../../MCAL/TIMER/timer.h"
// typedefs

// Marcos
#define T_TICK 1.024		//T_tick=1024*10^-6 s = 1024 us
#define T_MAXDELAY 262.144	//T_maxDelay=T_tick*256=262.144 ms

// functions prototypes
void delay_ms(uint64_t t_delay);		// delay function

#endif /* DELAY_H_ */