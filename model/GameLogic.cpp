#include "GameLogic.h"

//passing a diceroll object into game logic will list the scoring possibilities and
//points component
GameLogic::GameLogic(DiceRoll _d):_dice(_d){

  int count = 0;
  int tmp[6];

  //initialises tmp with each dice that has not been _dice.held
  for(int a = 0; a < 6 ; a++){

    if(!_dice.held[a]){
 
      tmp[count] = _dice.dice[a];
      count++;
    }
  }

  //implement some kind of logic that can list all the possibilities
  //and take a choice as an argument but thats sort of for the CLI but then its not
  ///count is for rolling dice logic not tracking held dice
  
  Max( _dice, count);
  Multiple( _dice, count);
  Straight( _dice, count);
  Pairs( _dice, count);

}

//simply adds up all the 1s and 5s
int GameLogic::Max(DiceRoll _dice, int _size){
  
  int aggregate = 0;
  
  for(int x = 0; x < _size; x++){

    if(_dice.dice[x] == 1){
      
      aggregate += 100;
      std::cout << "\u2860";
    }
  
    if(_dice.dice[x] == 5){
      
      aggregate += 50;
      std::cout << "\u2861";
    }
  }

  if(aggregate == 0)
    return -1;

  std::cout << dd.Draw( _dice.dice, _size) << "Aggregate Score : " << aggregate;
  return aggregate;
}


//finds the most common _dice->dice value and uses a scoring
//algorithm - returns -1 if no multiples found
int GameLogic::Multiple(DiceRoll _dice, int _size){

  int count = 0;
  int best = 0;
  int val = 0;

  std::string output = "Multiple Score: ";

    //search for highest multiple
    for(int num = 1; num < 7; num++){
      for(int x = 0; x < _size; x++){
	if( _dice.dice[x] == num){

	  count++;
	  if(count > best){

	    val = num;
	    best = count;
	  }
	}
      }
      
      count = 0;
    }

  //if three or more of a value have been found create score
  if(best > 2){

    int multiplier = 100;
    
    if(val == 1)
      multiplier = 1000;

    int score = (val * multiplier) * (best - 2);
    
    //creates an array to feed _dice->dice draw with
    int dice2[best];
    for(int n = 0; n < best; n++)
      dice2[n] = best;
    
    std::cout << dd.Draw( _dice.dice, best) << "Multiples Score : " << score;
    return score;
 
  }else{

    return -1;
  }
}

//checks that 1 to 6 exist otherwise returns -1
int GameLogic::Straight(DiceRoll _dice, int _size){

  bool isStraight;
  
  //straight will only work with 6 _dice->dice
  if(_size != 6)
    return -1;

  //iteritivley search for each number 1 to 6 or return false
  for(int x = 0; x < 6; x++){
    isStraight = false;
    for(int y = 0; y < 6; y++){
   
      if(_dice.dice[y] == x){

	isStraight = true;
	break;
      }
    }

    //if the next number is not found in the _dice->dice array it is
    //not a straight
    if(!isStraight){

      return -1;
    }
  }

  std::cout << dd.Draw( _dice.dice, 6) << " Straight Score : 1500";
  return 1500;
}

//to see if theres a possible set of three pairs of even the
//same two integers eg: 3-3 3-3 4-4 there must always be an
//even number of integers so if a number occurs three times
//or once a set of pairs is not possible
int GameLogic::Pairs(DiceRoll _dice, int _size){

  //six _dice->dice have to be available for this to apply
  if(_size != 6)
    return -1;
  
  //index one symbolises 1 on a die, if 3 or 1 occures at any
  //index a pair has not been found!
  int pairs[6] = { 0,0,0,0,0,0};

  for(int x = 0; x < _size; x++)
    for(int num = 0; num < 6; num++){

      if(_dice.dice[x] == num + 1)
	pairs[num] = pairs[num] + 1;
    }

  for(int n : pairs){

    if(n == 1 || n == 3){

      return -1;
    }
  }

  std::cout << dd.Draw( _dice.dice, 6) << " Pairs Score : 1500"; 
  return 1500;
}

//detects if a nothing with six _dice->dice is found if nothing with less than six
//zilched is set to true
int GameLogic::Nothing( DiceRoll _dice, int _size){

  //if a nothing is detected with less than six _dice->dice it is a zilch
  if(_size < 6)
    zilched = true;

  if(!zilched)

  std::cout << dd.Draw( _dice.dice, 6) << " Absolutely Nothing Score : 500";

  return 500;
}

//display different combinations available

//displays all possible scores as well as individual 1s and 5s
//next to an index number so user can make a selection to add to
//their score
int GameLogic::Choice(DiceRoll _dice, int _size){

  if(zilched){

    return -1;
  }else{

    //displays possibilities with selection numbers
    
    //ask user for individual selections 
    
    //ask user to select a combination
    
  }
}
