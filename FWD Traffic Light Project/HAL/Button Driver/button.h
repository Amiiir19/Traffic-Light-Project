/*
 * button.h
 *
 * Created: 08-Oct-22 1:30:52 AM
 *  Author: Abdelrahman Mohamed Amir
 */ 


#ifndef BUTTON_H_
EN_DIO_error_t buttonInit(unsigned char buttonPort, unsigned char buttonPin );
EN_DIO_error_t buttonRead(unsigned char buttonPort, unsigned char buttonPin , unsigned char *value);




#endif /* BUTTON_H_ */