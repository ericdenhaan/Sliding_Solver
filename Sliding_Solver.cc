// CPSC3620
// Project
// Sliding_Solver Class Implementation
// Written By: Eric Den Haan, Josh Vandenhoek, Lance Chisholm

#include "Sliding_Solver.h"

//Compare struct
//determines the order in which to sort the heap (by lowest total cost)
struct compare 
{
  bool operator()(const Board_Tile& a, const Board_Tile& b)
  {
    if (a.getTotalCost() < b.getTotalCost())
      {
	return true;
      }
    else 
      {
	return false;
      }	
  }
};

//Constructor
Sliding_Solver::Sliding_Solver(const string& s)
{
  initialConfig = new Board_Tile(s); 
  cout << *initialConfig << endl;
}

//Destructor
Sliding_Solver::~Sliding_Solver(){}

//Solve_Puzzle function
//solves the puzzle using A* search
void Sliding_Solver::Solve_Puzzle(const string& goalConfig)
{
  //set the goalString data member
  goalString = goalConfig;
  
  //set the initialconfig tile's total cost to begin with
  initialConfig->setTotalCost(goalString);
  
  //board tile list iterator
  list<Board_Tile>::iterator lit;
  
  Board_Tile* gc = new Board_Tile(goalConfig);
  cout << *gc << endl;
  
  //this list will contain all the board configurations that are potentially good candidates
  //for the path
  list<Board_Tile> configsToEval;
  
  //these are the configurations we visited but were not good enough
  vector<Board_Tile> closedVector;
  
  //this will hold all of the valid nextconfigs to check
  vector<Board_Tile> openVector;
  
  //push the initial configuration into the open vector
  openVector.push_back((*initialConfig));
  
  while(!openVector.empty())
    {
      //temporarily hold the top element
      Board_Tile tempTop = openVector.back();
      
      //found the config
      if(tempTop == (*gc))
	{
	  cout << "Found a solution!" << endl;
	  
	  string temp = tempTop.getMovesFromStart();
	  cout << "Moves From Start: " << temp << endl;
	  
	  int number = tempTop.numMoves();
	  cout << "Number of Moves: " << number << endl;
	  return;
	}
      
      //if a solution not found yet:
      else
	{
	  openVector.pop_back();
	  closedVector.push_back(tempTop);
	  configsToEval = tempTop.nextConfigs();
	  
	  //iterate over the next configurations, set their total cost, and
	  //determine whether they are in the closed list already
	  //if in the closed list, but a version with a lower cost is in the 
	  //next configurations, replace that element in the closed list
	  for(lit = configsToEval.begin(); lit != configsToEval.end(); ++lit)
	    {
	      for (unsigned int i = 0; i < closedVector.size(); i++)
	    	{
		  lit->setTotalCost(goalString);
		  if((*lit) == closedVector.at(i))
		    {
		      if(lit->getTotalCost() < closedVector.at(i).getTotalCost())
			{
			  closedVector.at(i) = (*lit);
			}
		    }
	    	}
	      
	      //add each next configuration to the open list if it is not 
	      //currently in the list
	      if(openVector.empty())
	    	{
		  openVector.push_back((*lit));	 
	    	}
	      else
	    	{
		   //boolean flag that determines if the current configuration should be pushed into the
		   //open vector
		   bool shouldPush = true;
		  
		  for(unsigned int i = 0; i < openVector.size(); i++)
		    {
		       //if the current configuration is already in the open vector, don't push it in again
		       if((*lit) == openVector.at(i))
			{
			  shouldPush = false;
			  break;
			}
		    }

		  //if it is not in the open vector, push it in
		  if(shouldPush)
		    {
		      openVector.push_back((*lit));
		    }			      
	    	}
	    }
	  
	  //sort the vectors into min-heaps
	  make_heap(openVector.begin(), openVector.end(), compare());
	  make_heap(closedVector.begin(), closedVector.end(), compare());
	}
    }
  
  //if there is no solution (for example, incorrect input)
  if(openVector.empty())
    {
      cout << "Solution not found!" << endl;
    }
}	



   
