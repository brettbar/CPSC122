/*
Problem 2
Brett Barinaga
12/3/2017
*/

#include <iostream>

using namespace std;

// Original using iterative process
void sign(int n)
{
	while (n>0)
	{
		cout << "No Parking\n";
		n--;
	}
}

// Same function, but using recursion in stead of iteration
void rSign(int n)
{
	if (n>0)
	{
		cout << "No Parking\n";
		n--;
		rSign(n);
	}
}

int main() 
{
	rSign(10);
	return 0;
}