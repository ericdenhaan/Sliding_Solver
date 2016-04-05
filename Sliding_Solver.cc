


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

	//board tile list iterator
	list <Board_Tile> iterator:: lit;

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

	while (!openVector.empty())
	{

		

		//this makes a heap out of the open vector
		make_heap(openVector.begin(), openVector.end(), compare());

		//pop the top
		Board_Tile tempTop = openVector.pop();



		


		if (openVector.begin() == gc)
		{
			cout <<openVector.begin()<<endl;
			return;
		}
		//list of next configurations coming up from the current top value
		configsToEval = tempTop->nextConfigs();

		


		//for all nextConfigs, check to see if they are valid (i.e. visited yet and hence in the closed list)?
		//if in closed list, disregard
		//if not, then check if they are in the open list
		//if in the open list:
		//check to see if its total cost is lower than the current entry--> if so, replace with this and reheapify
		//if not in the open list --> add this to the openVector and re heapify 



		//check for redundant entries with a lower cost
		for (int i=0; i < openVector.size(); i++)
		{
			
			if (openVector.begin() == openVector.at(i) && openVector.begin()->totalCost < openVector.at(i)->totalCost)
			{
				openVector.at(i) = openVector.begin();
				//re-heapify
				make_heap(openVector.begin(),openVector.end(), compare());
			}

		}


		//we found the config we want

		




	}


   
}








void Sliding_Solver::setGoalString(const string & s)
{
   goalString = s;
}


   
