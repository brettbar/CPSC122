#include <iostream>
#include <string>

using namespace std; 

int main()
{
	int sold[5];
	string names[5] = {"Mild", "Medium", "Sweet", "Hot", "Zesty"};

	// This for loop prompts user to enter values for the sold array, and does not allow negatives.
	for (int i = 0; i <= 4; i++)
	{
		int a;
		do
		{
			cout << "Enter number of jars sold for " << names[i] << ": ";
			cin >> a;
			if (a < 0)
			{
				cout << "Please enter a positive number. ";
				cin >> a;
			}
		} while (a < 0);
		sold[i] = a;
	}

	// This loop states the amount of each type sold
	for (int i = 0; i <= 4; i++)
	{
		cout << names[i] << " sold: " << sold[i] << endl;
	}
	
	// This loop keeps a running total of total sales
	int sum = 0;
	for (int i = 0; i <= 4; i++)
	{
		sum += sold[i];
	}

	// This loop sorts the sold array, and takes the first index and last index to give the min and max sales
	int minIndex, minValue;
	for (int i = 0; i <= 4; i++)
	{
		minIndex = i; 
		minValue = sold[i];
		for (int j = i + 1; j < 5; j++)
		{
			if (sold[j] < minValue)
			{
				minValue = sold[j];
				minIndex = j;
			}
		}
		sold[minIndex] = sold[i];
		sold[i] = minValue;
	}
	int min = sold[0];
	int max = sold[4];

	cout << endl;
	cout << "The max is " << max << endl;
	cout << "The min is " << min << endl;
	cout << "The total sales are " << sum << endl;
	return 0;
}
