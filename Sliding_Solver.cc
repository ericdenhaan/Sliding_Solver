// CPSC3620
// Project
// Sliding_Solver Class Implementation
// Written By: Eric Den Haan, Josh Vandenhoek, Lance Chisholm


// WHERE DO WE POP THE TOP OFF THE OPEN VECTOR?????????


#include "Sliding_Solver.h"

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

//this is the function that will be responsible for solving the puzzle,
//probably implementing the A* search algorithm
void Sliding_Solver::Solve_Puzzle(const string& goalConfig)
{
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

	//push the initial configuration into the closed vector
	closedVector.push_back((*initialConfig));

	//this makes a heap out of the open vector
	make_heap(openVector.begin(), openVector.end(), compare());

	//making a heap out of the closed vector
	make_heap(closedVector.begin(), closedVector.end(), compare());
	
	while(!openVector.empty())
	{
		cout << "looping" << endl;
		//temporarily hold the top element
		Board_Tile tempTop = openVector.back();

		//found the config
		if(tempTop == (*gc))
		{
			cout << tempTop << endl;
			string temp = tempTop.getMovesFromStart();
			cout << "Moves From Start: " << temp << endl;
			int number = tempTop.numMoves();
			cout << "Number of Moves: " << number << endl;
			return;
		}
		
		else
		{
			openVector.pop_back();
			cout << "not found yet" << endl;
			//list of next configurations coming up from the current top value
			configsToEval = tempTop.nextConfigs();

			for(lit = configsToEval.begin(); lit != configsToEval.end(); ++lit)
			{
				lit->setTotalCost(goalString);
			}

			//for all nextConfigs, check to see if they are valid (i.e. visited yet and hence in the closed list)?
			//if in closed list, disregard
			for(lit = configsToEval.begin(); lit != configsToEval.end(); ++lit)
			{
				cout << "iterating outer" << endl;
				for(unsigned int j = 0; j < closedVector.size(); j++)
			   	{
			   		cout << "interating inner" << endl;
			   		//if the board tile in the configsToEval list is a member of the 
			   		//closedList, we need to remove it from configsToEval 
			   		if((*lit) == closedVector.at(j))
			   		{
			   			cout << "already in the closed list" << endl;
			   			if((*lit).getTotalCost() < closedVector.at(j).getTotalCost())
			   			{
			   				cout << "lower cost, swapping" << endl;
			   				closedVector.at(j) = (*lit);
			   			}
			   			else
			   			{
			   				cout << "pushing" << endl;
			   			}
			  			
			  			openVector.push_back((*lit));
			   			make_heap(openVector.begin(), openVector.end(), compare());
			   			make_heap(closedVector.begin(), closedVector.end(), compare());
			   		}
			   	}			   
			}
		}
	}
	if(openVector.empty())
	{
		cout << "not found!" << endl;
	}
}	



   
