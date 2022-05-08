#include "Actions.h"

//some moves

void karakusaCombo(char direction){

  hc(invertedDirection(direction)); //half circle back
  pressButton(btnPins[6]); //HK
  delay(2500);
  // //possible short delay here due to needing to time the kara correctly
  pressButton(btnPins[2]); //HP
  delay(buttonTraverseTime()+10);
  qc(direction); //quarter circle forward
  pressDoubleButton(btnPins[1], btnPins[2]); //two punch buttons. index dependant on key binds in game, so extra headache there

}


void setup() {

  initializeButtons();
  randomSeed(millis()); //seed rng on startup

}

void loop() {

  //continuously seed rng? how resource intensive might that be? will it make a difference?
  //a more advanced humanization engine might need real time calculation - much to think about

  if(buttonIsPressed(INPUT_BUTTON_ID_1)) //these bare button ID's are not viable i need to figure something out, probably add them to the btnPin array
    karakusaCombo(left);
  
  else if(buttonIsPressed(INPUT_BUTTON_ID_2))
    karakusaCombo(right);
  
}




