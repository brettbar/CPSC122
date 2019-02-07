#include <iostream>
#include <cstdlib>

using namespace std;

int* largerArray(int arr[], int size)
{
	int* newArr = new int[size + 1];
	newArr[0] = 0; 
	for(int i = 1; i <= size; i++)
	{
		newArr[i] = arr[i - 1];
	}
	return newArr;
}

int main()
{
	cout << "It worked yo. " << endl;
	return 0;
}