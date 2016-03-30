// CPSC3620
// Project
// Board_Tile Class Implementation
// Written By: Eric Den Haan, Josh Vandenhoek, Lance Chisholm

#include "Board_Tile.h"

// Constructor
Board_Tile::Board_Tile(const string& s)
{
   // should we keep it as a string or represent as a 2D array?
}

// Destructor
Board_Tile::~Board_Tile()
{
}

void Board_Tile::nextConfigs()
{
   // just an idea of maybe how to do this:
   
   // iterate through the string "config" and find "0", the empty slot
   int emptypos = config.find('0');

   // switch statement, with the possible positions of '0' and their moves
   // depending on the position of '0', each case returns the possible new versions
   // of config
   switch(9)
   {
      case 1:
	 // can move D, L, R
      case 2:
	 // can move D, L
      case 3:
	 // can move U, R, D
      case 4:
	 // can move L, U, R, D
      case 5:
	 // can move L, U, D
      case 6:
	 // can move U, R
      case 7:
	 // can move L, U, R
      case 8:
	 // can move L, U
      default://position 0
         // can move D, U
   }
   // have to figure out how to return a list of Board_Tile objects from this function
}

int Board_Tile::numMoves()
{
   // needs to return the size of the moves_from_start string
}

int Board_Tile::Manhattan_Distance(const Board_Tile& goalconfig)
{
   // iterate through the current object
   // if currentobject[i] != goalconfig[i]
   // then subtract currentobject[i]'s position from goalconfig[i]'s position
   // and find the absolute value of that number
   // then sum up all of the absolute values and return this as manhattan distance
}


