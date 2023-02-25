/*
 * led.h
 *
 * Created: 12/01/2023 10:55:27 PM
 *  Author: Mahmoud
 */ 
#ifndef LED_H_
#define LED_H_
//lower layers header files includes
/*		lower layers header files includes		*/
#include "../../MCAL/DIO/dio.h"

// typedefs
typedef enum EN_ledError_t
{
	LED_OK, WRONG_LED_PORT, WRONG_LED_PIN
}EN_ledError_t;

// Marcos
#define	CAR_PORT PORT_A
#define PED_PORT PORT_B
#define RED_LED 0		// red led pin
#define YELLOW_LED 1	// yellow led pin
#define GREEN_LED 2		// green led pin

// functions prototypes
EN_ledError_t LED_init(uint8_t PORT, uint8_t PIN);		// initialize pin direction to output
EN_ledError_t LED_on(uint8_t PORT, uint8_t PIN);		// turns led on
EN_ledError_t LED_off(uint8_t PORT, uint8_t PIN);		// turns led off
EN_ledError_t LED_toggle(uint8_t PORT, uint8_t PIN);	// toggle led

#endif /* LED_H_ */