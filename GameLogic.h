#ifndef GAMELOGIC_H
#define GAMELOGIC_H
/*

 This class will provide the game with its 
 scoring logic as well as detect the possible
 combinations of dice scores. 

 This way the CLI can make suggestions as to 
 what choices provide the best scores and can
 enable an AI to select the best scores.

 Constructor takes in an array of five integers
 or less and identifies appropriate score or a
 no score situation (aka a zilch).

*/
#include <string>
#include "DrawDice.cpp"
#include "DiceRoll.cpp"

class GameLogic{

  bool zilched;
  DrawDice dd;
  int selected, totalscore;
  
 public:

  GameLogic();

  //aggregate of 1s and fives
  int Max( int*, int);

  //this function detects a sequence from 1 to 6
  int Straight( int*, int);

  //this function detects any three pairs
  int Pairs( int*, int);
  
  //this function identifies multiple dice scores
  //by detecting 3 to 5 of a kind. else returns -1
  int Multiple( int*, int);
 
  //detects if roll of six dice come up with no score
  int Nothing( int*, int);

  //asks the user to input
  int Choice( int*, int);
};


#endif
