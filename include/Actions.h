#include "ButtonHandler.h"

void hc(char direction){ //half circle that terminates in the direction that is passed in.
                        //so if you pass in right it will start from left and half-circle to the left
                        //hf-back should be inputted with the opposite direction the character is

    holdButton(invertedDirection(direction));
    delay(pressLength()); //6 or 4
    holdButton(down);
    delay(pressLength()); //3 or 1
    releaseButton(invertedDirection(direction));//Okay if you made it down to here i am not proud of what I had to do here.
    delay(pressLength()); //2                   //I can 100% streamline this by completely redoing how ButtonHandler ghosts inputs.
    holdButton(direction);                      //The problem that called for this patchwork solution was that FG's delete your input string 
    delay(pressLength()); //1 or 3              //if your move buttons/stick returns to neutral (5). pressButton has that return built in, which
    releaseButton(down);                        //is good for ability registering, but the exact opposite of what I need for movement inputs
    delay(pressLength()); //4 or 6              //I basically needed to bleed movement inputs into each other in order to get proper inputs.
    releaseButton(direction);                   //What I need is a function that has this bleed-in bult in, but cleans up the garbage inputs
    delay(pressLength());                       //that get left over during that operation. I need a ghost hand handling my virtual stick :)


    // pressButton(invertedDirection(direction));
    // pressDoubleButton(down, invertedDirection(direction));
    // pressButton(down);
    // pressDoubleButton(down, direction);
    // pressButton(direction);

}

void qc(char direction){ //quarter circle that terminates in the direction that is passed in

    holdButton(down);
    delay(pressLength()); //2
    holdButton(direction);
    delay(pressLength()); //3 or 1
    releaseButton(down);
    delay(pressLength()); //6 or 4
    releaseButton(direction);
    delay(pressLength());

    // pressButton(down);
    // pressDoubleButton(down, direction);
    // pressButton(direction);

}

void dragonInput(char direction, int action){ //dragon input in the direction passed in, terminates with ability

    qc(direction);
    qc(direction);
    pressButton(btnPins[action]);

}