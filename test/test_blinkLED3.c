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

void test_blinkLED3FiveTimesWhenButtonPressed_given_INITIAL_and_NoPressedButton_should_remain_initial(void){
	State state = INITIAL;
  int delay = 200;
  
  buttonPressed_IgnoreAndReturn(0);
  turnOffLED3_IgnoreAndReturn(0);

  blinkLED3FiveTimesWhenButtonPressed(&state, delay);
  TEST_ASSERT_EQUAL(INITIAL,state);
}

void test_blinkLED3FiveTimesWhenButtonPressed_given_INITIAL_and_PressedButton_should_goto_LED3_OFF(void){
	State state = INITIAL;
  int delay = 200;
  
  buttonPressed_IgnoreAndReturn(1);
  turnOffLED3_IgnoreAndReturn(0);

  blinkLED3FiveTimesWhenButtonPressed(&state, delay);
  TEST_ASSERT_EQUAL(LED3_OFF,state);
}

void test_blinkLED3FiveTimesWhenButtonPressed_given_LED3_ON_and_NoPressedButton_should_goto_LED3_OFF(void){
	State state = LED3_ON;
  int delay = 200;
  
  buttonPressed_IgnoreAndReturn(0);

  blinkLED3FiveTimesWhenButtonPressed(&state, delay);
  TEST_ASSERT_EQUAL(LED3_OFF,state);
}

void test_blinkLED3FiveTimesWhenButtonPressed_given_LED3_ON_and_PressedButton_should_goto_LED3_OFF(void){
	State state = LED3_ON;
  int delay = 200;
  
  buttonPressed_IgnoreAndReturn(1);
  turnOffLED3_IgnoreAndReturn(0);

  blinkLED3FiveTimesWhenButtonPressed(&state, delay);
  TEST_ASSERT_EQUAL(LED3_OFF,state);
}




