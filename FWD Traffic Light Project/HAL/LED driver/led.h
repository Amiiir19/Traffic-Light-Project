/*
 * led.h
 *
 * Created: 08-Oct-22 1:30:26 AM
 *  Author: Abdelrahman Mohamed Amir
 */ 


#ifndef LED_H_
#define LED_H_

EN_DIO_error_t ledInit(unsigned char ledPort ,unsigned char ledPin);
EN_DIO_error_t ledON(unsigned char ledPort ,unsigned char ledPin);
EN_DIO_error_t ledOFF(unsigned char ledPort ,unsigned char ledPin);
EN_DIO_error_t ledToggle(unsigned char ledPort ,unsigned char ledPin);




#endif /* LED_H_ */