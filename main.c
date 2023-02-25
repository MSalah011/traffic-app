/*
 * GccApplication1.c
 *
 * Created: 12/01/2023 11:28:06 PM
 *  Author: Mahmoud
 */ 

#include "Application/app.h"
int main(void)
{
	APP_init();
	APP_start();
	/*DIO_init(PORT_B,3,OUT);
	DIO_init(PORT_C,3,IN);
	DIO_write(PORT_B,3,HIGH);
	DIO_write(PORT_B,3,LOW);
	LED_init(PORT_A,4);
	LED_on(PORT_A,4);
	LED_off(PORT_A,4);
	LED_toggle(PORT_A,4);
	LED_toggle(PORT_A,4);
	delay_ms(300);
	LED_toggle(PORT_A,4);*/
	return 0;	
}