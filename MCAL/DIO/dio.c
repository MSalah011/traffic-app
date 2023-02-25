/*
 * dio.c
 *
 * Created: 12/01/2023 09:41:18 PM
 *  Author: Mahmoud
 */ 

// include header file of driver 
#include "dio.h"

// global variables declaration

// functions definitions

EN_dioError_t DIO_init(uint8_t PORT, uint8_t PIN, uint8_t direction)
{
	//check if pin number is between 0 and 7
	if (PIN>7 || PIN<0) return WRONG_PIN;
	//switch cases for ports 
	switch(PORT)
	{
		//case PORTA
		case PORT_A:
			//if direction is input
			if(direction == IN)
			{
				// set bit to zero (clear bit)
				CLEAR_BIT(DDRA, PIN) ; //input
				//return error state 0 (no errors "OK")
				return DIO_OK;
			}
			else if(direction == OUT) //if direction is output
			{
				// set bit to one (set bit)
				SET_BIT(DDRA, PIN); //output
				//return error state 0 (no errors "OK")
				return DIO_OK;
			}
			else
			{
				//else return wrong direction error state 1
				return WRONG_DIRECTION;
			}
			break;
		case PORT_B: //case PORTB
			//if direction is input
			if(direction == IN)
			{
				// set bit to zero (clear bit)
				CLEAR_BIT(DDRB, PIN); //input
				//return error state 0 (no errors "OK")
				return DIO_OK;
			}
			else if(direction == OUT) //if direction is output
			{
				// set bit to one (set bit)
				SET_BIT(DDRB, PIN); //output
				//return error state 0 (no errors "OK")
				return DIO_OK;
			}
			else
			{
				//else return wrong direction error state 1
				return WRONG_DIRECTION;
			}
			break;	
		case PORT_C: //case PORTC
			//if direction is input
			if(direction == IN)
			{
				// set bit to zero (clear bit)
				CLEAR_BIT(DDRC, PIN); //input
				//return error state 0 (no errors "OK")
				return DIO_OK;
			}
			else if(direction == OUT) //if direction is output
			{
				// set bit to one (set bit)
				SET_BIT(DDRC, PIN); //output
				//return error state 0 (no errors "OK")
				return DIO_OK;
			}
			else
			{
				//else return wrong direction error state 1
				return WRONG_DIRECTION;
			}
			break;
		case PORT_D: //case PORTD
			//if direction is input
			if(direction == IN)
			{
				// set bit to zero (clear bit)
				CLEAR_BIT(DDRD, PIN); //input
				//return error state 0 (no errors "OK")
				return DIO_OK;
			}
			else if(direction == OUT) //if direction is output
			{
				// set bit to one (set bit)
				SET_BIT(DDRD, PIN); //output
				//return error state 0 (no errors "OK")
				return DIO_OK;
			}
			else
			{
				//else return wrong direction error state 1
				return WRONG_DIRECTION;
			}
			break;
		default:
			return WRONG_PORT; //return error wrong port
			break;
	}
}

EN_dioError_t DIO_write(uint8_t PORT, uint8_t PIN,uint8_t val)
{
	//check if pin number is between 0 and 7
	if (PIN>7 || PIN<0) return WRONG_PIN;	
	//switch cases for ports 	
	switch(PORT)
	{
		case PORT_A: //case PORTA
			if(val == LOW) //if val is low
			{
				CLEAR_BIT(PORTA, PIN); // clear (set to low "logic 0")
				//return error state 0 (no errors "OK")
				return DIO_OK;
			}
			else if(val == HIGH) //if val is high
			{
				SET_BIT(PORTA, PIN); // set (set to high "logic 1")
				//return error state 0 (no errors "OK")
				return DIO_OK;
			}
			else
			{
				//else return wrong value error state 2
				return WRONG_VALUE;
			}
			break;
		case PORT_B: //case PORTB
			if(val == LOW) //if val is low
			{
				CLEAR_BIT(PORTB, PIN); // clear (set to low "logic 0")
				//return error state 0 (no errors "OK")
				return DIO_OK;
			}
			else if(val == HIGH) //if val is high
			{
				SET_BIT(PORTB, PIN); // set (set to high "logic 1")
				//return error state 0 (no errors "OK")
				return DIO_OK;
			}
			else
			{
				//else return wrong value error state 2
				return WRONG_VALUE;
			}
			break;
		case PORT_C: //case PORTC
			if(val == LOW) //if val is low
			{
				CLEAR_BIT(PORTC, PIN); // clear (set to low "logic 0")
				//return error state 0 (no errors "OK")
				return DIO_OK;
			}
			else if(val == HIGH) //if val is high
			{
				SET_BIT(PORTC, PIN); // set (set to high "logic 1")
				//return error state 0 (no errors "OK")
				return DIO_OK;
			}
			else
			{
				//else return wrong value error state 2
				return WRONG_VALUE;
			}
			break;
		case PORT_D: //case PORTD
			if(val == LOW) //if val is low
			{
				CLEAR_BIT(PORTD, PIN); // clear (set to low "logic 0")
				//return error state 0 (no errors "OK")
				return DIO_OK;
			}
			else if(val == HIGH) //if val is high
			{
				SET_BIT(PORTD, PIN); // set (set to high "logic 1")
				//return error state 0 (no errors "OK")
				return DIO_OK;
			}
			else
			{
				//else return wrong value error state 2
				return WRONG_VALUE;
			}
			break;			
		default:
			//error wrong port
			//else return wrong port error state 3
			return WRONG_PORT;
		break;
	}
	
}

EN_dioError_t DIO_toggle(uint8_t PORT, uint8_t PIN)
{
	//check if pin number is between 0 and 7
	if (PIN>7 || PIN<0) return WRONG_PIN;
	switch(PORT) //switch port cases
	{
		case PORT_A: //case PORTA
			TOGGLE_BIT(PORTA, PIN); // toggle pin
			//return error state 0 (no errors "OK")
			return DIO_OK;
			break;
		case PORT_B:
			TOGGLE_BIT(PORTB, PIN); // toggle pin
			//return error state 0 (no errors "OK")
			return DIO_OK;
			break;
		case PORT_C:
			TOGGLE_BIT(PORTC, PIN); // toggle pin
			//return error state 0 (no errors "OK")
			return DIO_OK;
			break;
		case PORT_D:
			TOGGLE_BIT(PORTD, PIN); // toggle pin
			//return error state 0 (no errors "OK")
			return DIO_OK;
			break;
		default:
			//error wrong port
			//else return wrong port error state 3
			return WRONG_PORT;
		break;
	}
	
}
EN_dioError_t DIO_read(uint8_t PORT, uint8_t PIN, uint8_t* val)
{	
	//check if pin number is between 0 and 7
	if (PIN>7 || PIN<0) return WRONG_PIN;
	//switch ports
	switch(PORT)
	{	
		case PORT_A:
			*val=READ_BIT(PINA, PIN);		// read pin value
			//return error state 0 (no errors "OK")
			return DIO_OK;
		break;
		case PORT_B:
			*val=READ_BIT(PINA, PIN);		// read pin value
			//return error state 0 (no errors "OK")
			return DIO_OK;
		break;
		case PORT_C:
			*val=READ_BIT(PINA, PIN);		// read pin value
			//return error state 0 (no errors "OK")
			return DIO_OK;		
		break;
		case PORT_D:
			*val=READ_BIT(PINA, PIN);		// read pin value
			//return error state 0 (no errors "OK")
			return DIO_OK;		
		break;
		default:
			//error wrong port
			//else return wrong port error state 3
			return WRONG_PORT;
		break;
	}	
}
