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
  void Solve_Puzzle(const string&);
  void setGoalString(const string&);
  
 private:
  Board_Tile* initialConfig;
  string goalString;
};
#endif
