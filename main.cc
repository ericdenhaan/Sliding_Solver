// CPSC3620
// Project
// Board_Tile Class Interface
// Written By: Eric Den Haan, Josh Vandenhoek, Lance Chisholm

#include "Board_Tile.h"

int main()
{

   std::string initialconfig = "123745086";
   Board_Tile initial(initialconfig);

   std::string goalconfig = "123456780";
   Board_Tile goal(goalconfig);

   int m_distance = initial.Manhattan_Distance(goal);
   
   //testing the constructor to make sure is representing correctly
   std::cout << initial << std::endl;
   std::cout << goal << std::endl;
   std::cout << m_distance;
   return 0;
}
