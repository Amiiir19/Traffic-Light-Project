/*
* FWD Traffic Light Project.c
*
* Created: 08-Oct-22 1:21:08 AM
* Author : Abdelrahman Mohamed Amir
*/

#include "MCAL/DIO Driver/dio.h"
#include "MCAL/Interrupt Driver/interrupt.h"
#include "MCAL/Others/bits.h"
#include "MCAL/Others/registers.h"
#include "MCAL/Timer Driver/timers.h"
#include "HAL/Button Driver/button.h"
#include "HAL/LED driver/led.h"
#include "APPLICATION/application.h"
extern  int trafficState;

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


int main(void)
{
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

