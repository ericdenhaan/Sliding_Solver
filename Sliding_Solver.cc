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
   cout << *initialConfig;
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

	//this list will contain all the board configurations that are potentially good candidates
	//for the path
	list<Board_Tile> configsToEval;
	
	//these are the configurations we visited but were not good enough
	vector<Board_Tile> closedVector;
	
	//this will hold all of the valid nextconfigs to check
	vector<Board_Tile> openVector;

	//push the initial configuration into the open vector
	openVector.push_back((*initialConfig));
	//push initial config into the closed vector
	//closedVector.push_back((*initialConfig));

	cout << "Open Vector to Start: " << endl;
	for (unsigned int i =0; i < openVector.size(); i++)
	{
		cout << openVector.at(i);
	}

	//main while loop

	while (!openVector.empty())
	{
		//this makes a heap out of the open vector
		make_heap(openVector.begin(), openVector.end(), compare());

		//temporarily hold the top element
		Board_Tile tempTop = openVector.back();


		//found the config
		if (tempTop == (*gc))
		{
			cout << tempTop << endl;
			string temp = tempTop.getMovesFromStart();
			cout << "Moves From Start: " << temp << endl;
			int number = tempTop.numMoves();
			cout << "Number of Moves: " << number << endl;
			return;
		}

		
		
		//this is causing problems!
		//***********************************************************************************

		//remove the top element
		openVector.pop_back();
		//***********************************************************************************
		




		//loop through the closed list and see if the top element is already in that list

		for (unsigned int i =0; i < closedVector.size(); i++)
		{
			if (tempTop == closedVector.at(i))
			{
				cout << "tempTop is in the closed Vector, breaking" << endl;
				break;
			}
			else {
				cout << "tempTop is not in the closed Vector, push tempTop into the closed Vector" << endl;
				closedVector.push_back(tempTop);
			}
		}
		
		

		//list of next configurations coming up from the current top value
		configsToEval = tempTop.nextConfigs();

		//need to see if the nextConfigs are already in the closed and open
		for (lit = configsToEval.begin(); lit != configsToEval.end(); ++lit)
		{
			//initialize the total cost member for each of the potential new configs	
			cout << "In the main for loop" << endl;
			lit->setTotalCost(goalString);

			for (unsigned int i =0; i < closedVector.size(); i++)
			{
				//if in the closed list, then disregard it and break out
				if (closedVector.at(i) == (*lit))
				{
					cout << "nextConfig is in the closed Vector, breaking out" << endl;
					break;
				}
				//if not in the closed list
				if (closedVector.at(i) != (*lit))
				{
					cout << "nextConfig is not in the closed Vector" << endl;
					//check to see if it is in the open list

					cout << "Open Vector's size: " << openVector.size() << endl;
					for (unsigned int j =0; j < openVector.size(); j++)
					{
						//if it is in the open list, we need to see if this nextConfig's cost is lower than 
						if (openVector.at(j) == (*lit))
						{
							cout << "nextConfig is in the open list" << endl;
							//now do the comparison for a better configuration
							if((*lit) == openVector.at(j) && lit->getTotalCost() < openVector.at(j).getTotalCost())
							{
								cout << "nextConfig is better than what is in open Vector, replacing" << endl;
								openVector.at(j) = (*lit);
								//re-heapify
								make_heap(openVector.begin(),openVector.end(), compare());
							}
							//break out of the loop because we are not going to add it to the openVector again
							cout << "nextConfig was in the open Vector but was not better, breaking" << endl;
							break;
						}
						//if nothing else worked, then it is not in the open or closed list, so it needs to enter the open list
						if (openVector.at(j) != (*lit))
						{
							cout << "nextConfig was not in the open or closed vector, adding it to the open vector" << endl;
							openVector.push_back((*lit));
							//reheapify
							make_heap(openVector.begin(), openVector.end(), compare());
						}
					}
				}
			}
			//lit->setTotalCost(goalString);
			//openVector.push_back((*lit));
		}
		cout << "While loop ending" << endl;
}
/*
		//for all nextConfigs, check to see if they are valid (i.e. visited yet and hence in the closed list)?
		//if in closed list, disregard
		for (unsigned int i = 0; i < openVector.size(); i++)
		   {
			for (unsigned int j =0; j < closedVector.size(); j++)
		   	{
		   		//if the board tile in the configsToEval list is a member of the 
		   		//closedList, we need to remove it from configsToEval 
		   		if (openVector.at(i) == closedVector.at(j))
		   		{
		   			openVector.erase(openVector.begin() + i);
		   			//re-heapify
		   			make_heap(openVector.begin(), openVector.end(), compare());
		   		}

		   	}
		   
		   }
		      
		//if not, then check if they are in the open list
		//if in the open list:


		//check to see if its total cost is lower than the current entry--> if so, replace with this and reheapify
		//if not in the open list --> add this to the openVector and re heapify 

		//check for redundant entries with a lower cost
		for (unsigned int i=0; i < openVector.size(); i++)
		{
			if(tempTop == openVector.at(i) && 
				tempTop.getTotalCost() < openVector.at(i).getTotalCost())
			{
				openVector.at(i) = tempTop;
				//re-heapify
				make_heap(openVector.begin(),openVector.end(), compare());
			}

		}
	}
	*/
}	



   
