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
  list<Board_Tile> nextConfigs();
  int numMoves();
  int Manhattan_Distance(const Board_Tile&);
  friend ostream& operator<<(ostream& os, const Board_Tile&);
  Board_Tile rightMove(int, int);
  Board_Tile leftMove(int, int);
  Board_Tile upMove(int, int);
  Board_Tile downMove(int, int);
  void addMove(const string&);
  bool operator==(const Board_Tile&);
  Board_Tile operator=(const Board_Tile&);
  void setTotalCost(const string&);
  int getTotalCost() const;
  string getMovesFromStart() const;
  
 private:
  char **Array;
  string config;
  string moves_from_start;
  int totalCost;
};
#endif

