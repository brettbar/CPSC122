#include <iostream>

using namespace std;

int main()
{
	int choices[10] = { 13579, 26791, 26792, 33445, 55555, 62483, 77777,
						79422, 85647, 93121 };
	int win;

	cout << "What is this weeks winning five digit number: ";
	cin >> win;

	int index = 0;
	int position = -1; // must start outside of array for a search, this variable states where the winner index is
	bool found = false;  // flag is initialized as false

	while (index < 10 && !found)
	{
		if (choices[index] == win)
		{
			found = true; // flag is true
			position = index;
		}
		index++; // go to next element
	}

	if (found)
	{
		cout << "You have won, with an entry of " << win << " which was ticket number " << position + 1 << endl;
	}
	else if (!found)
	{
		cout << "No winning ticket found, better luck next time. " << endl;
	}
	return 0;
}