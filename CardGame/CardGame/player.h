#ifndef PLAYER_H
#define PLAYER_H
#include <string>
#include <iostream>

using namespace std;

class Player
{
private:
	struct Card
	{
		string name;
		int atkPoints;
		int defPoints;
		string type;
	};
	struct Hand
	{
		Card* Card;
		Hand* next;
	};

	struct DeckStack
	{
		Card* Card;
		DeckStack* next;
	};
	DeckStack* top;

public:
	string playerName;
	int lifePoints = 8000;

	Player()
	{
		top = nullptr;
	}

	~Player();
	void push(DeckStack*);
	void pop();
	bool isEmpty();
	void fillDeck();
	void Player::fillHand(DeckStack* filledDeck);
	void Player::popToHand(DeckStack* deck);
};

Player::~Player()
{
	DeckStack *nodePtr = nullptr;
	DeckStack *nextNode = nullptr;
	nodePtr = top;

	while (nodePtr != nullptr)
	{
		nextNode = nodePtr->next;
		delete nodePtr;
		nodePtr = nextNode;
	}
}

bool Player::isEmpty()
{
	bool status;
	if (!top)
	{
		status = true;
	}
	else
		status = false;
	return status;
}

void Player::push(DeckStack *newCard)
{
	newCard = new DeckStack;
	if (isEmpty())
	{
		top = newCard;
		newCard->next = nullptr;
	}
	else
	{
		newCard->next = top;
		top = newCard;
	}
	
}

void Player::pop()
{
	DeckStack *temp = nullptr;
	if (isEmpty())
	{
		cout << "There are no cards in the deck. \n";
	}
	else
	{
		temp = top->next;
		delete top;
		top = temp; 
	}
}

void Player::popToHand(DeckStack* deck)
{

	if (isEmpty())
	{
		cout << "There are no cards in the deck. \n";
	}
	else
	{
		deck = top->next;
		delete top;
		top = deck; 
	}
}

void Player::fillDeck()
{

	Card* Warrior = new Card;
	Warrior->atkPoints = 500;
	Warrior->defPoints = 500;
	Warrior->name = "Warrior";
	Warrior->type = "WR";

	Card* Mage = new Card;
	Mage->atkPoints = 700;
	Mage->defPoints = 300;
	Mage->name = "Mage";
	Mage->type = "MG";

	Card* Hunter = new Card;
	Hunter->atkPoints = 600;
	Hunter->defPoints = 400;
	Hunter->name = "Hunter";
	Hunter->type = "HT";

	Card* Rogue = new Card;
	Rogue->atkPoints = 800;
	Rogue->defPoints = 200;
	Rogue->name = "Rogue";
	Rogue->type = "RG";

	Card* Paladin = new Card;
	Paladin->atkPoints = 350;
	Paladin->defPoints = 650;
	Paladin->name = "Paladin";
	Paladin->type = "PD";

	DeckStack* newDeckNode = new DeckStack;

	for (int i = 1; i <= 4; i++)
	{
		newDeckNode->Card = Warrior; 
		push(newDeckNode);
		cout << Warrior->atkPoints << " ";
	}
	for (int i = 1; i <= 4; i++)
	{
		newDeckNode->Card = Mage;
		push(newDeckNode);
		cout << Mage->atkPoints << " ";
	}
	for (int i = 1; i <= 4; i++)
	{
		newDeckNode->Card = Hunter;
		push(newDeckNode);
		cout << Hunter->atkPoints << " ";
	}
	for (int i = 1; i <= 4; i++)
	{
		newDeckNode->Card = Rogue;
		push(newDeckNode);
		cout << Rogue->atkPoints << " ";
	}
	for (int i = 1; i <= 4; i++)
	{
		newDeckNode->Card = Paladin;
		push(newDeckNode);
		cout << Paladin->atkPoints << " ";
	}
}

void Player::fillHand(DeckStack* filledDeck)
{
	Hand* newHand = new Hand;
	for (int i = 0; i < 5; i++)
	{
		
	}
}

#endif