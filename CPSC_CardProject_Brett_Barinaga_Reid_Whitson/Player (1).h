//
// Created by reidw on 11/6/2017.
//

#ifndef BETTERCARDGAME_PLAYER_H
#define BETTERCARDGAME_PLAYER_H
#include <iostream>
#include <string>
using namespace std;

class Player
{
private:
    struct  Monster
    {
        int attack;
        int defense;
        string type;
        string name;
        struct Monster *next;
    };
    Monster *top;

    struct HandCard
    {
        int MonsterAttack;
        int MonsterDefense;
        string TypeOfMonster;
        string NameOfMonster;
        struct HandCard *next;
    };
    HandCard *topTwo;

    struct AttackQueue
    {
        int attk;
        int def;
        string typeMonst;
        string NameMonst;
        AttackQueue *next;
    };

    AttackQueue *AttackFront;
    AttackQueue *AttackRear;
    int numAttackCards;

    struct DefenseQueue
    {
        int attkdef;
        int deff;
        string typeMonster;
        string NameMonster;
        DefenseQueue *next;
    };

    DefenseQueue *DefenseFront;
    DefenseQueue *DefenseRear;
    int numDefenseCards;

public:
    int lifePoints;

    Player()
    {
        top = nullptr;
        topTwo = nullptr;
        AttackFront = nullptr;
        AttackRear = nullptr;
        DefenseFront = nullptr;
        DefenseRear = nullptr;
        int numAttackCards = 0;
        int numDefenseCards = 0;
        int lifePoints = 8000;
    }

    void push(int,int,string,string);
    void pop(int &, int &,string &,string &);
    bool isEmpty();

    void drawFirstHand();
    void displayHand();
    void whichCard(int &,int &, int &, int &);
    void drawCards();

    void enqueueAttack(int,int,string,string);
    void dequeueAttack(int &,int &, string &, string &);
    bool isAttackQueueEmpty() const;

    void enqueueDefense(int,int,string,string);
    void dequeueDefense(int &,int &, string &, string &);
    bool isDefenseQueueEmpty() const;

    void fillDeck();
};

void Player::enqueueDefense(int atttk, int defend, string typer, string namer)
{
    DefenseQueue *newQueuedCard2 = nullptr;
    newQueuedCard2 = new DefenseQueue;
    newQueuedCard2->attkdef = atttk;
    newQueuedCard2->deff= defend;
    newQueuedCard2->typeMonster = typer;
    newQueuedCard2->NameMonster = namer;
    newQueuedCard2->next = nullptr;
    if(isDefenseQueueEmpty())
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

bool Player::isDefenseQueueEmpty() const
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

void Player::dequeueDefense(int &atttk, int &defend, string &typer, string &namer)
{
    DefenseQueue *temp = nullptr;
    if(isDefenseQueueEmpty())
    {
        cout << "The Defense Queue is empty.\n";
    }
    else
    {
        atttk = DefenseFront->attkdef;
        defend = DefenseFront->deff;
        typer = DefenseFront->typeMonster;
        namer = DefenseFront->NameMonster;
        temp = DefenseFront;
        DefenseFront = DefenseFront->next;
        delete temp;
        numDefenseCards--;
    }
}

bool Player::isAttackQueueEmpty() const {
    bool status;

    if(numAttackCards > 0)
    {
        status = false;
    }
    else
    {
        status = true;
    }
    return status;
}

void Player::enqueueAttack(int atk, int defen, string type, string name)
{
    AttackQueue *newQueuedCard = nullptr;
    newQueuedCard = new AttackQueue;
    newQueuedCard->attk = atk;
    newQueuedCard->def= defen;
    newQueuedCard->typeMonst = type;
    newQueuedCard->NameMonst = name;
    newQueuedCard->next = nullptr;
    if(isAttackQueueEmpty())
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

void Player::dequeueAttack(int &atk, int &defen, string &type, string &name)
{
    AttackQueue *temp = nullptr;
    if(isAttackQueueEmpty())
    {
        cout << "Queue is empty.\n";
    }
    else
    {
        atk = AttackFront->attk;
        defen = AttackFront->def;
        type = AttackFront->typeMonst;
        name = AttackFront->NameMonst;
        temp = AttackFront;
        AttackFront = AttackFront->next;
        delete temp;
        numAttackCards--;
    }
}

void Player::whichCard(int &attkCardAttk, int &attkCardDefen, int &DefCardAtk, int &DefCardDef)
{
    displayHand();
    int AttackCard;
    int DefenseCard;
    cout << "\nWhat card number would you like to attack?(1,2,3,4 or 5)";
    cin >> AttackCard;
    cout << "\nWhat card number would you like to defend?(1,2,3,4 or 5)";
    cin >> DefenseCard;

    HandCard *FindCard;
    FindCard = topTwo;

    int num = 1;
    while(FindCard)
    {
        HandCard *previous;
        previous = FindCard;
        if(num == AttackCard)
        {
            cout << "\nAttackCard\n";
            cout << "Name: " << FindCard->NameOfMonster << endl;
            cout << "Type: " << FindCard->TypeOfMonster << endl;
            cout << "Attack: " << FindCard->MonsterAttack << endl;
            cout << "Defense: " << FindCard->MonsterDefense << endl;
            attkCardAttk = FindCard->MonsterAttack;
            attkCardDefen = FindCard->MonsterDefense;

            //put it into attack queue
            enqueueAttack(FindCard->MonsterAttack,FindCard->MonsterDefense,FindCard->TypeOfMonster,FindCard->NameOfMonster);
            //delete the card from hand
            if(num == 1) {
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
    HandCard *FindCard2;
    FindCard2 = topTwo;
    HandCard *previous2;
    previous2 = FindCard2;

    while (FindCard2)
    {
        if (newNum == DefenseCard)
        {
            cout << "\nDefense Card\n";
            cout << "Name: " << FindCard2->NameOfMonster << endl;
            cout << "Type: " << FindCard2->TypeOfMonster << endl;
            cout << "Attack: " << FindCard2->MonsterAttack << endl;
            cout << "Defense: " << FindCard2->MonsterDefense << endl;
            DefCardAtk = FindCard2->MonsterAttack;
            DefCardDef = FindCard2->MonsterDefense;

            //put it into Defense queue
            enqueueDefense(FindCard2->MonsterAttack, FindCard2->MonsterDefense, FindCard2->TypeOfMonster, FindCard2->NameOfMonster);
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

void Player::displayHand()
{
    int j=1;
    HandCard *Display;
    Display = topTwo;
    for (int i=0;i<6;i++)
    {
        while(Display)
        {
            cout << "\nCard: " << j << endl;
            cout << "Attack of Card: " << Display->MonsterAttack << endl;
            cout << "Defense of Card: " << Display->MonsterDefense << endl;
            cout << "Type of Monster: " << Display->TypeOfMonster << endl;
            cout << "Name of Monster: " << Display->NameOfMonster << endl;
            Display = Display->next;
            j++;
        }
    }
}

void Player::drawFirstHand()
{
    int attk;
    int defen;
    string typeMon;
    string NameMon;

    for(int i=0; i<5;i++)
    {
        pop(attk,defen,typeMon,NameMon);
        HandCard *Card=nullptr;
        HandCard *CardPtr;
        Card = new HandCard;
        Card->MonsterAttack=attk;
        Card->MonsterDefense=defen;
        Card->TypeOfMonster=typeMon;
        Card->NameOfMonster=NameMon;
        Card->next=nullptr;
        if(!topTwo)
        {
            topTwo = Card;
        }
        else
        {
            CardPtr=topTwo;
            while(CardPtr->next)
            {
                CardPtr=CardPtr->next;
            }
            CardPtr->next=Card;
        }

    }
}

void Player::drawCards()
{
    int attk;
    int defen;
    string typeMon;
    string NameMon;

    for(int i=0; i<2;i++)
    {
        pop(attk,defen,typeMon,NameMon);
        HandCard *Card=nullptr;
        HandCard *CardPtr;
        Card = new HandCard;
        Card->MonsterAttack=attk;
        Card->MonsterDefense=defen;
        Card->TypeOfMonster=typeMon;
        Card->NameOfMonster=NameMon;
        Card->next=nullptr;
        if(!topTwo)
        {
            topTwo = Card;
        }
        else
        {
            CardPtr=topTwo;
            while(CardPtr->next)
            {
                CardPtr=CardPtr->next;
            }
            CardPtr->next=Card;
        }

    }
}

void Player::push(int atk,int dfnse,string typeOftheCard,string NameOftheCard)
{
    Monster*newCard = new Monster;
    newCard->attack= atk;
    newCard->defense=dfnse;
    newCard->type = typeOftheCard;
    newCard->name = NameOftheCard;
    if (isEmpty())
    {
        top = newCard;
        newCard->next=nullptr;
    }
    else
    {
        newCard->next=top;
        top=newCard;
    }
}

void Player::pop(int &atk,int &dfn,string &TypeOfCard,string &NameOfMonsterCard)
{
    Monster *temp = nullptr;
    if (isEmpty())
    {
        cout << "There are no cards in the deck.\n";
    }
    else
    {
        atk = top->attack;
        dfn = top->defense;
        TypeOfCard = top->type;
        NameOfMonsterCard = top->name;
        temp = top->next;
        delete top;
        top = temp;
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
    {
        status = false;
    }
    return status;
}

void Player::fillDeck()
{
    Monster Warrior;
    Warrior.attack = 500;
    Warrior.defense = 500;
    Warrior.name = "Warrior";
    Warrior.type = "WR";

    Monster Mage;
    Mage.attack = 700;
    Mage.defense = 300;
    Mage.name = "Mage";
    Mage.type = "MG";

    Monster Hunter;
    Hunter.attack = 600;
    Hunter.defense = 400;
    Hunter.name = "Hunter";
    Hunter.type = "HT";

    Monster Rogue;
    Rogue.attack = 800;
    Rogue.defense = 200;
    Rogue.name = "Rogue";
    Rogue.type = "RG";

    Monster Paladin;
    Paladin.attack = 350;
    Paladin.defense = 650;
    Paladin.name = "Paladin";
    Paladin.type = "PD";

    Monster *Card = nullptr;
    Monster *CardPtr;
    Card = new Monster;

    for (int i = 0; i <= 4; i++)
    {
        push(Warrior.attack, Warrior.defense, Warrior.type, Warrior.name);
        Card->attack = Warrior.attack;
        Card->defense = Warrior.defense;
        Card->type = Warrior.type;
        Card->name = Warrior.name;
        Card->next = nullptr;
        if (!top)
        {
            top = Card;
        }
        else
        {
            CardPtr = top;
            while (CardPtr->next)
            {
                CardPtr = CardPtr->next;
            }
            CardPtr->next = Card;
        }
    }
    for (int i = 0; i <= 4; i++)
    {
        push(Mage.attack, Mage.defense, Mage.type, Mage.name);
        Card->attack = Mage.attack;
        Card->defense = Mage.defense;
        Card->type = Mage.type;
        Card->name = Mage.name;
        Card->next = nullptr;
        if (!top)
        {
            top = Card;
        }
        else
        {
            CardPtr = top;
            while (CardPtr->next)
            {
                CardPtr = CardPtr->next;
            }
            CardPtr->next = Card;
        }
    }
    for (int i = 0; i <= 4; i++)
    {
        push(Hunter.attack, Hunter.defense, Hunter.type, Hunter.name);
        Card->attack = Hunter.attack;
        Card->defense = Hunter.defense;
        Card->type = Hunter.type;
        Card->name = Hunter.name;
        Card->next = nullptr;
        if (!top)
        {
            top = Card;
        }
        else
        {
            CardPtr = top;
            while (CardPtr->next)
            {
                CardPtr = CardPtr->next;
            }
            CardPtr->next = Card;
        }
    }
    for (int i = 0; i <= 4; i++)
    {
        push(Rogue.attack, Rogue.defense, Rogue.type, Rogue.name);
        Card->attack = Rogue.attack;
        Card->defense = Rogue.defense;
        Card->type = Rogue.type;
        Card->name = Rogue.name;
        Card->next = nullptr;
        if (!top)
        {
            top = Card;
        }
        else
        {
            CardPtr = top;
            while (CardPtr->next)
            {
                CardPtr = CardPtr->next;
            }
            CardPtr->next = Card;
        }
    }
    for (int i = 0; i <= 4; i++)
    {
        push(Paladin.attack, Paladin.defense, Paladin.type, Paladin.name);
        Card->attack = Paladin.attack;
        Card->defense = Paladin.defense;
        Card->type = Paladin.type;
        Card->name = Paladin.name;
        Card->next = nullptr;
        if (!top)
        {
            top = Card;
        }
        else
        {
            CardPtr = top;
            while (CardPtr->next)
            {
                CardPtr = CardPtr->next;
            }
            CardPtr->next = Card;
        }
    }
}
#endif //BETTERCARDGAME_PLAYER_H
