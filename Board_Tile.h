// CPSC3620
// Project
// Board_Tile Class Interface
// Written By: Eric Den Haan, Josh Vandenhoek, Lance Chisholm

#include <string>
#include <iostream>
#include <cmath>
#include <list>
using namespace std;

#ifndef BOARD_TILE
#define BOARD_TILE

//board tile class declaration
class Board_Tile
{
 public:
  //Constructor
  Board_Tile(const string&);
  
  //Copy Constructor
  Board_Tile(const Board_Tile&);
  
  //Destructor
  ~Board_Tile();
  
  //Member Functions
  
  //generates next configurations for the given board tile, returns a list of board tiles
  list<Board_Tile> nextConfigs();
  //calculates the length of the string "moves_from_start" which is necessary to compute the numbers of moves so far
  int numMoves();
  //function that calculates the manhattan distance of each board tile
  int Manhattan_Distance(const Board_Tile&);
  //overloaded << operator so that we can print our board tiles directly to the screen
  friend ostream& operator<<(ostream& os, const Board_Tile&);
  //function that defines the behaviour for a right move
  Board_Tile rightMove(int, int);
  //function that defines the behaviuor for a left move
  Board_Tile leftMove(int, int);
  //function that defines the behaviour for an up move
  Board_Tile upMove(int, int);
  //function that defines the behaviour for a down move
  Board_Tile downMove(int, int);
  //this function will add a move to the current board tile, this will grow the string representing the moves_so_far
  void addMove(const string&);
  //overloaded == operator to check the equality of board tiles directly
  bool operator==(const Board_Tile&);
  //overloaded = operator so that we can make direct assignments between board tiles
  Board_Tile operator=(const Board_Tile&);
  //function that sets the private data member totalCost and moves_from_start to the appropriate values
  void setTotalCost(const string&);
  //getter method that returns the totalCost private data member
  int getTotalCost() const;
  //getter method that returns the moves_from_start data member
  string getMovesFromStart() const;
  
 private:
  //2D array of chars
  char **Array;
  //string representing the configuration of the board tile
  string config;
  //string representing the number of moves from start
  string moves_from_start;
  //variable that is the aggregation of the manhattan distance and the numMoves for each board tile
  int totalCost;
};
#endif

