#include <iostream>
#include <cstdlib>

using namespace std;

int* dynamicAllocate(int n)
{
	int* arr;
	arr = new int[n];
	for (int i = 0; i <= n; i++)
	{
		arr[i] = (rand() % 10) + 1; 
	}
	return arr; 
}

int main()
{
	int* arr;
	arr = dynamicAllocate(5);

	for (int i = 0; i <= 5; i++)
	{
		cout << arr[i] << " ";
	}
	cout << endl;
	return 0;
}