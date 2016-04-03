


// CPSC3620
// Project
// Sliding_Solver Class Implementation
// Written By: Eric Den Haan, Josh Vandenhoek, Lance Chisholm

#include "Sliding_Solver.h"

//Constructor
Sliding_Solver::Sliding_Solver(const string& s)
{
   Board_Tile *initialConfig = new Board_Tile(s);
   
}


//this is the function that will be responsible for solving the puzzle,
//probably implementing the A* search algorithm
void Sliding_Solver::Solve_Puzzle()
{
   
}






void Sliding_Solver::setGoalString(const string & s)
{
   goalString = s;
}


   
