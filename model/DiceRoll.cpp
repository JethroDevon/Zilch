#include "DiceRoll.h"

DiceRoll::DiceRoll(){

  srand(time(NULL));
}

//toggles bool at specific index in bool array held
void DiceRoll::Hold(int _dienum){

  if(held[_dienum]){

    held[_dienum] = false;
  }else{

    held[_dienum] = true;
  }
}

//sets new values for each integer in dice that has not been held
void DiceRoll::Roll(){

  for(int d = 0; d < 7; d++){
    if(!held[d]){

      dice[d] = rand() % 6 + 1;
    }
  }
}

