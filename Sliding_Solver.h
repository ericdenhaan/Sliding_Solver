// CPSC3620
// Project
// Sliding_Solver Class Interface
// Written By: Eric Den Haan, Josh Vandenhoek, Lance Chisholm

#include <string>
using namespace std;


#ifndef SLIDING_SOLVER
#define SLIDING_SOLVER

class Sliding_Solver
{
public:
	//Constructors
	Sliding_Solver();
	Sliding_Solver(const string&);

	//Destructor
	~Sliding_Solver();

	//Member Functions
	void Solve_Puzzle();

private:

};
#endif
