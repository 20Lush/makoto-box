#include <Arduino.h>

//This is a standard use library for the cheatbox that uses randomness to devate around a target value
//This is a precaution in the case that the game will pick up on perfect button inputs.
//
//- There is room for improvement here, while randomness is closer to human behavior than perfection,
//- human inputs are not random, the delay a human may input is a rather complex relationship between
//- variables in the game as well as physical stimuli. this would be more to the job of a NN or something
//- that is less predictable than a fixed % error rate.

const char TARGET_BUTTON_TRAVERSE = 8; //10ms
const char ERROR_BUTTON_TRAVERSE = 2; //2% deviation set
const char TARGET_PRESS_LENGTH = 4; //50ms
const char ERROR_PRESS_LENGTH = 2; //5% deviation set

int roll(int min, int max){ //take a random value from between bounds min and max

  int output = min + (random() % static_cast<int>(max - min + 1)); //stolen from stackoverflow kekw
  return output;

}

int fuzzyInt(int _theoreticalValue, int range){ //fuzzy the target(theoretical) value, by adding on a percentage RNG error

  double percentErr = 0.01 * roll(-range,range);
  int calc = _theoreticalValue + (_theoreticalValue*percentErr);

  return calc; //return an integer because arduino sad :(

}

int buttonTraverseTime(){ //humanized transition time between pressing buttons in a string

  return fuzzyInt(TARGET_BUTTON_TRAVERSE, ERROR_BUTTON_TRAVERSE);

};

int pressLength(){ //humanized keystroke length

  return fuzzyInt(TARGET_PRESS_LENGTH, ERROR_PRESS_LENGTH);

};