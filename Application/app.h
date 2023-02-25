/*
 * app.h
 *
 * Created: 12/01/2023 11:51:25 PM
 *  Author: Mahmoud
 */ 


#ifndef APP_H_
#define APP_H_

// lower layers header files includes
#include "../ECUAL/LED/led.h"
#include "../ECUAL/Delay/delay.h"
#include "../ECUAL/EXT_INT/ext_int.h"

// typedefs
typedef enum EN_mode_t
{
	NORMAL_YELLOW_BLINK, PED_YELLOW_BLINK
}EN_mode_t;
// macros

// functions prototypes
void APP_init(void);
void APP_start(void);
void ped_Mode(void);
void yellow_blink(EN_mode_t mode);

#endif /* APP_H_ */