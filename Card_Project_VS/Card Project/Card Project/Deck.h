#ifndef DECK_H
#define DECK_H
#include <string>
#include <iostream>

using namespace std;

class Deck
{
private:
	struct Card
	{
		string name;
		int atkPoints;
		int defPoints;
		string type;
		Card *next;
	};
	Card *top; 

	struct Hand
	{
		int attack;
		int defense;
		string type;
		string name;
		Hand* next;
	};
	Hand* topTwo;

	struct deckStack
	{
		int attack;
		int defense;
		string type;
		string name;
		deckStack* next;
	};
	deckStack* topThree;

	struct AttackQueue
	{
		int attack;
		int defense;
		string type;
		string name;
		AttackQueue* next;
	};
	AttackQueue *AttackFront;
	AttackQueue *AttackRear;
	int numAttackCards;

	struct DefenseQueue
	{
		int attack;
		int defense;
		string type;
		string name;
		DefenseQueue* next;
	};
	DefenseQueue *DefenseFront;
	DefenseQueue *DefenseRear;
	int numDefenseCards;
public: 
	string playerName;
	int lifePoints = 8000;
	Deck()
	{
		top = nullptr;
		topTwo = nullptr;
		AttackFront = nullptr;
		AttackRear = nullptr;
		DefenseFront = nullptr;
		DefenseRear = nullptr;
		int numAttackCards = 0;
		int numDefenseCards = 0;
	}

	~Deck();
	void push(int, int, string, string);
	void pop(int &, int &, string &, string &);
	bool isEmpty();

	void drawFirstHand();
	void displayHand();
	void whichCard(int &, int &, int &, int &);
	void drawCards();

	void enqueueAttack(int, int, string, string);
	void dequeueAttack(int &, int &, string &, string &);
	bool isAttackQueueEmpty() const;

	void enqueueDefense(int, int, string, string);
	void dequeueDefense(int &, int &, string &, string &);
	bool isDefenseQueueEmpty() const;

	void fillDeck();
};

Deck::~Deck()
{
	Card *nodePtr = nullptr;
	Card *nextNode = nullptr;
	nodePtr = top;

	while (nodePtr != nullptr)
	{
		nextNode = nodePtr->next;
		delete nodePtr;
		nodePtr = nextNode; 
	}
} 

void Deck::enqueueDefense(int atttk, int defend, string typer, string namer)
{
	DefenseQueue *newQueuedCard2 = nullptr;
	newQueuedCard2 = new DefenseQueue;
	newQueuedCard2->attack = atttk;
	newQueuedCard2->defense = defend;
	newQueuedCard2->type = typer;
	newQueuedCard2->name = namer;
	newQueuedCard2->next = nullptr;
	if (isDefenseQueueEmpty())
	{
		DefenseFront = newQueuedCard2;
		DefenseRear = newQueuedCard2;
	}
	else
	{
		DefenseRear->next = newQueuedCard2;
		DefenseRear = newQueuedCard2;
	}
	numDefenseCards++;
}

void Deck::enqueueAttack(int atk, int defen, string type, string name)
{
	AttackQueue *newQueuedCard = nullptr;
	newQueuedCard = new AttackQueue;
	newQueuedCard->attack = atk;
	newQueuedCard->defense = defen;
	newQueuedCard->type = type;
	newQueuedCard->name = name;
	newQueuedCard->next = nullptr;
	if (isAttackQueueEmpty())
	{
		AttackFront = newQueuedCard;
		AttackRear = newQueuedCard;
	}
	else
	{
		AttackRear->next = newQueuedCard;
		AttackRear = newQueuedCard;
	}
	numAttackCards++;
}

bool Deck::isDefenseQueueEmpty() const
{
	bool status2;
	if (numDefenseCards > 0)
	{
		status2 = false;
	}
	else
	{
		status2 = true;
	}
	return status2;
}

void Deck::dequeueDefense(int &atttk, int &defend, string &typer, string &namer)
{
	DefenseQueue *temp = nullptr;
	if (isDefenseQueueEmpty())
	{
		cout << "The Defense Queue is empty.\n";
	}
	else
	{
		atttk = DefenseFront->attack;
		defend = DefenseFront->defense;
		typer = DefenseFront->type;
		namer = DefenseFront->name;
		temp = DefenseFront;
		DefenseFront = DefenseFront->next;
		delete temp;
		numDefenseCards--;
	}
}

bool Deck::isAttackQueueEmpty() const {
	bool status;

	if (numAttackCards > 0)
	{
		status = false;
	}
	else
	{
		status = true;
	}
	return status;
}

void Deck::dequeueAttack(int &atk, int &defen, string &type, string &name)
{
	AttackQueue *temp = nullptr;
	if (isAttackQueueEmpty())
	{
		cout << "Queue is empty.\n";
	}
	else
	{
		atk = AttackFront->attack;
		defen = AttackFront->defense;
		type = AttackFront->type;
		name = AttackFront->name;
		temp = AttackFront;
		AttackFront = AttackFront->next;
		delete temp;
		numAttackCards--;
	}
}

void Deck::whichCard(int &attkCardAttk, int &attkCardDefen, int &DefCardAtk, int &DefCardDef)
{
	displayHand();
	int AttackCard;
	int DefenseCard;
	cout << "\nWhat card number would you like to attack?(1,2,3,4 or 5)";
	cin >> AttackCard;
	cin.ignore(1000, 10);
	cout << "\nWhat card number would you like to defend?(1,2,3,4 or 5)";
	cin >> DefenseCard;
	cin.ignore(1000, 10);

	Hand *FindCard;
	FindCard = topTwo;

	int num = 1;
	Hand *previous;
	previous = FindCard;
	while (FindCard)
	{
		if (num == AttackCard)
		{
			cout << "\nAttackCard\n";
			cout << "Name: " << FindCard->name << endl;
			cout << "Type: " << FindCard->type << endl;
			cout << "Attack: " << FindCard->attack << endl;
			cout << "Defense: " << FindCard->defense << endl;
			attkCardAttk = FindCard->attack;
			attkCardDefen = FindCard->defense;

			//put it into attack queue
			enqueueAttack(FindCard->attack, FindCard->defense, FindCard->type, FindCard->name);
			//delete the card from hand
			if (num == 1) 
			{
				FindCard = topTwo->next;
				delete FindCard;
				topTwo = FindCard;
			}
			else{
				previous->next = FindCard->next;
				delete FindCard;
			}
		}
		FindCard = FindCard->next;
		num++;
	}

	int newNum = 1;
	Hand *FindCard2;
	FindCard2 = topTwo;
	Hand *previous2;
	previous2 = FindCard2;
	
	while (FindCard2)
	{
		if (newNum == DefenseCard)
		{
			cout << "\nDefense Card\n";
			cout << "Name: " << FindCard2->name << endl;
			cout << "Type: " << FindCard2->type << endl;
			cout << "Attack: " << FindCard2->attack << endl;
			cout << "Defense: " << FindCard2->defense << endl;
			DefCardAtk = FindCard2->attack;
			DefCardDef = FindCard2->defense;

			//put it into Defense queue
			enqueueDefense(FindCard2->attack, FindCard2->defense, FindCard2->type, FindCard2->name);
			//delete the card from hand
			if (newNum == 1) {
				FindCard2 = topTwo->next;
				delete FindCard2;
				topTwo = FindCard2;
			}
			else
			{
				previous2->next = FindCard2->next;
				delete FindCard2;
			}
		}
		FindCard2 = FindCard2->next;
		newNum++;
	}
}

void Deck::displayHand()
{
	int j = 1;
	Hand *Display;
	Display = topTwo;
	for (int i = 0; i<6; i++)
	{
		while (Display)
		{
			cout << "\nCard: " << j << endl;
			cout << "Attack of Card: " << Display->attack << endl;
			cout << "Defense of Card: " << Display->defense << endl;
			cout << "Type of Monster: " << Display->type << endl;
			cout << "Name of Monster: " << Display->name << endl;
			Display = Display->next;
			j++;
		}
	}
}

void Deck::drawFirstHand()
{
	int attk;
	int defen;
	string typeMon;
	string NameMon;

	for (int i = 0; i<5; i++)
	{
		pop(attk, defen, typeMon, NameMon);
		Hand *Card = nullptr;
		Hand *CardPtr;
		Card = new Hand;
		Card->attack = attk;
		Card->defense = defen;
		Card->type = typeMon;
		Card->name = NameMon;
		Card->next = nullptr;
		if (!topTwo)
		{
			topTwo = Card;
		}
		else
		{
			CardPtr = topTwo;
			while (CardPtr->next)
			{
				CardPtr = CardPtr->next;
			}
			CardPtr->next = Card;
		}

	}
}

void Deck::drawCards()
{
	int attk;
	int defen;
	string typeMon;
	string NameMon;

	for (int i = 0; i<2; i++)
	{
		pop(attk, defen, typeMon, NameMon);
		Hand *Card = nullptr;
		Hand *CardPtr;
		Card = new Hand;
		Card->attack = attk;
		Card->defense = defen;
		Card->type = typeMon;
		Card->name = NameMon;
		Card->next = nullptr;
		if (!topTwo)
		{
			topTwo = Card;
		}
		else
		{
			CardPtr = topTwo;
			while (CardPtr->next)
			{
				CardPtr = CardPtr->next;
			}
			CardPtr->next = Card;
		}

	}
}

void Deck::push(int atk, int dfnse, string typeOftheCard, string NameOftheCard)
{
	Card *newCard = new Card;
	newCard->atkPoints = atk;
	newCard->defPoints = dfnse;
	newCard->type = typeOftheCard;
	newCard->name = NameOftheCard;
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

void Deck::pop(int &atk, int &dfn, string &TypeOfCard, string &NameOfMonsterCard)
{
	Card *temp = nullptr;
	if (isEmpty())
	{
		cout << "There are no cards in the deck.\n";
	}
	else
	{
		atk = top->atkPoints;
		dfn = top->defPoints;
		TypeOfCard = top->type;
		NameOfMonsterCard = top->name;
		temp = top->next;
		delete top;
		top = temp;
	}
}

bool Deck::isEmpty()
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

void Deck::fillDeck()
{
	Card Warrior;
	Warrior.atkPoints = 500;
	Warrior.defPoints = 500;
	Warrior.name = "Warrior";
	Warrior.type = "WR";

	Card Mage;
	Mage.atkPoints = 700;
	Mage.defPoints = 300;
	Mage.name = "Mage";
	Mage.type = "MG";

	Card Hunter;
	Hunter.atkPoints = 600;
	Hunter.defPoints = 400;
	Hunter.name = "Hunter";
	Hunter.type = "HT";

	Card Rogue;
	Rogue.atkPoints = 800;
	Rogue.defPoints = 200;
	Rogue.name = "Rogue";
	Rogue.type = "RG";

	Card Paladin;
	Paladin.atkPoints = 350;
	Paladin.defPoints = 650;
	Paladin.name = "Paladin";
	Paladin.type = "PD";

	deckStack *Card = nullptr;
	deckStack *CardPtr;
	Card = new deckStack;

	for (int i = 0; i <= 4; i++)
	{
		push(Warrior.atkPoints, Warrior.defPoints, Warrior.type, Warrior.name);
		Card->attack = Warrior.atkPoints;
		Card->defense = Warrior.defPoints;
		Card->type = Warrior.type;
		Card->name = Warrior.name;
		Card->next = nullptr;
		if (!topThree)
		{
			topThree = Card;
		}
		else
		{
			CardPtr = topThree;
			while (CardPtr->next)
			{
				CardPtr = CardPtr->next;
			}
			CardPtr->next = Card;
		}
	}
	for (int i = 0; i <= 4; i++)
	{
		push(Mage.atkPoints, Mage.defPoints, Mage.type, Mage.name);
		Card->attack = Mage.atkPoints;
		Card->defense = Mage.defPoints;
		Card->type = Mage.type;
		Card->name = Mage.name;
		Card->next = nullptr;
		if (!topThree)
		{
			topThree = Card;
		}
		else
		{
			CardPtr = topThree;
			while (CardPtr->next)
			{
				CardPtr = CardPtr->next;
			}
			CardPtr->next = Card;
		}
	}
	for (int i = 0; i <= 4; i++)
	{
		push(Hunter.atkPoints, Hunter.defPoints, Hunter.type, Hunter.name);
		Card->attack = Hunter.atkPoints;
		Card->defense = Hunter.defPoints;
		Card->type = Hunter.type;
		Card->name = Hunter.name;
		Card->next = nullptr;
		if (!topThree)
		{
			topThree = Card;
		}
		else
		{
			CardPtr = topThree;
			while (CardPtr->next)
			{
				CardPtr = CardPtr->next;
			}
			CardPtr->next = Card;
		}
	}
	for (int i = 0; i <= 4; i++)
	{
		push(Rogue.atkPoints, Rogue.defPoints, Rogue.type, Rogue.name);
		Card->attack = Rogue.atkPoints;
		Card->defense = Rogue.defPoints;
		Card->type = Rogue.type;
		Card->name = Rogue.name;
		Card->next = nullptr;
		if (!topThree)
		{
			topThree = Card;
		}
		else
		{
			CardPtr = topThree;
			while (CardPtr->next)
			{
				CardPtr = CardPtr->next;
			}
			CardPtr->next = Card;
		}
	}
	for (int i = 0; i <= 4; i++)
	{
		push(Paladin.atkPoints, Paladin.defPoints, Paladin.type, Paladin.name);
		Card->attack = Paladin.atkPoints;
		Card->defense = Paladin.defPoints;
		Card->type = Paladin.type;
		Card->name = Paladin.name;
		Card->next = nullptr;
		if (!topThree)
		{
			topThree = Card;
		}
		else
		{
			CardPtr = topThree;
			while (CardPtr->next)
			{
				CardPtr = CardPtr->next;
			}
			CardPtr->next = Card;
		}
	}
}

#endif