#include <iostream>
#include <string>
#include "Player.h"

using namespace std; 

int intro() 
{
	cout << "1. Create Player\n";
	cout << "2. Add Cards to Specific Player\n";
	cout << "3. Trade Cards with Other Player\n";
	cout << "4. Battle Other Player\n";
	cout << endl;
	cout << "Enter choice: ";
	int choice;
	cin >> choice;
	bool worked = false;
	while(!worked) 
	{
		if(choice == 1)
		{
			worked = true;
			return 1;
		}
		else if (choice == 2)
		{
			worked = true;
			return 2;
		}
		else if (choice == 3)
		{
			worked = true;
			return 3;
		} 
		else if (choice == 4)
		{
			worked = true;
			return 4;
		} 
		else
		{
			worked = false; 
			cout << "Enter a valid option. " << endl;
		}
	}
	

}

void createPlayer()
{
	Player newPlayer;
	cout << "Enter player name";

}



int main()
{
	intro(); 

	return 0;
}

