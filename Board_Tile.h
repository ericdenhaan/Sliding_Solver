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
	//Constructors
	Board_Tile();
	Board_Tile(const string&);

	//Destructor
	~Board_Tile();

	//Member Functions
	void nextConfigs();
	int numMoves();
	int Manhattan_Distance(const Board_Tile&);

private:
	string config;
	string moves_from_start;
};
#endif
