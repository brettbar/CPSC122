#include <iostream>
#include <cstdlib>

using namespace std;

int* dynamicArrayAllocate(int n)
{
	int* arr;
	arr = new int[n];
	for (int i = 0; i<= n; i++)
	{
		arr[i] = rand() % 10;
	}
	return arr;
}

int main()
{
	int* ptr = dynamicArrayAllocate(5);
	for (int i = 0; i <= 5; i++)
	{
		cout << ptr[i] << " ";
	}
	cout << endl;
	
	return 0;
}