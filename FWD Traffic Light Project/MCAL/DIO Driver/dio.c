/*
* dio.c
*
* Created: 08-Oct-22 1:28:52 AM
*  Author: Abdelrahman Mohamed Amir
*/
#include "../../MCAL/DIO Driver/dio.h"
#include "../../MCAL/Interrupt Driver/interrupt.h"
#include "../../MCAL/Others/bits.h"
#include "../../MCAL/Others/registers.h"
#include "../../MCAL/Timer Driver/timers.h"
#include "../../HAL/Button Driver/button.h"
#include "../../HAL/LED driver/led.h"
#include "dio.h"


EN_DIO_error_t  dioInit( unsigned char portNum ,unsigned char pinNum, unsigned char direction){
	
	
	if (pinNum>7){
		return DIO_WRONG_PIN_NUMBER;
	}
	if(direction != OUTPUT || direction != INPUT){
		return DIO_WRONG_DIRECTION;
	}
	
	
	switch(portNum){
		case PORT_A :
		if(direction == OUTPUT){
			setBit(directionPortA,pinNum);
		}
		else if (direction == INPUT){
			//INPUT
			clrBit(directionPortA,pinNum);
		}
		break;
		
		case PORT_B :
		if(direction == OUTPUT){
			//OUTPUT
			setBit(directionPortB,pinNum);

		}
		else if (direction == INPUT){
			//INPUT
			clrBit(directionPortB,pinNum);
		}
		break;
		case PORT_C :
		if(direction == OUTPUT){
			//OUTPUT
			setBit(directionPortC,pinNum);
		}
		else if (direction == INPUT){
			//INPUT
			clrBit(directionPortC,pinNum);
		}
		break;
		case PORT_D :
		if(direction == OUTPUT){
			setBit(directionPortD,pinNum);
		}
		else if (direction == INPUT){
			//INPUT
			clrBit(directionPortD,pinNum);
		}
		break;
			default:
			return DIO_WRONG_PORT_NUMBER;
	}
	return DIO_OK;
}

EN_DIO_error_t  dioWrite( unsigned char portNum ,unsigned char pinNum, unsigned char value){
	
	if (pinNum>7){
		return DIO_WRONG_PIN_NUMBER;
	}
	
	switch(portNum){
		case PORT_A :
		if(value==HIGH){
			setBit(PORTA,pinNum);

		}
		else if(value ==LOW){
			clrBit(PORTA,pinNum);

		}
		break;
		case PORT_B :
		if(value==HIGH){
			setBit(PORTB,pinNum);
		}
		else if(value ==LOW){
			clrBit(PORTB,pinNum);
		}
		break;
		case PORT_C :
		if(value==HIGH){
			setBit(PORTC,pinNum);
		}
		else if(value ==LOW){
			clrBit(PORTC,pinNum);
		}
		break;
		case PORT_D :
		if(value==HIGH){
			setBit(PORTD,pinNum);
		}
		else if(value ==LOW){
			clrBit(PORTD,pinNum);
		}
		break;
			default:
			return DIO_WRONG_PORT_NUMBER;
	}
	return DIO_OK;
}

EN_DIO_error_t  dioToggle( unsigned char portNum ,unsigned char pinNum)
{
	if (pinNum>7){
		return DIO_WRONG_PIN_NUMBER;
	}
	switch(portNum){
		case PORT_A :
		toggleBit(PORTA,pinNum);
		
		break;
		case PORT_B :
		toggleBit(PORTB,pinNum);
		
		break;
		case PORT_C :
		toggleBit(PORTC,pinNum);
		
		break;
		case PORT_D :
		toggleBit(PORTD,pinNum);
		
		break;
		default: return DIO_WRONG_PORT_NUMBER;
	}
	return DIO_OK;
}

EN_DIO_error_t dioRead( unsigned char portNum ,unsigned char pinNum, unsigned char *value){
	
	if (pinNum>7){
		return DIO_WRONG_PIN_NUMBER;
	}
	
	switch (portNum){
		case PORT_A:
		*value = readBit(PINA,pinNum);
		
		break;
		case PORT_B:
		*value = readBit(PINB,pinNum);
		
		break;
		case PORT_C:
		*value = readBit(PINC,pinNum);
		
		break;
		case PORT_D:
		*value = readBit(PIND,pinNum);
		
		break;
		default:
		return DIO_WRONG_PORT_NUMBER;
	}
	return DIO_OK;
}