// CPSC3620
// Project
// Board_Tile Class Interface
// Written By: Eric Den Haan, Josh Vandenhoek, Lance Chisholm

#include "Board_Tile.h"

int main()
{

   //generate list of Board tiles
   list<Board_Tile> masterList;

   //testing Board_Tile Constructor with initial config
   std::string initialconfig = "123745086";
   Board_Tile initial(initialconfig);

   //testing Board_Tile Constructor that constructs an end goal
   std::string goalconfig = "123456780";
   Board_Tile goal(goalconfig);

   //testing the default constructor
   //Board_Tile def();

   int m_distance = initial.Manhattan_Distance(goal);

   //generate nextConfigs for the initial Board_Tile and store in the Board_Tile list
   masterList = initial.nextConfigs();

   cout << "Initial: " << endl << initial << endl;
   cout << "Goal: " << endl << goal << endl;
   //cout << "Default: " << endl << def << endl;

   cout << "Next Configs: " << endl;
   for (list<Board_Tile>::iterator it = masterList.begin(); it != masterList.end(); ++it)
   {
      cout << (*it) << endl;
   }
   //testing the assignment operator
   initial = goal;

   cout << "Initial after assignment to goal: " << endl << initial << endl;

   
   
   //testing the constructor to make sure is representing correctly
   std::cout << "Manhattan Distance: " << m_distance << endl;
   return 0;
}
