#include <vector>
#include <algorithm>
#include <iostream>



struct compare 
{
	bool operator()(const int& a, const int& b)
	{
		if (a < b)
		{
			return true;
		}
		else 
		{
			return false;
		}	
	}
};

int main ()

{
	
	std::vector<int> myvector;

//original vector
	for (int i=0; i < 5; i++)
	{

		myvector.push_back(i);
	}


//print the original vector

std::cout << "Printing original vector: ";
	for (unsigned int  i =0; i < myvector.size(); i ++)
	{

		std::cout << myvector.at(i) << " "; 
	}

std::cout << std::endl;


//make a heap

std::make_heap (myvector.begin(), myvector.end(), compare());


//print the heap
std::cout << "Printing the heap: ";
for (unsigned int i =0; i < myvector.size(); i++)
{

	std::cout << myvector.at(i) << " ";
}









	return 0;
}