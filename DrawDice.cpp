#include "DrawDice.h"

//switch statment draws a unicode character for each die in arary dice
std::string DrawDice::Draw(int *dice, int _size){

  std::string ret = "";
  
  for(int d = 0; d < _size; d++){

    switch(dice[d]){

    case 1:
      ret += "\u2680";
      break;
    case 2:
      ret += "\u2681";
      break;
    case 3:
      ret += "\u2682";
      break;
    case 4:
      ret += "\u2683";
      break;
    case 5:
      ret += "\u2684";
      break;
    case 6:
      ret += "\u2685";
      break;
    }
  }

  return ret;
}
