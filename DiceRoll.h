#ifndef DICEROLL_H
#define DICEROLL_H

/*

This class simulates the roling and holding
back of up to five dice as well as displaying
the dice unicode symbols when promted

*/

#include <iostream>
#include <string>
#include <stdlib.h>
#include <time.h>

class DiceRoll{
  
 public:
    
  //five dice named 1 to 5 will be initialised with
  //random values from 1 to six when role dice is called
  int dice[6];

  //dice that have been held will not be roled, index numbers
  //corelate with the dice array
  bool held[6];

  DiceRoll();

  //integer passed in this function toggles whether die is
  //held back or not
  void Hold(int);

  //performs the dice roll
  void Roll();
  
};

#endif
