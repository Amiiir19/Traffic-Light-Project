#include "../MCAL/DIO Driver/dio.h"
#include "../MCAL/Interrupt Driver/interrupt.h"
#include "../MCAL/Others/bits.h"
#include "../MCAL/Others/registers.h"
#include "../MCAL/Timer Driver/timers.h"
#include "../HAL/Button Driver/button.h"
#include "../HAL/LED driver/led.h"
#include "application.h"

unsigned char buttonState = 0;
int trafficState = 0;
int testMode=0;

ISR (EXT_INT_0){
	
	//disable interrupt TO AVOID LONG PRESS AND DOUBLE PRESS
	clrBit(GICR,6);
	// The ISR Function
	/* Here we check the last state of the car leds to know in which behavior will we act with the interrupt*/

	switch(trafficState){
		case 1 :
		break;
		case 2 :
		// Yellow Blinking both yellow leds and the timer is inside the function
		// we pass a Variable of 1 to the function that will make the function use timer1 not 0
		
		yellowBlink(1,2);
		pedPass();
		timer1Set(0);
		yellowBlink(1,0);
		break;
		case 3 :
		yellowBlink(1,1);
		pedPass();
		timer1Set(0);
		yellowBlink(1,0);
		carPass();
		break;
	}

	//enable interrupt AGAIN
	interruptInit();
	setBit(GIFR,6);
}



void APP_start (){
	while (1)
	{
		if (testMode==1){
			timer1Set(1);
			// Button Driver Function Test
			unsigned char x=0;
			buttonRead(PORT_C,2,&x);
			if(	x==1){

					//led toggle function test
				ledToggle(PORT_C,1);
			}
		}
		else{
			normalMode();
		}
	}
}


void APP_init(){
	
	
	if(testMode==1){
		/*
		led 0 c always high
		led 1 c on
		timer 5 second
		led 1 c off
		loop
		timer 1 second
		check button
		if pressed toggle led
		*/
		
		
		//DIO Driver Function Test
		dioInit(PORT_C,0,OUTPUT);
		dioWrite(PORT_C,0,HIGH);
		
		//led Driver Function Test
		ledInit(PORT_C,1);
		ledON(PORT_C,1);

		
		//button Driver Function Test
		buttonInit(PORT_C,2);
		
		// timer test
		timerInit();
		ledON(PORT_C,1);
		timer0Set(2000);
		ledOFF(PORT_C,1);
	}
	
	else{
		setupMode();
	}
	
}

void setupMode(void)
{

	ledInit(PORT_A, 0);
	ledInit(PORT_A, 1);
	ledInit(PORT_A, 2);
	ledInit(PORT_B, 0);
	ledInit(PORT_B, 1);
	ledInit(PORT_B, 2);
	buttonInit(PORT_D, 2);
	interruptInit();
	timerInit();

}

void normalMode(void)
{
	pedPass();
	timer0Set(2000);
	yellowBlink(0,0); // yellowblink(used timer 0 for normal 1 for interrupt , which yellow led will blink 0 car)
	carPass();
	timer0Set(2000);
}

void pedPass(){
	ledON(PORT_A, 0);
	ledOFF(PORT_A, 1);
	ledOFF(PORT_A, 2);
	ledON(PORT_B, 2);
	ledOFF(PORT_B, 1);
	ledOFF(PORT_B, 0);
	trafficState = 1;
}
void carPass(){
	ledON(PORT_A, 2);
	ledOFF(PORT_A, 0);
	ledOFF(PORT_A, 1);
	ledON(PORT_B, 0);
	ledOFF(PORT_B, 1);
	ledOFF(PORT_B, 2);
	trafficState = 3;
}
yellowError yellowBlink(int timernum , int pedorcar){
	// 0 means car blink
	// 1 means ped blink
	if (timernum==0){
		if (pedorcar==0){
			trafficState = 2;
			ledON(PORT_B,0);
			ledOFF(PORT_B,1);
			ledOFF(PORT_B,2);
			ledOFF(PORT_A,0);
			ledOFF(PORT_A,2);
			ledON(PORT_A,1);
			for(int count=0 ;count<=4;count++ ){
				timer0Set(0);
				ledToggle(PORT_A,1);
			}
		}
		else if(pedorcar==1)
		{
			trafficState = 3;
			ledON(PORT_A,2);
			ledOFF(PORT_A,1);
			ledOFF(PORT_A,0);
			ledOFF(PORT_B,0);
			ledOFF(PORT_B,2);
			ledON(PORT_B,1);
			for(int count=0 ;count<=4;count++ ){
				timer0Set(0);
				ledToggle(PORT_B,1);
			}
		}
		else{
			return wrong_mode_choice;
		}
	}
	else if(timernum==1){
		if (pedorcar==0){
			trafficState = 2;
			ledON(PORT_B,0);
			ledOFF(PORT_B,1);
			ledOFF(PORT_B,2);
			ledOFF(PORT_A,0);
			ledOFF(PORT_A,2);
			ledON(PORT_A,1);
			for(int count=0 ;count<=10;count++ ){
				timer1Set(1);
				ledToggle(PORT_A,1);
			}
		}
		else if(pedorcar==1)
		{
			trafficState = 3;
			ledON(PORT_A,2);
			ledOFF(PORT_A,1);
			ledOFF(PORT_A,0);
			ledOFF(PORT_B,0);
			ledOFF(PORT_B,2);
			ledON(PORT_B,1);
			for(int count=0 ;count<=10;count++ ){
				timer1Set(1);
				ledToggle(PORT_B,1);
			}
		}
		else if(pedorcar==2)
		{
			trafficState = 3;
			ledON(PORT_A,1);
			ledOFF(PORT_A,2);
			ledOFF(PORT_A,0);
			ledOFF(PORT_B,0);
			ledOFF(PORT_B,2);
			ledON(PORT_B,1);
			for(int count=0 ;count<=10;count++ ){
				timer1Set(1);
				ledToggle(PORT_B,1);
				ledToggle(PORT_A,1);
			}
			ledOFF(PORT_A,1);
			ledOFF(PORT_B,1);
			
		}
		else{
			return wrong_mode_choice;
		}
	}
	else{
		return wrong_timern_number;
	}
	return yellowok;
}