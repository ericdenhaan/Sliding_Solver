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

   //default constructor
   Board_Tile();
//Constructor with parameters
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
   //perhaps an assignment operator for replacing
   //configurations in the tree
   Board_Tile operator=(const Board_Tile&);
   
  private:
   //this data member is the 2D array tht stores the config string
   char **Array;
   string config;
   string moves_from_start;
   //maybe a data member that tracks the value for the A* search?
   //int totalCost=0;
};
#endif
