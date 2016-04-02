// CPSC3620
// Project
// Board_Tile Class Interface
// Written By: Eric Den Haan, Josh Vandenhoek, Lance Chisholm

#include <string>
using namespace std;

#ifndef BOARD_TILE
#define BOARD_TILE

class Board_Tile
{
public:
	//Constructor
	Board_Tile(const string&);

	//Destructor
	~Board_Tile();

	//Member Functions
	void nextConfigs();
	int numMoves();
	int Manhattan_Distance(const Board_Tile&);

  private:
	//this data member is the 2D array tht stores the config string
	int **Array;
	string config;
	string moves_from_start;
};
#endif
