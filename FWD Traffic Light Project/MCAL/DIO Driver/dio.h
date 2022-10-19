/*
 * dio.h
 *
 * Created: 08-Oct-22 1:29:00 AM
 *  Author: Abdelrahman Mohamed Amir
 */ 


#ifndef DIO_H_
#define DIO_H_



#define PORT_A 'A'
#define PORT_B 'B'
#define PORT_C 'C'
#define PORT_D 'D'

enum mode {
	INPUT,OUTPUT
}mode;
enum state{
	LOW,HIGH
}state;


typedef enum EN_DIO_error_t
{
	DIO_WRONG_PIN_NUMBER,
	DIO_WRONG_PORT_NUMBER,
	DIO_WRONG_DIRECTION,
	DIO_OK
}EN_DIO_error_t ;


EN_DIO_error_t dioInit( unsigned char portNum ,unsigned char pinNum, unsigned char direction);
EN_DIO_error_t dioWrite( unsigned char portNum ,unsigned char pinNum, unsigned char value);
EN_DIO_error_t dioToggle( unsigned char portNum ,unsigned char pinNum);
EN_DIO_error_t dioRead( unsigned char portNum ,unsigned char pinNum, unsigned char *value);




#endif /* DIO_H_ */