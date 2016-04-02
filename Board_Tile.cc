// CPSC3620
// Project
// Board_Tile Class Implementation
// Written By: Eric Den Haan, Josh Vandenhoek, Lance Chisholm

#include "Board_Tile.h"

// Constructor
Board_Tile::Board_Tile(const string& s)
{
   Array = new char *[3];
   for (int i = 0; i < 3; i++)
   {
      Array[i] = new char[3];
   }
   
   for(int i = 0; i < 3; i++)
   {
      for(int j = 0; j < 3; j++)
      {
	 Array[i][j] = s.at(i*3+j);
      }
   }

   config = s;
}

// Destructor
Board_Tile::~Board_Tile()
{
   for(int i = 0; i < 3; i++)
   {
      delete [] Array[i];
   }
 
   delete [] Array;
   Array = nullptr;
}

void Board_Tile::nextConfigs()
{
   // just an idea of maybe how to do this:
   
   // iterate through the string "config" and find "0", the empty slot
   // int emptypos = config.find('0');

   // switch statement, with the possible positions of '0' and their moves
   // depending on the position of '0', each case returns the possible new versions
   // of config
   /*switch(9)
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
   // have to figure out how to return a list of Board_Tile objects from this function*/
}

int Board_Tile::numMoves()
{
   // needs to return the size of the moves_from_start string
}

int Board_Tile::Manhattan_Distance(const Board_Tile& goalconfig)
{
   int m_dist = 0;
   for(int i = 0; i < 3; i++)
   {
      for(int j = 0; j < 3; j++)
      {
	 char initial_value = this->Array[i][j];
	 int initial_x = i;
	 int initial_y = j;

	 if(initial_value != '0')
	 {
	    for(int k = 0; k < 3; k++)
	    {
	       for(int l = 0; l < 3; l++)
	       {
		  char goal_value = goalconfig.Array[k][l];
		  int goal_x = k;
		  int goal_y = l;
		  
		  if(initial_value == goal_value)
		  {
		     m_dist += abs(initial_x - goal_x) + abs(initial_y - goal_y);
		  }
	       }
	    }
	 }
      }
   }
   return m_dist;
}

//print function (<< operator)
ostream& operator<<(ostream& os, const Board_Tile& B)
{
   for(int i = 0; i < 3; i++)
   {
      for(int j = 0; j < 3; j++)
      {
	 os  << B.Array[i][j] << " ";
      }
      os << endl;
   }
   return os;
}


