/*
Problem 3
Brett Barinaga
12/3/2017
*/

#include <iostream>

using namespace std;

int sumOfArray(int[], int);

int main()
{
	int SIZE = 4;
	int arr[SIZE] = {1, 2, 3, 4}; // sum should be 10
	
	cout << sumOfArray(arr,SIZE) << endl;


	return 0;
}

int sumOfArray(int arr[], int size)
{
	int sum = 0;
	if (size <= 0)
		return 0;
	return arr[size - 1] + sumOfArray(arr, size - 1);
}