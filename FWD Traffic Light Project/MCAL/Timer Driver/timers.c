/*
* timers.c
*
* Created: 08-Oct-22 1:29:52 AM
*  Author: Abdelrahman Mohamed Amir
*/
#include "../../MCAL/DIO Driver/dio.h"
#include "../../MCAL/Interrupt Driver/interrupt.h"
#include "../../MCAL/Others/bits.h"
#include "../../MCAL/Others/registers.h"
#include "../../MCAL/Timer Driver/timers.h"
#include "../../HAL/Button Driver/button.h"
#include "../../HAL/LED driver/led.h"
#include "timers.h"

void timerInit()
{
	// 1. set timer mode to normal mode
	TCCR0 = 0X00; // Normal mode
	// 2. Set timer initial value to 0
	TCNT0 = 0x00;
	TCCR1B=1;
}

// Here i implement this function
void timerStart0(unsigned int preScalar, unsigned int number_of_overflow)
{
	unsigned int counter = 0;
	switch (preScalar)
	{
		case 1:
		setBit(TCCR0,0);
		break;
		case 8:
		setBit(TCCR0,1);
		break;
		case 64:
		setBit(TCCR0,0);
		setBit(TCCR0,1);
		break;
		case 256:
		setBit(TCCR0,2);
		break;
		case 1024:
		setBit(TCCR0,0);
		setBit(TCCR0,2);
		break;
		default:
		break;
	}
	// overflow times
	while (counter < number_of_overflow)
	{
		//  overflow set
		while (readBit(TIFR,0) == 0);
		// Clear the overflow
		setBit(TIFR,0);
		counter++;
	}
}

void timerStop0()
{
	TCCR0 = 0x00;
}
timerError timer0Set(int x){
	if(x==2000){
		timerStart0(256,77);
	}
	else if(x==0) {
		timerStart0(256,15);
	}
	else{
		return wrongMode;
	}
	return timerok;
	timerStop0();
}
timerError timer1Set(int yellow){
	// here i use prescalar 64 for and 256 for 5 second
	TCCR1B = 0x00;
	if(yellow==1){
		TCNT1H = 0xE1;
		TCNT1L = 0x7C;
		//make the prescalar of 64
		setBit(TIFR,2);
		setBit(TCCR1B,1);
		setBit(TCCR1B,0);
	}
	else if(yellow==0) {
		//tick = 256/10^6
		//max ticks = 2^16
		// no. of ticks = 5 second / tick
		// initial value = max ticks - no. of ticks needed = B3B5
		TCNT1H =  0xB3;
		TCNT1L = 0xB5;
		//make the prescalar of 256
		setBit(TIFR,2);
		setBit(TCCR1B,2);
	}
	
	else{
	return wrongMode;
	}
	while ((readBit(TIFR,2)) == 0);
	//setBit(TIFR,2);

	// stop the timer
	TCCR1B = 0x00;
	return timerok;
}
