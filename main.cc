// CPSC3620
// Project
// Board_Tile Class Interface
// Written By: Eric Den Haan, Josh Vandenhoek, Lance Chisholm

#include "Board_Tile.h"

int main()
{

   list<Board_Tile> masterList;

   std::string initialconfig = "123745086";
   Board_Tile initial(initialconfig);

   std::string goalconfig = "123456780";
   Board_Tile goal(goalconfig);

   int m_distance = initial.Manhattan_Distance(goal);

   masterList = initial.nextConfigs();

   cout << "Initial: " << endl << initial << endl;
   cout << "Goal: " << endl << goal << endl;

   cout << "Next Configs: " << endl;
   for (list<Board_Tile>::iterator it = masterList.begin(); it != masterList.end(); ++it)
   {
      cout << (*it) << endl;
   }
   
   //testing the constructor to make sure is representing correctly
   std::cout << "Manhattan Distance: " << m_distance << endl;
   return 0;
}
