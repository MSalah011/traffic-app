/*
 * app.c
 *
 * Created: 12/01/2023 11:51:38 PM
 *  Author: Mahmoud
 */ 
// driver header file include
#include "app.h"

// global variables declaration
uint8_t pedMode;

// functions definitions
void APP_init(void)
{
	//initalize car and pedestrian LEDs as outputs
	LED_init(CAR_PORT, RED_LED);
	LED_init(CAR_PORT, YELLOW_LED);
	LED_init(CAR_PORT, GREEN_LED);
	LED_init(PED_PORT, RED_LED);
	LED_init(PED_PORT, YELLOW_LED);
	LED_init(PED_PORT, GREEN_LED);
	
	// interrupt initalization
	ExtInt0_init();
	
}

void APP_start(void)
{
	while(1)
	{
		pedMode=0;
		//1.turn car green and ped red on
		LED_on(CAR_PORT, GREEN_LED);
		LED_on(PED_PORT, RED_LED);
		//2.wait 5 seconds
		delay_ms(5000);
		//3.if pedMode==1 start pedmode then continue
		if(pedMode==1)
		{
			ped_Mode();
			continue;
		}
		//4.blink car yellow for 5 seconds
		pedMode=1;
		yellow_blink(PED_YELLOW_BLINK);
		//5.turn car green and ped red off
		LED_off(CAR_PORT, GREEN_LED);
		LED_off(PED_PORT, RED_LED);
		//6.turn car red and ped green on
		LED_on(CAR_PORT, RED_LED);
		LED_on(PED_PORT, GREEN_LED);
		//7.wait 5 seconds
		delay_ms(5000);
		//8.blink car yellow for 5 seconds
		pedMode=0;
		yellow_blink(NORMAL_YELLOW_BLINK);
		//9.if pedMode==1 start pedmode then continue
		if(pedMode==1)
		{
			ped_Mode();
			continue;
		}	
		//10.turn car red and ped green off
		LED_off(CAR_PORT, RED_LED);
		LED_off(PED_PORT, GREEN_LED);
	}
	
}
void ped_Mode(void)
{
	//1.ped & car yellow_blink for 5 seconds
	yellow_blink(PED_YELLOW_BLINK);
	//2.car green off and red on
	LED_off(CAR_PORT, GREEN_LED);
	LED_on(CAR_PORT, RED_LED);
	//3.ped red off and green on
	LED_off(PED_PORT, RED_LED);
	LED_on(PED_PORT, GREEN_LED);
	//4.wait 5 seconds
	delay_ms(5000);
	//5.ped & car yellow blink for 5 seconds
	yellow_blink(PED_YELLOW_BLINK);
	//6.ped green off and red on
	LED_off(PED_PORT, GREEN_LED);
	LED_on(PED_PORT, RED_LED);
	//7.car red off
	LED_off(CAR_PORT, RED_LED);
	
}
void yellow_blink(EN_mode_t mode)
{
	int counter;
	switch(mode){
		case NORMAL_YELLOW_BLINK: //case car yellow only blinking in normal mode
		for(counter=0;counter<10;counter++) // toggle led 10 times each of 0.5 sec of total 5 sec
		{
			//toggle car yellow LED 
			LED_toggle(CAR_PORT, YELLOW_LED);
			//toggle pedestrian yellow LED
			LED_toggle(PED_PORT, YELLOW_LED);
			// wait 0.5 sec
			delay_ms(500);
			//get out of loop if ped mode is activated
			if(pedMode==1)break;
		}
		// turn yellow LEDs off
		LED_off(CAR_PORT, YELLOW_LED);
		LED_off(PED_PORT, YELLOW_LED);
		break;
		case PED_YELLOW_BLINK: // case car and pedestrian yellow LEDs blinks together in pedestrian mode
		for(counter=0;counter<10;counter++) // toggle led 10 times each of 0.5 sec of total 5 sec
		{
			//toggle car yellow LED
			LED_toggle(CAR_PORT, YELLOW_LED);
			//toggle pedestrian yellow LED
			LED_toggle(PED_PORT, YELLOW_LED);
			// wait 0.5 sec
			delay_ms(500);
		}
		// turn yellow LEDs off
		LED_off(CAR_PORT, YELLOW_LED);
		LED_off(PED_PORT, YELLOW_LED);
		break;
		default:
		break;
		
	}
}

ISR(EXT_INT_0)
{
	//activate pedestrian mode if is not activated and stop timer
	if (pedMode==0) 
	{
		pedMode=1;
		TIMER0_stop();
	}
}