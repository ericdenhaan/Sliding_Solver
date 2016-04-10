// CPSC3620
// Project
// Sliding_Solver Class Interface
// Written By: Eric Den Haan, Josh Vandenhoek, Lance Chisholm

#include <string>
#include "Board_Tile.h"
#include <vector>
#include <algorithm>

using namespace std;


#ifndef SLIDING_SOLVER
#define SLIDING_SOLVER

class Sliding_Solver
{
 public:
  //Constructor
  Sliding_Solver(const string&);
  
  //Destructor
  ~Sliding_Solver();
  
  //Member Functions
  //Function that does the heavy lifting and actually solves the puzzle
  void Solve_Puzzle(const string&);
  //setter function that handles setting the goal string for the Sliding_Solver object
  void setGoalString(const string&);
  
 private:
  //private data member that is a board tile pointer, reprsents the initial configuration of the puzzle
  Board_Tile* initialConfig;
  //string reprenting the configuration of the final board state
  string goalString;
};
#endif
