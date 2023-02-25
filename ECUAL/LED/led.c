/*
 * led.c
 *
 * Created: 12/01/2023 10:55:37 PM
 *  Author: Mahmoud
 */ 
// include header file of driver
#include "led.h"
// global variables declaration

// functions definitions
EN_ledError_t LED_init(uint8_t PORT, uint8_t PIN)
{	
	switch(DIO_init(PORT, PIN, OUT)) // initiallizes LED port to output
	{
		case DIO_OK:
			return LED_OK;
			break;
		case WRONG_PORT:
			return WRONG_LED_PORT;
			break;
		default:
			return WRONG_LED_PIN;
			break;
	}
}

EN_ledError_t LED_on(uint8_t PORT, uint8_t PIN)
{	
	switch(DIO_write(PORT, PIN, HIGH)) // set LED port to high (turn on LED on pull down resistor mode)
	{
		case DIO_OK:
			return LED_OK;
			break;
		case WRONG_PORT:
			return WRONG_LED_PORT;
			break;
		default:
			return WRONG_LED_PIN;
			break;
	}
}

EN_ledError_t LED_off(uint8_t PORT, uint8_t PIN)
{	 
	switch(DIO_write(PORT, PIN, LOW)) // set LED port to low (turn on LED off pull down resistor mode)
	{
		case DIO_OK:
			return LED_OK;
			break;
		case WRONG_PORT:
			return WRONG_LED_PORT;
			break;
		default:
			return WRONG_LED_PIN;
			break;
	}
}

EN_ledError_t LED_toggle(uint8_t PORT, uint8_t PIN)
{
	switch(DIO_toggle(PORT, PIN)) // toggle led port from low to high or from high to low
	{
		case DIO_OK:
			return LED_OK;
			break;
		case WRONG_PORT:
			return WRONG_LED_PORT;
			break;
		default:
			return WRONG_LED_PIN;
			break;
	}
}