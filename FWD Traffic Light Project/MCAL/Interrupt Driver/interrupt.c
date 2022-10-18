/*
* interrupt.c
*
* Created: 08-Oct-22 1:29:15 AM
*  Author: Abdelrahman Mohamed Amir
*/

#include "../../MCAL/DIO Driver/dio.h"
#include "../../MCAL/Interrupt Driver/interrupt.h"
#include "../../MCAL/Others/bits.h"
#include "../../MCAL/Others/registers.h"
#include "../../MCAL/Timer Driver/timers.h"
#include "../../HAL/Button Driver/button.h"
#include "../../HAL/LED driver/led.h"
#include "interrupt.h"

void interruptInit(void){
	sei();
	setBit(MCUCR,0);
	setBit(MCUCR,1);
	setBit(GICR,6);
	setBit (SREG ,7);
 
}