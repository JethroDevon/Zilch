/*
              ╔═════╗
 ╔════════════╣ZILCH╠════════════╗
 ║            ╚═════╝            ║
 ║                               ║                   
 ║ Zilch is a multi player dice  ║
 ║ game that a hippie called     ║
 ║ Charlie Barley taught me when ║
 ║ I was a kid.                  ║
 ║            ╔═════╗            ║
 ╠════════════╣RULES╠════════════╣
              ╚═════╝
*/

//#include "Player.h"
//#include "CLI.h"
#include "GameLogic.cpp"
#include <iostream>
#include <string>

DiceRoll dr;

int main(){

  dr.Roll();
  GameLogic gl( dr.dice, dr.held);
}
