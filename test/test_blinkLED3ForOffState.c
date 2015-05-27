#include "unity.h"
#include "blinkLED3.h"
#include "mock_LED.h"
#include "mock_button.h"

void setUp(void)
{
}

void tearDown(void)
{
}

void test_blinkLED3FiveTimesWhenButtonPressed_given_LED3_OFF_and_NoPressedButton_should_remain_LED3_OFF(void){
	State state = LED3_OFF;
  int delay = 200;
  
  buttonPressed_IgnoreAndReturn(0);

  blinkLED3FiveTimesWhenButtonPressed(&state, delay);
  TEST_ASSERT_EQUAL(LED3_OFF,state);
  
  resetCounter();
}

void test_blinkLED3FiveTimesWhenButtonPressed_given_LED3_OFF_and_PressedButton_should_remain_LED3_ON(void){
	State state = LED3_OFF;
  int delay = 200;
  
  buttonPressed_IgnoreAndReturn(1);
  turnOnLED3_IgnoreAndReturn(1);

  blinkLED3FiveTimesWhenButtonPressed(&state, delay);
  TEST_ASSERT_EQUAL(LED3_ON,state);
  
  resetCounter();
}


