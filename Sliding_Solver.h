// CPSC3620
// Project
// Sliding_Solver Class Interface
// Written By: Eric Den Haan, Josh Vandenhoek, Lance Chisholm

#include <string>
#include "Board_Tile.h"
using namespace std;


#ifndef SLIDING_SOLVER
#define SLIDING_SOLVER

class Sliding_Solver
{
public:
   //Constructor

   //the const string must be the start configuration?
	Sliding_Solver(const string&);

	//Destructor
	~Sliding_Solver();

	//Member Functions
	void Solve_Puzzle();
	//setter function that allows us to change the goalString
	void setGoalString(const string &);

  private:
	
	string goalString;

};
#endif
