/*
 * dio.h
 *
 * Created: 12/01/2023 09:41:30 PM
 *  Author: Mahmoud
 */ 
#ifndef DIO_H_
#define DIO_H_
/*		Utilities libraries includes	 */
// types library include
#include "../../Utilities/types.h"
// registers library include
#include "../../Utilities/registers.h"
// bit manipulation library include
#include "../../Utilities/bit_manipulation.h"
/*		typedefs	 */
typedef enum EN_dioError_t
{
	DIO_OK, WRONG_DIRECTION, WRONG_VALUE, WRONG_PORT, WRONG_PIN
}EN_dioError_t;
/*		Macros		 */
// port macros
#define PORT_A 'A'
#define PORT_B 'B'
#define PORT_C 'C'
#define PORT_D 'D'
// direction macros
#define	IN 0
#define OUT 1
// value macros
#define LOW 0
#define HIGH 1
//functions prototypes
EN_dioError_t DIO_init(uint8_t PORT, uint8_t PIN, uint8_t direction);	// initialize pin direction
EN_dioError_t DIO_write(uint8_t PORT, uint8_t PIN, uint8_t val);		// write data on pin
EN_dioError_t DIO_toggle(uint8_t PORT, uint8_t PIN);					// toggle pin value
EN_dioError_t DIO_read(uint8_t PORT, uint8_t PIN, uint8_t* val);		// read pin value
#endif /* DIO_H_ */