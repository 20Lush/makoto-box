#include "ButtonHandler.h"

void hc(char direction){ //half circle that terminates in the direction that is passed in

    pressButton(invertedDirection(direction));
    pressDoubleButton(down, invertedDirection(direction));
    pressButton(down);
    pressDoubleButton(down, direction);
    pressButton(direction);

}

void qc(char direction){ //quarter circle that terminates in the direction that is passed in

    pressButton(down);
    pressDoubleButton(down, direction);
    pressButton(direction);

}

void dragonInput(char direction, int action){ //dragon input in the direction passed in, terminates with ability

    qc(direction);
    qc(direction);
    pressButton(btnPins[action]);

}