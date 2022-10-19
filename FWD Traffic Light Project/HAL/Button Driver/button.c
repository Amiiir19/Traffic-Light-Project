/*
* button.c
*
* Created: 08-Oct-22 1:30:37 AM
*  Author: Abdelrahman Mohamed Amir
*/
#include "../../MCAL/DIO Driver/dio.h"
#include "../../MCAL/Interrupt Driver/interrupt.h"
#include "../../MCAL/Others/bits.h"
#include "../../MCAL/Others/registers.h"
#include "../../MCAL/Timer Driver/timers.h"
#include "../../HAL/Button Driver/button.h"
#include "../../HAL/LED driver/led.h"
#include "button.h"
EN_DIO_error_t errorbutton;
EN_DIO_error_t buttonInit(unsigned char buttonPort, unsigned char buttonPin ){
	errorbutton=dioInit(buttonPort,buttonPin,INPUT);
	return errorbutton;
}
EN_DIO_error_t buttonRead(unsigned char buttonPort, unsigned char buttonPin , unsigned char *value){
	errorbutton=dioRead(buttonPort,buttonPin,value);
	return errorbutton;
}