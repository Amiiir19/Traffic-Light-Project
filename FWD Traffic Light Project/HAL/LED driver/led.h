/*
 * led.h
 *
 * Created: 08-Oct-22 1:30:26 AM
 *  Author: Abdelrahman Mohamed Amir
 */ 


#ifndef LED_H_
#define LED_H_


void ledInit(unsigned char ledPort ,unsigned char ledPin);
void ledON(unsigned char ledPort ,unsigned char ledPin);
void ledOFF(unsigned char ledPort ,unsigned char ledPin);
void ledToggle(unsigned char ledPort ,unsigned char ledPin);




#endif /* LED_H_ */