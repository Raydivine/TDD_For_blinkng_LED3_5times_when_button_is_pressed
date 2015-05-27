#include "blinkLED3.h"
#include "LED.h"
#include "timingControl.h"
#include "button.h"
#include "defination.h"

void blinkLED3FiveTimesWhenButtonPressed(State *state, int time){
	static int previousTime = 0 ;
	static int counter = 0 ;

	switch (*state){
			case  INITIAL:	turnOffLED3();
      
                      if( ButtonIsPressed() && counter < 5){
                        *state = LED3_OFF;
                        break;
                       }

			case LED3_OFF:	if( ButtonIsNotPressed())
                        break;
                      
                      if( counterIsEqualFive(counter)){
                        *state = INITIAL;
                        break;
                      }
      
                      if( waitWithoutDelay( previousTime,time) ){
                        previousTime = getCurrentTime();
                        turnOnLED3();
                        *state = LED3_ON;
                      }
                      break;
                      
			case  LED3_ON:  if( ButtonIsNotPressed()){
                        *state = LED3_OFF;
                        break;
                      }

                      if( counterIsEqualFive(counter)){
			                	*state = INITIAL;
			                	break;
			                }
                      
                      if( waitWithoutDelay( previousTime,time) ){
                        previousTime = getCurrentTime();
                        turnOffLED3();
                        *state = LED3_OFF;
                        counter++;
                      }
                      break;

			default: 		break;
		}
}

int ButtonIsNotPressed(){

	int readButton ;
	readButton = buttonPressed();

	if(readButton == 0 )
		return 1;
	return 0;
}

int ButtonIsPressed(){

	int readButton ;
	readButton = buttonPressed();

	if(readButton == 1 )
		return 1;
	return 0;
}

int counterIsEqualFive( int counter){

	 if(counter>=5)
	 	return 1;
	 return 0;
}