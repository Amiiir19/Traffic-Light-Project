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


void dioInit( unsigned char portNum ,unsigned char pinNum, unsigned char direction);
void dioWrite( unsigned char portNum ,unsigned char pinNum, unsigned char value);
void dioToggle( unsigned char portNum ,unsigned char pinNum);
void dioRead( unsigned char portNum ,unsigned char pinNum, unsigned char *value);




#endif /* DIO_H_ */