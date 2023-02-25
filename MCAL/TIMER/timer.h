/*
 * timer.h
 *
 * Created: 01/01/1980 01:14:43 AM
 *  Author: Mahmoud
 */ 

#ifndef TIMER_H_
#define TIMER_H_

/*		Utilities libraries includes	 */

// types library include
#include "../../Utilities/types.h"

// registers library include
#include "../../Utilities/registers.h"

// bit manipulation library include
#include "../../Utilities/bit_manipulation.h"

/*		typedefs	 */

/*		Macros		 */

#define CS00 0
#define CS02 2
#define TOV0 0

//functions prototypes
void TIMER0_init(void);				// initialize timer
void TIMER0_start(void);			// start timer
void TIMER0_stop(void);				// stop timer
void TIMER0_clear(void);			// clear timer flag
void TIMER0_set(uint64_t t_init);	// set timer initial value
uint8_t TIMER0_get(void);			// get timer flag value

#endif /* TIMER_H_ */