


// CPSC3620
// Project
// Sliding_Solver Class Implementation
// Written By: Eric Den Haan, Josh Vandenhoek, Lance Chisholm

#include "Sliding_Solver.h"


struct compare 
{

	bool operator()(const Board_Tile& a, const Board_Tile& b)
	{
		if (a.getTotalCost() < b.getTotalCost())
		{
			return true;
		}
	else {
		return false;
			}	
	}
};





//Constructor
Sliding_Solver::Sliding_Solver(const string& s)
{
   initialConfig = new Board_Tile(s);
   
}


//this is the function that will be responsible for solving the puzzle,
//probably implementing the A* search algorithm
void Sliding_Solver::Solve_Puzzle(const string& goalConfig)
{

	Board_Tile* gc = new Board_Tile(goalConfig);

	//this list will contain all the board configurations that are potentially good candidates
	//for the path
	list <Board_Tile> configsToEval;
	//these are the configurations we visited but were not good enough
	vector<Board_Tile> closedVector;
	//this will hold all of the valid nextconfigs to check
	vector<Board_Tile> openVector;

	//push the initial configuration into the open vector
	openVector.push_back((*initialConfig));



	





	
   
}








void Sliding_Solver::setGoalString(const string & s)
{
   goalString = s;
}


   
