/*
* timers.h
*
* Created: 08-Oct-22 1:29:41 AM
*  Author: Abdelrahman Mohamed Amir
*/


#ifndef TIMERS_H_
#define TIMERS_H_
typedef enum timerError{
	wrongMode,
	timerok
	}timerError;

void timerInit(void);
timerError timer0Set(int x);
timerError timer1Set(int yellow);

#endif /* TIMERS_H_ */