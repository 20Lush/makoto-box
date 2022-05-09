#include "Actions.h"

// 3rd STRIKE  -----------------------------------------------
void karakusa(char direction){

  hc(invertedDirection(direction)); //half circle back
  pressButton(btnPins[5]); //HK
  delay(300);

}


void IIsuper(char direction){

  qc(direction);
  qc(direction);
  pressButton(btnPins[5]);

}
//----------------------------------------------------------------

// STRIVE --------------------------------------------------------

void parry(char direction){

  hc(invertedDirection(direction), true); //the true flag here just means it follows strive's half circle format (terminates forward)
  pressButton(btnPins[3]); //or is it 2 kekwait
  delay(30);

}

//----------------------------------------------------------------


void setup() {

  initializeButtons();
  randomSeed(millis()); //seed rng on startup

}

void loop() {

  //continuously seed rng? how resource intensive might that be? will it make a difference?
  //a more advanced humanization engine might need real time calculation - much to think about


  if(status()){

    if(buttonIsPressed(inputPins[0]))
      parry(left);
    else if(buttonIsPressed(inputPins[1]))
      parry(right);

  }

  else if(!status()){

    if(buttonIsPressed(inputPins[2]))
      karakusa(left);
  
    else if(buttonIsPressed(inputPins[3]))
      karakusa(right);

    if(buttonIsPressed(inputPins[0]))
      IIsuper(left);
  
    else if(buttonIsPressed(inputPins[1]))
      IIsuper(right);

  }


  
}




