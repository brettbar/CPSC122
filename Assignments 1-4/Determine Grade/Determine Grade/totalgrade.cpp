#include <iostream>

using namespace std;

int main()
{
	int mon, tue, wed, thur, fri; // Declaring the int variables which will hold the number of bulldog bucks spent on a particular day.

	cout << "Enter bulldog bucks spent on Monday: ";
	cin >> mon;

	cout << "Enter bulldog bucks spent on Tuesday: ";
	cin >> tue;

	cout << "Enter bulldog bucks spent on Wednesday: ";
	cin >> wed;

	cout << "Enter bulldog bucks spent on Thursday: ";
	cin >> thur;

	cout << "Enter bulldog bucks spent on Friday: ";
	cin >> fri;

	cout << "MONEY SPENT BAR CHART" << endl;
	cout << "(Each * = $5)" << endl;


	// Each of the following for loops will take the number of dollars spent on a particular day, and will print out a star for every five dollars spent.
	cout << "M:";
	for (int i = 5; i <= 5; i++)
	{
		for (int j = 1; j <= mon / 5; j++)
		{
			cout << "*";
		}
	}
	cout << endl;

	cout << "T:";
	for (int i = 5; i <= 5; i++)
	{
		for (int j = 1; j <= tue / 5; j++)
		{
			cout << "*";
		}
	}
	cout << endl;

	cout << "W:";
	for (int i = 5; i <= 5; i++)
	{
		for (int j = 1; j <= wed / 5; j++)
		{
			cout << "*";
		}
	}
	cout << endl;

	cout << "H:";
	for (int i = 5; i <= 5; i++)
	{
		for (int j = 1; j <= thur / 5; j++)
		{
			cout << "*";
		}
	}
	cout << endl;

	cout << "F:";
	for (int i = 5; i <= 5; i++)
	{
		for (int j = 1; j <= fri / 5; j++)
		{
			cout << "*";
		}
	}
	cout << endl;
	system("pause");
	return 0;
}