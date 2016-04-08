// CPSC3620
// Project
// Board_Tile Class Interface
// Written By: Eric Den Haan, Josh Vandenhoek, Lance Chisholm

#include "Board_Tile.h"
#include "Sliding_Solver.h"

int main()
{
  string initialString, goalString;

   cout << "Please enter the initial configuration: ";
   cin >> initialString;
   cout << endl;

   Sliding_Solver test(initialString);
   cout << "Enter the solution: ";
   cin >> goalString;
   cout << endl;

   test.Solve_Puzzle(goalString);

   return 0;
}
