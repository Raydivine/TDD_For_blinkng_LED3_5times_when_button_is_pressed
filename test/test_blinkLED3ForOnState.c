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
  // turnOnLED3_IgnoreAndReturn(1);
  // turnOffLED3_IgnoreAndReturn(1);
 

  blinkLED3FiveTimesWhenButtonPressed(&state, delay);
  TEST_ASSERT_EQUAL(LED3_OFF,state);
  blinkLED3FiveTimesWhenButtonPressed(&state, delay);
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
  // turnOffLED3_IgnoreAndReturn(1);
 

  blinkLED3FiveTimesWhenButtonPressed(&state, delay);
  TEST_ASSERT_EQUAL(LED3_OFF,state);
  blinkLED3FiveTimesWhenButtonPressed(&state, delay);
  TEST_ASSERT_EQUAL(LED3_ON,state);
  blinkLED3FiveTimesWhenButtonPressed(&state, delay);
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
 

  blinkLED3FiveTimesWhenButtonPressed(&state, delay);
  TEST_ASSERT_EQUAL(LED3_OFF,state);
  blinkLED3FiveTimesWhenButtonPressed(&state, delay);
  TEST_ASSERT_EQUAL(LED3_ON,state);
  blinkLED3FiveTimesWhenButtonPressed(&state, delay);
  TEST_ASSERT_EQUAL(LED3_OFF,state);
  blinkLED3FiveTimesWhenButtonPressed(&state, delay);
  TEST_ASSERT_EQUAL(LED3_ON,state);
  resetCounter();
}

void test_blinkLED3FiveTimesWhenButtonPressed_given_LED3_ON_input_5_times_should_have_sequence_of_state_LED3off_LED3on_LED3off_LED3on_LED3off(void){
	State state = LED3_ON;
  int delay = 200;
  
  buttonPressed_IgnoreAndReturn(1);
  turnOnLED3_IgnoreAndReturn(1);
  turnOffLED3_IgnoreAndReturn(1);
  turnOnLED3_IgnoreAndReturn(1);
  turnOffLED3_IgnoreAndReturn(1);
  turnOffLED3_IgnoreAndReturn(1);
 

  blinkLED3FiveTimesWhenButtonPressed(&state, delay);
  TEST_ASSERT_EQUAL(LED3_OFF,state);
  blinkLED3FiveTimesWhenButtonPressed(&state, delay);
  TEST_ASSERT_EQUAL(LED3_ON,state);
  blinkLED3FiveTimesWhenButtonPressed(&state, delay);
  TEST_ASSERT_EQUAL(LED3_OFF,state);
  blinkLED3FiveTimesWhenButtonPressed(&state, delay);
  TEST_ASSERT_EQUAL(LED3_ON,state);
  blinkLED3FiveTimesWhenButtonPressed(&state, delay);
  TEST_ASSERT_EQUAL(LED3_OFF,state);
  resetCounter();
}

void test_blinkLED3FiveTimesWhenButtonPressed_given_LED3_ON_input_8_times_should_have_get_the_number_fifthTimes_LED3on_state(void){
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
 
 

  blinkLED3FiveTimesWhenButtonPressed(&state, delay); //1
  blinkLED3FiveTimesWhenButtonPressed(&state, delay); //2
  blinkLED3FiveTimesWhenButtonPressed(&state, delay); //3
  blinkLED3FiveTimesWhenButtonPressed(&state, delay); //4
  blinkLED3FiveTimesWhenButtonPressed(&state, delay); //5
  blinkLED3FiveTimesWhenButtonPressed(&state, delay); //6
  blinkLED3FiveTimesWhenButtonPressed(&state, delay); //7
  blinkLED3FiveTimesWhenButtonPressed(&state, delay); //8
  TEST_ASSERT_EQUAL(LED3_ON,state);
  resetCounter();
}

void test_blinkLED3FiveTimesWhenButtonPressed_given_LED3_ON_input_10_times_should_have_get_the_state_of_INITIAL_because_the_counter_is_reached_5_so_it_cant_turn_on_anymore(void){
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
  
  blinkLED3FiveTimesWhenButtonPressed(&state, delay); //1
  blinkLED3FiveTimesWhenButtonPressed(&state, delay); //2
  blinkLED3FiveTimesWhenButtonPressed(&state, delay); //3
  blinkLED3FiveTimesWhenButtonPressed(&state, delay); //4
  blinkLED3FiveTimesWhenButtonPressed(&state, delay); //5
  blinkLED3FiveTimesWhenButtonPressed(&state, delay); //6
  blinkLED3FiveTimesWhenButtonPressed(&state, delay); //7
  blinkLED3FiveTimesWhenButtonPressed(&state, delay); //8
  blinkLED3FiveTimesWhenButtonPressed(&state, delay); //9
  blinkLED3FiveTimesWhenButtonPressed(&state, delay); //10
  TEST_ASSERT_EQUAL(INITIAL,state);
  resetCounter();
}


