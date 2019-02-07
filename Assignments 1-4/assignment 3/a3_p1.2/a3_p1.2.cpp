#include <iostream>

using namespace std; 

void showValues(int nums[4][5]) // columms needs an index if we are going to be using it later on in the loop
{
	for (int rows = 0; rows < 4; rows++)
	{
		for (int cols = 0; cols < 5; cols++)
		{
			cout << nums[rows][cols];
		}
	}
}
