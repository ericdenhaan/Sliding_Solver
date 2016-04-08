// CPSC3620
// Project
// Board_Tile Class Implementation
// Written By: Eric Den Haan, Josh Vandenhoek, Lance Chisholm

#include "Board_Tile.h"

//Constructor
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

//Copy Constructor
Board_Tile::Board_Tile(const Board_Tile& copy)
{
  Array = new char*[3];
  for (int i = 0; i < 3; i++)
    {
      Array[i] = new char[3];
    }
  
  for (int i = 0; i < 3; i++)
    {
      for(int j = 0; j < 3; j++)
	{
	  Array[i][j] = copy.Array[i][j];
	}
    }
  
  config = copy.config;
  moves_from_start = copy.moves_from_start;
  totalCost = copy.totalCost;
}

//Destructor
Board_Tile::~Board_Tile()
{
  for(int i = 0; i < 3; i++)
    {
      delete [] Array[i];
    }
  
  delete [] Array;
  Array = nullptr;
}

//nextConfigs Function
//finds the next possible moves and returns them as a list
list<Board_Tile> Board_Tile::nextConfigs()
{
  list<Board_Tile> nextConfigList;
  
  int indexi;
  int indexj;
  
  for (int i=0; i < 3; i++)
    {
      for (int j =0; j < 3; j++)
	{
	  if (this->Array[i][j] == '0')
	    {
	      indexi = i;
	      indexj = j;
	    }	 
	}
    }
  
  int emptypos = indexi*3 + indexj;
  
  //switch statement, with the possible positions of '0' and their moves
  //depending on the position of '0', each case returns the possible new versions
  //of config
  switch(emptypos)
    {
    case 1:
      //can move D, L, R
      nextConfigList.push_back(leftMove(indexi,indexj));
      nextConfigList.push_back(rightMove(indexi,indexj));
      nextConfigList.push_back(downMove(indexi,indexj));
      break;
      
    case 2:
      //can move D, L
      nextConfigList.push_back(leftMove(indexi,indexj));
      nextConfigList.push_back(downMove(indexi,indexj));
      break;
      
    case 3:
      //can move U, R, D
      nextConfigList.push_back(rightMove(indexi,indexj));
      nextConfigList.push_back(upMove(indexi,indexj));
      nextConfigList.push_back(downMove(indexi,indexj));
      break;
      
    case 4:
      //can move L, U, R, D
      nextConfigList.push_back(leftMove(indexi,indexj));
      nextConfigList.push_back(rightMove(indexi,indexj));
      nextConfigList.push_back(upMove(indexi,indexj));
      nextConfigList.push_back(downMove(indexi,indexj));
      break;
      
    case 5:
      //can move L, U, D
      nextConfigList.push_back(leftMove(indexi,indexj));
      nextConfigList.push_back(upMove(indexi,indexj));
      nextConfigList.push_back(downMove(indexi,indexj));
      break;
      
    case 6:
      //can move U, R
      nextConfigList.push_back(rightMove(indexi,indexj));
      nextConfigList.push_back(upMove(indexi,indexj));	 
      break;
      
    case 7:
      //can move L, U, R
      nextConfigList.push_back(leftMove(indexi,indexj));
      nextConfigList.push_back(rightMove(indexi,indexj));
      nextConfigList.push_back(upMove(indexi,indexj));	 
      break;
      
    case 8:
      //can move L, U
      nextConfigList.push_back(leftMove(indexi,indexj));
      nextConfigList.push_back(upMove(indexi,indexj));
      break;
      
    default:
      //can move D, U
      nextConfigList.push_back(rightMove(indexi,indexj));
      nextConfigList.push_back(downMove(indexi,indexj));	 
      break;	 
    }
  
  return nextConfigList;
}

//numMoves function
//returns the number of moves to reach the current configuration
int Board_Tile::numMoves()
{
  return moves_from_start.size();
}

//Manhattan Distance calculation
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

//Print function (<< operator)
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

//Movement functions
Board_Tile Board_Tile::rightMove(int i, int j)
{
  Board_Tile* b = new Board_Tile(*this);
  swap(b->Array[i][j], b->Array[i][j+1]);
  b->addMove("R");
  return *b;
}

Board_Tile Board_Tile::leftMove(int i, int j)
{
  Board_Tile* b = new Board_Tile(*this);
  swap(b->Array[i][j], b->Array[i][j-1]);
  b->addMove("L");
  return *b;
}

Board_Tile Board_Tile::upMove(int i, int j)
{
  Board_Tile* b = new Board_Tile(*this);
  swap(b->Array[i][j], b->Array[i-1][j]);
  b->addMove("U");
  return *b;
}

Board_Tile Board_Tile::downMove(int i, int j)
{
  Board_Tile* b = new Board_Tile(*this);
  swap(b->Array[i][j], b->Array[i+1][j]);
  b->addMove("D");
  return *b;
}

//addMove function
//appends the current move to the moves_from_start string
void Board_Tile::addMove(const string& s)
{
  moves_from_start += s;
}

//Comparison (==) operator
bool Board_Tile::operator==(const Board_Tile& bt)
{
  for (int i = 0; i < 3 ; i++)
    {
      for (int j = 0; j < 3; j++)
	{
	  if (this->Array[i][j] != bt.Array[i][j])
	    {
	      return false;
	    }
	}
    }
  return true;
}

//Assignment Operator
Board_Tile Board_Tile::operator=(const Board_Tile& bt)
{
  for (int i=0;i <3; i++)
    {
      for (int j =0; j < 3; j++)
	{
	  this->Array[i][j] = bt.Array[i][j];
	}
    }
  
  this->config = bt.config;
  this->totalCost = bt.totalCost;
  this->moves_from_start = bt.moves_from_start;
  
  return *this;
}

//setTotalCost function
//adds the number of moves and manhattan distance for a given
//configuration
void Board_Tile::setTotalCost(const string& goalString)
{
  totalCost = Manhattan_Distance(goalString) + numMoves();
}  

//getTotalCost function
//returns the total cost of a given configuration
int Board_Tile::getTotalCost() const
{
  return totalCost;
}

//getMovesFromStart function
//returns the moves taken to reach a given configuration
string Board_Tile::getMovesFromStart() const
{
  return moves_from_start;
}
