// CPSC3620
// Project
// Board_Tile Class Interface
// Written By: Eric Den Haan, Josh Vandenhoek, Lance Chisholm

#include "Board_Tile.h"

int main()
{

   std::string initialconfig = "012345678";
   Board_Tile initial(initialconfig);
   //testing the constructor to make sure is representing correctly
   std::cout << initial << std::endl;
   return 0;
}
