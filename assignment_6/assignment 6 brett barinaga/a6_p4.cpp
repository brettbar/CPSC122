/*
Problem 4
Brett Barinaga
12/3/2017
*/

#include <iostream>

using namespace std;

int rMultiply(int, int);

int main()
 {
 	cout << rMultiply(5,5) << endl;
 	return 0;
 }

 int rMultiply(int x, int y)
 {

 	if (x <= 0)
 		return 0;
 	else
 		return y + rMultiply(x-1,y);
 }