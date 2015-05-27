#include "blinkLED3.h"
#include "LED.h"
#include "timingControl.h"
#include "button.h"
#include "defination.h"
#include <stdio.h>

static int counter = 0 ;

void blinkLED3FiveTimesWhenButtonPressed(State *state, int time){
	static int previousTime = 0 ;


    switch (*state){
			case  INITIAL:	turnOffLED3();
      
                      if( ButtonIsPressed() && counter < 5)
                        *state = LED3_OFF;              
                      break;

			case LED3_OFF:	if( ButtonIsNotPressed()){
                        printf("off and button no press\n");
                        break;                  
                      }
                      
                      if( counterIsEqualFive(counter)){
                        *state = INITIAL;
                        break;
                      }
      
                     
                      turnOnLED3();
                      *state = LED3_ON;                     
                      break;
                      
			case  LED3_ON:  if( ButtonIsNotPressed()){
                        *state = LED3_OFF;
                        printf("on and button no press\n");
                        break;
                      }

                      if( counterIsEqualFive(counter)){
                        printf("counter reached 5\n");
			                	*state = INITIAL;
			                	break;
			                }
                                          
                      turnOffLED3();
                      *state = LED3_OFF;
                      counter++;
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

void resetCounter(){
  counter = 0;
}
