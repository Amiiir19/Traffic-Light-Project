/*
* registers.h
*
* Created: 08-Oct-22 1:32:26 AM
*  Author: Abdelrahman Mohamed Amir
*/


#ifndef REGISTERS_H_
#define REGISTERS_H_

//PORT A
#define PORTA *((volatile unsigned char*) 0x3B)
#define directionPortA *((volatile unsigned char*) 0x3A)
#define PINA *((volatile unsigned char*) 0x39)
//PORT B
#define PORTB *((volatile unsigned char*) 0x38)
#define directionPortB *((volatile unsigned char*) 0x37)
#define PINB *((volatile unsigned char*) 0x36)
//PORT C
#define PORTC *((volatile unsigned char*) 0x35)
#define directionPortC *((volatile unsigned char*) 0x34)
#define PINC *((volatile unsigned char*) 0x33)
//PORT D
#define PORTD *((volatile unsigned char*) 0x32)
#define directionPortD *((volatile unsigned char*) 0x31)
#define PIND *((volatile unsigned char*) 0x30)

//timers
#define TCCR0 *((volatile unsigned char*) 0x53) 
#define TCNT0 *((volatile unsigned char*) 0x52) 
#define TIFR *((volatile unsigned char*) 0x58)
#define TIMSK *((volatile unsigned char*) 0x59)
#define OCR0  (*(volatile unsigned char*) 0x5C)


//Timer1 registers
#define TCCR1A *((volatile unsigned char*)0x4F)
#define TCCR1B *((volatile unsigned char*)0x4E)
#define TCNT1H *((volatile unsigned char*)0x4D)
#define TCNT1L *((volatile unsigned char*)0x4C)

//interrupts
#define MCUCR *((volatile unsigned char*) 0x55) 
#define MCUCSR *((volatile unsigned char*) 0x54) 
#define GICR *((volatile unsigned char*) 0x5B)
#define GIFR *((volatile unsigned char*) 0x5A)
#define SREG *((volatile unsigned char*)0x5f)      


#endif /* REGISTERS_H_ */