#include "unity.h"
#include "blinkLED3.h"
#include "mock_LED.h"
#include "mock_timingControl.h"
#include "mock_button.h"

void setUp(void)
{
}

void tearDown(void)
{
}

void test_blinkLED3FiveTimesWhenButtonPressed_given_pressed_1_times_should_on_times_then_off(void){
	State *state = INITIAL;
  int delay = 200;
  
  buttonPressed_IgnoreAndReturn(0);
  // getCurrentTime_IgnoreAndReturn(0);
  // getCurrentTime_IgnoreAndReturn(200);
  
  blinkLED3FiveTimesWhenButtonPressed(state, delay);
  
}
