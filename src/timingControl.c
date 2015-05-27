#include "timingControl.h"


int getCurrentTime(){
	static int counter = 0;
	static int currentTime = 0;

	if(counter++ >= 100){
		counter = 0;
		currentTime++;
	}

	return currentTime;
}

int waitWithoutDelay ( int previousTime, int delayMilliSecond){
	if(getCurrentTime() - previousTime > delayMilliSecond)
		return 1;
	return 0;
}