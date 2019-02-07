/*
Problem 5
Brett Barinaga
12/3/2017
*/

#include <iostream>

using namespace std;

bool isMember(int[], int, int);

int main()
{
	int arr[] = {1,2,3,4,5,6};
	int size = 6;
	cout << isMember(arr,size,5) << endl;
	return 0;
}

bool isMember(int arr[], int size, int value)
{
	int count = 0;
	if (arr[count] = value)
		return true;
	else if (count <= size)
	{
		count++;
		isMember(arr, size, value);
	}
	else
		return false;
}