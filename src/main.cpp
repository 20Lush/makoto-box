#include "Actions.h"

//some moves

void karakusaCombo(char direction){

  hc(invertedDirection(direction)); //half circle back
  pressButton(btnPins[5]); //HK
  delay(300);
  // pressButton(btnPins[2]); //HP
  // delay(buttonTraverseTime()+10); //10ms+fuzzy buffer to allow for HP to fully go through before EX-Hayate
  // qc(direction); //quarter circle forward
  // pressDoubleButton(btnPins[1], btnPins[2]);

}

//supers?

void IIsuper(char direction){

  qc(direction);
  qc(direction);
  pressButton(btnPins[5]);

}


void setup() {

  initializeButtons();
  randomSeed(millis()); //seed rng on startup

}

void loop() {

  //continuously seed rng? how resource intensive might that be? will it make a difference?
  //a more advanced humanization engine might need real time calculation - much to think about

  if(buttonIsPressed(inputPins[2]))
    karakusaCombo(left);
  
  else if(buttonIsPressed(inputPins[3]))
    karakusaCombo(right);

  if(buttonIsPressed(inputPins[0]))
    IIsuper(left);
  
  else if(buttonIsPressed(inputPins[1]))
    IIsuper(right);
  
}




