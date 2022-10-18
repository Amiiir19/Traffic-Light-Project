/*
 * button.h
 *
 * Created: 08-Oct-22 1:30:52 AM
 *  Author: Abdelrahman Mohamed Amir
 */ 


#ifndef BUTTON_H_
#define BUTTON_H_

void buttonInit(unsigned char buttonPort, unsigned char buttonPin );
void buttonRead(unsigned char buttonPort, unsigned char buttonPin , unsigned char *value);




#endif /* BUTTON_H_ */