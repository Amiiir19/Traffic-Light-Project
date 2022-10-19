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
EN_DIO_error_t errorpan;
EN_DIO_error_t ledInit(unsigned char ledPort ,unsigned char ledPin){
	errorpan=dioInit(ledPort,ledPin,OUTPUT);
	return errorpan;
}
EN_DIO_error_t ledON(unsigned char ledPort ,unsigned char ledPin){
	
	errorpan=dioWrite(ledPort,ledPin,HIGH);
	return errorpan;

}
EN_DIO_error_t ledOFF(unsigned char ledPort ,unsigned char ledPin){
	errorpan=dioWrite(ledPort,ledPin,LOW);
	return errorpan;

}
EN_DIO_error_t ledToggle(unsigned char ledPort ,unsigned char ledPin){
	errorpan=dioToggle(ledPort,ledPin);
	return errorpan;
}

