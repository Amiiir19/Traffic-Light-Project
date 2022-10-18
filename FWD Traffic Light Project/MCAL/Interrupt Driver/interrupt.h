/*
 * interrupt.h
 *
 * Created: 08-Oct-22 1:29:27 AM
 *  Author: Abdelrahman Mohamed Amir
 
 */ 


#ifndef INTERRUPT_H_
#define INTERRUPT_H_

/*Interrupt vectors*/

#define EXT_INT_0 __vector_1
#define EXT_INT_1 __vector_2
#define EXT_INT_2 __vector_3


#define sei() __asm__ __volatile__("sei":::"memory")


#define cli() __asm__ __volatile__("cli":::"memory")

#define ISR(INT_VECT)void INT_VECT(void) __attribute__ ((signal, used));\
void INT_VECT(void)


void interruptInit(void);


#endif /* INTERRUPT_H_ */