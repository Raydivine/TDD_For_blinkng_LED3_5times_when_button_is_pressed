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


void test_blinkLED3FiveTimesWhenButtonPressed_given_LED3_ON_and_NoPressedButton_should_goto_LED3_OFF(void){
	State state = LED3_ON;
  int delay = 200;
  
  buttonPressed_IgnoreAndReturn(0);

  blinkLED3FiveTimesWhenButtonPressed(&state, delay);
  TEST_ASSERT_EQUAL(LED3_OFF,state);
  resetCounter();
}

void test_blinkLED3FiveTimesWhenButtonPressed_given_LED3_ON_and_PressedButton_should_goto_LED3_OFF(void){
	State state = LED3_ON;
  int delay = 200;
  
  buttonPressed_IgnoreAndReturn(1);
  turnOffLED3_IgnoreAndReturn(1);

  blinkLED3FiveTimesWhenButtonPressed(&state, delay);
  TEST_ASSERT_EQUAL(LED3_OFF,state);
  resetCounter();
}


void test_blinkLED3FiveTimesWhenButtonPressed_given_LED3_ON_input_2_times_should_have_sequence_of_state_LED3off_LED3on(void){
	State state = LED3_ON;
  int delay = 200;
  
  buttonPressed_IgnoreAndReturn(1);
  turnOnLED3_IgnoreAndReturn(1);
  turnOffLED3_IgnoreAndReturn(1);

  blinkLED3FiveTimesWhenButtonPressed(&state, delay); //off
  blinkLED3FiveTimesWhenButtonPressed(&state, delay); //on
  TEST_ASSERT_EQUAL(LED3_ON,state);
  resetCounter();
}

void test_blinkLED3FiveTimesWhenButtonPressed_given_LED3_ON_input_3_times_should_have_sequence_of_state_LED3off_LED3on_LED3off(void){
	State state = LED3_ON;
  int delay = 200;
  
  buttonPressed_IgnoreAndReturn(1);
  turnOnLED3_IgnoreAndReturn(1);
  turnOffLED3_IgnoreAndReturn(1);
  turnOnLED3_IgnoreAndReturn(1);
 
  blinkLED3FiveTimesWhenButtonPressed(&state, delay); //off
  blinkLED3FiveTimesWhenButtonPressed(&state, delay); //on
  blinkLED3FiveTimesWhenButtonPressed(&state, delay); //off
  TEST_ASSERT_EQUAL(LED3_OFF,state);
  resetCounter();
}

void test_blinkLED3FiveTimesWhenButtonPressed_given_LED3_ON_input_4_times_should_have_sequence_of_state_LED3off_LED3on_LED3off_LED3on(void){
	State state = LED3_ON;
  int delay = 200;
  
  buttonPressed_IgnoreAndReturn(1);
  turnOnLED3_IgnoreAndReturn(1);
  turnOffLED3_IgnoreAndReturn(1);
  turnOnLED3_IgnoreAndReturn(1);
  turnOffLED3_IgnoreAndReturn(1);
 

  blinkLED3FiveTimesWhenButtonPressed(&state, delay); //off
  blinkLED3FiveTimesWhenButtonPressed(&state, delay); //on
  blinkLED3FiveTimesWhenButtonPressed(&state, delay); //off
  blinkLED3FiveTimesWhenButtonPressed(&state, delay); //on
  TEST_ASSERT_EQUAL(LED3_ON,state);
  resetCounter();
}



void test_blinkLED3FiveTimesWhenButtonPressed_given_LED3_ON_10_times_should_goto_LED3on_and_this_is_number_fifthTimes_of_LED3On_state(void){
	State state = LED3_ON;
  int delay = 200;
  
  buttonPressed_IgnoreAndReturn(1);
  turnOnLED3_IgnoreAndReturn(1);
  turnOffLED3_IgnoreAndReturn(1);
  turnOnLED3_IgnoreAndReturn(1);
  turnOffLED3_IgnoreAndReturn(1);
  turnOffLED3_IgnoreAndReturn(1);
  turnOnLED3_IgnoreAndReturn(1);
  turnOffLED3_IgnoreAndReturn(1);
  turnOnLED3_IgnoreAndReturn(1);
  turnOffLED3_IgnoreAndReturn(1);
  turnOffLED3_IgnoreAndReturn(1);
  turnOffLED3_IgnoreAndReturn(1);
  turnOffLED3_IgnoreAndReturn(1);
  
  blinkLED3FiveTimesWhenButtonPressed(&state, delay); //off
  blinkLED3FiveTimesWhenButtonPressed(&state, delay); //on   1
  blinkLED3FiveTimesWhenButtonPressed(&state, delay); //off
  blinkLED3FiveTimesWhenButtonPressed(&state, delay); //on   2
  blinkLED3FiveTimesWhenButtonPressed(&state, delay); //off
  blinkLED3FiveTimesWhenButtonPressed(&state, delay); //on   3
  blinkLED3FiveTimesWhenButtonPressed(&state, delay); //off
  blinkLED3FiveTimesWhenButtonPressed(&state, delay); //on   4
  blinkLED3FiveTimesWhenButtonPressed(&state, delay); //off
  blinkLED3FiveTimesWhenButtonPressed(&state, delay); //on   5
  TEST_ASSERT_EQUAL(LED3_ON,state);   // this is number fifth times of On state
  resetCounter();
}

void test_blinkLED3FiveTimesWhenButtonPressed_given_LED3_ON_12_times_should_goto_INITIAL_state_because_it_already_blink_5_times(void){
	State state = LED3_ON;
  int delay = 200;
  
  buttonPressed_IgnoreAndReturn(1);
  turnOnLED3_IgnoreAndReturn(1);
  turnOffLED3_IgnoreAndReturn(1);
  turnOnLED3_IgnoreAndReturn(1);
  turnOffLED3_IgnoreAndReturn(1);
  turnOffLED3_IgnoreAndReturn(1);
  turnOnLED3_IgnoreAndReturn(1);
  turnOffLED3_IgnoreAndReturn(1);
  turnOnLED3_IgnoreAndReturn(1);
  turnOffLED3_IgnoreAndReturn(1);
  turnOffLED3_IgnoreAndReturn(1);
  turnOffLED3_IgnoreAndReturn(1);
  turnOffLED3_IgnoreAndReturn(1);
  turnOffLED3_IgnoreAndReturn(1);
  turnOffLED3_IgnoreAndReturn(1);
  
  blinkLED3FiveTimesWhenButtonPressed(&state, delay); //off
  blinkLED3FiveTimesWhenButtonPressed(&state, delay); //on   1
  blinkLED3FiveTimesWhenButtonPressed(&state, delay); //off
  blinkLED3FiveTimesWhenButtonPressed(&state, delay); //on   2
  blinkLED3FiveTimesWhenButtonPressed(&state, delay); //off
  blinkLED3FiveTimesWhenButtonPressed(&state, delay); //on   3
  blinkLED3FiveTimesWhenButtonPressed(&state, delay); //off
  blinkLED3FiveTimesWhenButtonPressed(&state, delay); //on   4
  blinkLED3FiveTimesWhenButtonPressed(&state, delay); //off
  blinkLED3FiveTimesWhenButtonPressed(&state, delay); //on   5
  blinkLED3FiveTimesWhenButtonPressed(&state, delay); //off
  blinkLED3FiveTimesWhenButtonPressed(&state, delay); //on   6
  TEST_ASSERT_EQUAL(INITIAL,state);   //  the state back to initial because already blink 5 times
  resetCounter();
}
