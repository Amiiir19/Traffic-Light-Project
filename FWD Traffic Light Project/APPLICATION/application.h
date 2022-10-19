/*
* application.h
*
* Created: 08-Oct-22 1:28:34 AM
*  Author: Abdelrahman Mohamed Amir
*/


#ifndef APPLICATION_H_
#define APPLICATION_H_
typedef enum yellowError{
	wrong_timern_number,
	wrong_mode_choice,
	yellowok
	}yellowError;

void APP_start (void);
void APP_init(void);
void setupMode(void);
void normalMode(void);
void pedPass(void);
void carPass(void);
yellowError yellowBlink(int timernum, int pedorcar);
#endif /* APPLICATION_H_ */