/*
 * led.c
 *
 * Created: 08-Oct-22 1:30:16 AM
 *  Author: Abdelrahman Mohamed Amir
 */ 
#include "../../MCAL/DIO Driver/dio.h"
#include "../../MCAL/Interrupt Driver/interrupt.h"
#include "../../MCAL/Others/bits.h"
#include "../../MCAL/Others/registers.h"
#include "../../MCAL/Timer Driver/timers.h"
#include "../../HAL/Button Driver/button.h"
#include "../../HAL/LED driver/led.h"
#include "led.h"

void ledInit(unsigned char ledPort ,unsigned char ledPin){
	dioInit(ledPort,ledPin,OUTPUT);
}
void ledON(unsigned char ledPort ,unsigned char ledPin){
	
	dioWrite(ledPort,ledPin,HIGH);
}
void ledOFF(unsigned char ledPort ,unsigned char ledPin){
	dioWrite(ledPort,ledPin,LOW);
}
void ledToggle(unsigned char ledPort ,unsigned char ledPin){
	dioToggle(ledPort,ledPin);
}
