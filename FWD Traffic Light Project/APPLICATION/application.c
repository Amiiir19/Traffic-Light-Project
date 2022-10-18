
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
void yellowBlink(int timernum , int pedorcar){
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
	}
}