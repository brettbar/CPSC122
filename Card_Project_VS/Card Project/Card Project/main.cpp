#include <iostream>
#include <string>
#include <cstdlib>
#include "Deck.h"

using namespace std;

int intro();
Deck* createPlayer(int*);


int main()
{
	int numPlayers = 0; 
	int* playersPtr = &numPlayers;
	int whatPlayer;
	int choice;
	bool status = true;

	Deck* Player1 = nullptr;
	Deck* Player2 = nullptr;

	while (status)
	{
		choice = intro();

		switch (choice)
		{
			case 1: 
			{
					  if (numPlayers == 0)
					  {
						  Player1 = createPlayer(playersPtr);
						  cout << endl;
						  numPlayers++;
						  break;
					  }
					  else if (numPlayers == 1)
					  {
						  Player2 = createPlayer(playersPtr);
						  cout << endl;
						  numPlayers;
						  break;
					  }
					  else if (numPlayers > 2)
					  {
						  cout << "Already two players, restart game if you want to redefine new players...";
						  break;
					  }
			}
			case 2:
			{
					  cout << "\nWhich player wants to fill there deck with cards?(1 or 2)\n";
					  cin >> whatPlayer;
					  if (whatPlayer == 1)
					  {
						  Player1->fillDeck();
						  cout << "\nDefault deck created with 4 cards for each 5 card types.\n\n";
					  }
					  if (whatPlayer == 2)
					  {
						  Player2->fillDeck();
						  cout << "\nDefault deck created with 4 cards for each 5 card types.\n\n";
					  }
					  break;
			}
			case 3:
			{
					  // Trade cards
					  for (int i = 0; i <= 20; i++)
					  {
						 
					  }
					  break;
			}
			case 4:
			{
					  cout << "\nWhich player wants to draw cards?(1 or 2)\n";
					  cin >> whatPlayer;
					  if (whatPlayer == 1)
					  {
						  Player1->drawFirstHand();
						  Player1->displayHand();
					  }
					  if (whatPlayer == 2) 
					  {
						  Player2->drawFirstHand();
						  Player2->displayHand();
					  }

					  int AtkCardAtkP1, AtkCardDefP1, DefCardAtkP1, DefCardDefP1;
					  Player1->whichCard(AtkCardAtkP1, AtkCardDefP1, DefCardAtkP1, DefCardDefP1);

					  cout << "\nPlayerOne\n" << endl;
					  int choicePlayerOne;
					  cout << "What Card Would you like to activate?(1 or 2)" << endl;
					  cout << "1. Attack\n";
					  cout << "2. Defense\n";
					  cin >> choicePlayerOne;
					  cin.ignore(1000, 10);

					  //Player Two
					  int AtkCardAtkP2, AtkCardDefP2, DefCardAtkP2, DefCardDefP2;
					  Player2->whichCard(AtkCardAtkP2, AtkCardDefP2, DefCardAtkP2, DefCardDefP2);

					  cout << "\nPlayerTwo\n" << endl;
					  int choicePlayerTwo;
					  cout << "What Card Would you like to activate?(1 or 2)" << endl;
					  cout << "1. Attack\n";
					  cout << "2. Defense\n";
					  cin >> choicePlayerTwo;
					  cin.ignore(1000, 10);

					  //If One player Chooses attack and the other defense
					  if (choicePlayerOne == 1 && choicePlayerTwo == 2) 
					  {
						  int difference;

						  int RealAtkCardAtkP1, RealAtkCardDefP1;
						  string atkCardtypeP1, AtkCardNameP1;
						  Player1->dequeueAttack(RealAtkCardAtkP1, RealAtkCardDefP1, atkCardtypeP1, AtkCardNameP1);

						  int RealatkCardAtkP2, RealdefCardDefP2;
						  string defCardtypeP2, defCardNameP2;
						  Player2->dequeueDefense(RealatkCardAtkP2, RealdefCardDefP2, defCardtypeP2, defCardNameP2);

						  difference = RealAtkCardAtkP1 - RealdefCardDefP2;

						  //Subtract the difference

						  //Dont know 100% if this works.
						  //ptrForHealthP2->lifePoints = ptrForHealthP2->lifePoints - difference;
						  Player2->lifePoints = Player2->lifePoints - difference;
						  cout << "Player 2 health: " << Player2->lifePoints << endl;
						  if (Player2->lifePoints < 0) {
							  cout << "Player One has won.\n";
							  status = false;
						  }

					  }
					  if (choicePlayerOne == 2 && choicePlayerTwo == 1)
					  {
						  int difference;
						  int aP1, dp1;
						  string T1, N1;
						  Player1->dequeueDefense(aP1, dp1, T1, N1);

						  int aP2, dp2;
						  string T2, N2;
						  Player2->dequeueAttack(aP2, dp2, T2, N2);

						  difference = aP2 - dp1;

						  Player1->lifePoints = Player1->lifePoints - difference;
						  cout << "Player One Health: " << Player1->lifePoints << endl;
						  if (Player1->lifePoints < 0)
						  {
							  cout << "Player Two has Won.\n";
							  status = false;
						  }
					  }
					  if (choicePlayerOne == 2 && choicePlayerTwo == 2)
					  {
						  cout << "Both cards get discarded.\n";
						  int a, b;
						  string c, d;
						  Player1->dequeueDefense(a, b, c, d);
						  Player2->dequeueDefense(a, b, c, d);
					  }
					  if (choicePlayerOne == 1 && choicePlayerTwo == 1)
					  {
						  int a, b;
						  string c, d;
						  Player1->dequeueAttack(a, b, c, d);

						  int e, f;
						  string g, h;
						  Player2->dequeueAttack(e, f, g, h);

						  if (a>e)
						  {
							  Player1->enqueueAttack(a, b, c, d);
						  }
						  if (e>a)
						  {
							  Player2->enqueueAttack(e, f, g, h);
						  }
					  }
					  Player1->drawCards();
					  Player2->drawCards();
					  break; 
			}
		}
	}

	system("pause");
	return 0;
}

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
	cin.ignore(1000, 10); 
	cout << endl;
	bool worked = false;
	while (!worked)
	{
		if (choice == 1)
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
			do
			{
				cout << "Enter a valid option: ";
				cin >> choice;
			} while (choice != 1 && choice != 2 && choice != 3 && choice != 4);
		}
	} 
	return 0;
}


Deck* createPlayer(int* numPlayers)
{
	if (*numPlayers == 0)
	{
		Deck* player1 = nullptr;
		player1 = new Deck;
		*numPlayers++;
		cout << "Enter Player 1's name: ";
		string name;
		getline(cin, name);
		player1->playerName = name;
		return player1;
	}
	if (*numPlayers == 1)
	{
		Deck* player2 = nullptr;
		player2 = new Deck;
		*numPlayers++;
		cout << "Enter Player 2's name: ";
		string name;
		getline(cin, name);
		player2->playerName = name;
		return player2;
	}
	if (*numPlayers == 2)
	{
		cout << "Already have two players. ";
	}
	return nullptr;
}


