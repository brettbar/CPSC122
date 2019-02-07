#include <iostream>

using namespace std;

// Declares methods here since they are after main
void bubbleSort(int array[], int, int&); 
void selectionSort(int array[], int, int&);

int main()
{	
	const int SIZE = 20; // included a constant incase we wanted to every change the size of these arrays
	int list1[SIZE] = { 20, 3, 37, 12, 40, 50, 23, 15, 62, 99, 17, 1, 2, 3, 52, 432, 0, 9, 11, 203 };
	int list2[SIZE] = { 20, 3, 37, 12, 40, 50, 23, 15, 62, 99, 17, 1, 2, 3, 52, 432, 0, 9, 11, 203 };
	
	int exchange1 = 0;
	int exchange2 = 0;

	bubbleSort(list1, SIZE, exchange1);
	selectionSort(list2, SIZE, exchange2);

	cout << "Bubble sort exchanges: " << exchange1 << endl;
	cout << "Selection sort exhanges " << exchange2 << endl;
	return 0;
}
//This method uses the bubblesort method of sorting
void bubbleSort(int array[], int size, int &exchange)
{
	bool swap; int temp;

	do
	{
		swap = false;
		for (int i = 0; i < (size - 1); i++)
		{
			if (array[i] > array[i + 1])
			{
				temp = array[i]; 
				array[i] = array[i + 1];
				array[i + 1] = temp;
				swap = true;
				exchange++;
			}
		}
	} while (swap);
}
// This method uses the selectionsort method of sorting
void selectionSort(int array[], int size, int &exchange)
{
	int i, minIndex, minValue;
	for (i = 0; i < (size - 1); i++)
	{
		minIndex = i;
		minValue = array[i];
		for (int index = i + 1; index < size; index++)
		{
			if (array[index] < minValue)
			{
				minValue = array[index];
				minIndex = index;
				exchange++;
			}
		}
		array[minIndex] = array[i];
		array[i] = minValue;
	}
}