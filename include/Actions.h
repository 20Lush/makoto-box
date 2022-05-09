#include "ButtonHandler.h"

void hc(char direction, bool finish = false){ //half circle that terminates in the direction that is passed in.
                        //so if you pass in right it will start from left and half-circle to the left
                        //hf-back should be inputted with the opposite direction the character is

    holdButton(invertedDirection(direction));
    delay(pressLength()); //6 or 4
    holdButton(down);
    delay(pressLength()); //3 or 1
    releaseButton(invertedDirection(direction));
    delay(pressLength()); //2          
    holdButton(direction);                  
    delay(pressLength()); //1 or 3       
    releaseButton(down);                 
    delay(pressLength()); //4 or 6       
    releaseButton(direction);

    if(!finish)
        return;
    else if(finish){
        holdButton(invertedDirection(direction));
        delay(pressLength());
        releaseButton(invertedDirection(direction));
    }


}

void qc(char direction){ //quarter circle that terminates in the direction that is passed in

    holdButton(down);
    delay(pressLength()); //2
    holdButton(direction);
    delay(pressLength()); //3 or 1
    releaseButton(down);
    delay(pressLength()); //6 or 4
    releaseButton(direction);
    // delay(pressLength());

    // pressButton(down);
    // pressDoubleButton(down, direction);
    // pressButton(direction);

}

void dragonInput(char direction, int action){ //dragon input in the direction passed in, terminates with ability

    qc(direction);
    qc(direction);
    pressButton(btnPins[action]);

}
