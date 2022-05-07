#include "Latency.h" //look here for pressLength()
#include <Arduino.h>

//     9 10 11  ------------- 12 13 14
//   ____________________________________
//  |                                    |
//  |   left  down          1  2  3  4   |
//  |             right      5  6  7  8  |
//  |        up                          |
//  |                                    |
//  |____________________________________|
// 
// numbers here refer to the index in btnPins array. btnPin[1] will call the arduino pin number of that button

//arduin pin ID's VVVVVVV
//movement buttons. declared explicitly so I can use them later as movement "vectors"
const char down = 2;
const char up = 15;
const char right = 16;
const char left = 10;

char btnPins[14] = {}; //fill out the pin assignments for this. future me problem
char movementPins[] = {up, down, left, right};

void initializeButtons(void){ //arduino pin settings and setting all btns HIGH

  for(unsigned int i = 0; i<sizeof(movementPins); i++){ //iterate through button array
    pinMode(movementPins[i], OUTPUT);
    digitalWrite(movementPins[i], HIGH);
  }

  for(unsigned int i = 0; i<sizeof(btnPins); i++){ //iterate through button array
    pinMode(btnPins[i], OUTPUT);
    digitalWrite(btnPins[i], HIGH);
  }

}

void pressButton(char button){ //generic trivial button press function. Presses an button!

  digitalWrite(button, 0);
  delay(pressLength());
  digitalWrite(button, 1);
  delay(buttonTraverseTime());

  // ---- essay alert ----
  //this is a bit of a weird implementation. traverseTime can definitally be improved.
  //right now its basically just a pressLength but with different parameters.

  //A better version would probably get passed in some sort of modifier that allows one to
  //more easily control how long it takes the arduino to "traverse" to a different button.

  //though I hate to think about this, building a data set from ML would probably yield an engine
  //that sees more human-like traversal times rather than it revolving around a fixed value.

  //think about it: a human's reaction time is stronger in some situations and weaker in others.
  //a human going from btnPin[1] to btnPin[2] will see a lower traverseTime, where as from btnPin[1] to btnPin[8] is going to be higher.
  //but in a full combo, the traverse time is likely to be more uniform no matter the distance, because its a rehearsed action.
  //and even further, there may be deliberate lag between inputs by the human to more accuately time it.
  //---- end essay ---- 

}

void pressDoubleButton(char button1, char button2){ //generic trivial button pressfunction that supports pressing two buttons simultaneously

  digitalWrite(button1, 0);
  digitalWrite(button2, 0);
  delay(pressLength());
  digitalWrite(button1, 1);
  digitalWrite(button2, 1);
  delay(buttonTraverseTime());

}

char invertedDirection(char direction){ //idk how to do this without verbose conditional statements. shouts out to the compiler

  if(direction == up)
    return down;
  else if(direction == down)
    return up;

  if(direction == left)
    return right;
  else if(direction == right)
    return left;

  else
    return 0; //i have no clue if this is going to fuck something up
}