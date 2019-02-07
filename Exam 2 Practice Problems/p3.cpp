#include <iostream>

using namespace std;

int* newArray(int old[],int n)
{
	int* newArray;
	newArray = new int[n + 1];
	newArray[0] = 0;
	for(int i = 1; i < n; i++)
	{
		newArray[i] = old[i - 1];
	}
	return newArray;
}

int main()
{
	int beepboop[7] = {5, 4, 2, 4, 1, 7};
	int* ptr = nullptr;
	ptr = new int[7];
	ptr = newArray(beepboop,7);
	for (int i = 0; i <= 7 - 1; i++)
	{
		cout << ptr[i] << " ";
	} 
	return 0;
}