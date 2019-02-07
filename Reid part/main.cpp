#include <iostream>
#include <string>
#include "Monster.h"

using namespace std;

class Hand
{
private:
    struct CardInHand
    {
        double MonsterAttack;
        double MonsterDefense;
        string TypeOfMonster;
        string NameOfMonster;
        CardInHand *next;
    };
    CardInHand *top;
public:
    Hand()
    {top = nullptr;}

    void drawFirstCards();
    void displayCardsToUserPickCardsAndUpdateHand(double &, double &, double &,double &);



};

void Hand::displayCardsToUserPickCardsAndUpdateHand(double &AttackCardAttack, double &AttackCardDefense, double &DefenseCardAttack, double &DefenseCardDefense)
{
    //traverse through the hand and display the cards
    CardInHand *CardDisplay;
    CardDisplay = top;

    int j = 1;
    //Display all 5 cards to the user
    for (int i = 1; i < 6; i++)
    {
        while (CardDisplay) {
            cout << "\nCard " << j << endl;
            cout << "Attack of Card: " << CardDisplay->MonsterAttack << endl;
            cout << "Defense of Card: " << CardDisplay->MonsterDefense << endl;
            cout << "Type of Monster: " << CardDisplay->TypeOfMonster << endl;
            cout << "Name of Monster: " << CardDisplay->NameOfMonster << endl;
            CardDisplay = CardDisplay->next;
            j++;
        }
    }
    //Initialize variables to hold the number for attack card and defense card
    int AttackCard;
    int DefenseCard;

    //Ask the user which card they would like to play
    cout << "What card number would you like to play to attack (1,2,3,4 or 5)?";
    cin >> AttackCard;
    cout << "What card would you lke to play to defend (1,2,3,4 or 5)?";
    cin >> DefenseCard;

    //Find those cards
    CardInHand *FindCard;
    FindCard = top;

    //Display the Cards to the Screen with there information
    int num = 1;
    while (FindCard)
    {
        if(num == AttackCard)
        {
            cout << "\nAttack Card\n";
            cout << "Name: " << FindCard->NameOfMonster << endl;
            cout << "Type: " << FindCard->TypeOfMonster << endl;
            cout << "Attack: " << FindCard->MonsterAttack << endl;
            cout << "Defense: " << FindCard->MonsterDefense << endl;
        }
        if(num == DefenseCard)
        {
            cout << "\nDefense Card\n";
            cout << "Name: " << FindCard->NameOfMonster << endl;
            cout << "Type: " << FindCard->TypeOfMonster << endl;
            cout << "Attack: " << FindCard->MonsterAttack << endl;
            cout << "Defense: " << FindCard->MonsterDefense << endl;
        }
        FindCard = FindCard->next;
        num++;
    }

    //Now delete the Attack Card from the Hand
    CardInHand *newPtr;
    CardInHand *PreviousCard;
    int Position = 1;

    //Determine if its the first Node
    if(Position == AttackCard)
    {
        AttackCardAttack = top->MonsterAttack;
        AttackCardDefense = top->MonsterDefense;
        newPtr=top->next;
        delete top;
        top = newPtr;
    }
    else
    {
        newPtr = top;
        Position++;
        while(newPtr !=nullptr && AttackCard != Position)
        {
            PreviousCard = newPtr;
            newPtr = newPtr->next;
        }
        //When you find the card
        if(newPtr && AttackCard == Position)
        {
            AttackCardAttack = newPtr->MonsterAttack;
            AttackCardDefense = newPtr->MonsterDefense;
            PreviousCard->next = newPtr->next;
            delete newPtr;
        }
    }

    //Now delete the Defense Card from the Hand
    CardInHand *newPtrTwo;
    CardInHand *PreviousCardTwo;
    int PositionTwo = 1;

    //Determine if its the first Node
    if(PositionTwo == DefenseCard)
    {
        DefenseCardAttack = top->MonsterAttack;
        DefenseCardDefense = top->MonsterDefense;
        newPtrTwo=top->next;
        delete top;
        top = newPtrTwo;
    }
    else
    {
        newPtrTwo = top;
        PositionTwo++;
        while(newPtrTwo !=nullptr && DefenseCard != PositionTwo)
        {
            PreviousCardTwo = newPtrTwo;
            newPtrTwo = newPtrTwo->next;
        }
        //When you find the card
        if(newPtrTwo && DefenseCard == PositionTwo)
        {
            DefenseCardAttack = newPtrTwo->MonsterAttack;
            DefenseCardDefense = newPtrTwo->MonsterDefense;
            PreviousCardTwo->next = newPtrTwo->next;
            delete newPtrTwo;
        }
    }

    //Draw two More Cards from the Stack
    for (int i=0; i<2; i++)
    {
        //create an object that will draw a card off the stack
        MonsterCard drawCard;

        //create a pointer for the new card
        CardInHand *newCardInHand = nullptr;
        newCardInHand = new CardInHand;
        CardInHand *CardPtr;

        //create variables to hold incoming parameters
        double attk;
        double defen;
        string TypeMonster;
        string NameMonster;

        //pop off value
        drawCard.pop(attk, defen, TypeMonster, NameMonster); //pop the card into the hand

        //assign the popped off variables to the new card
        newCardInHand->MonsterAttack=attk;
        newCardInHand->MonsterDefense=defen;
        newCardInHand->NameOfMonster=NameMonster;
        newCardInHand->TypeOfMonster=TypeMonster;
        newCardInHand->next = nullptr;

        if (!top)
        {
            top = newCardInHand;
        }
        else
        {
            CardPtr = top;
            while (CardPtr->next)
            {
                CardPtr=CardPtr->next;
            }
            CardPtr->next=newCardInHand;
        }
    }
}

//This function will work assuming the deck is a stack that created in the class Monster
void Hand::drawFirstCards()
{
    for (int i=0; i<5; i++)
    {
        //create an object that will draw a card off the stack
        MonsterCard drawCard;

        //create a pointer for the new card
        CardInHand *newCardInHand = nullptr;
        newCardInHand = new CardInHand;
        CardInHand *CardPtr;

        //create variables to hold incoming parameters
        double attk;
        double defen;
        string TypeMonster;
        string NameMonster;

        //pop off value
        drawCard.pop(attk, defen, TypeMonster, NameMonster); //pop the card into the hand

        //assign the popped off variables to the new card
        newCardInHand->MonsterAttack=attk;
        newCardInHand->MonsterDefense=defen;
        newCardInHand->NameOfMonster=NameMonster;
        newCardInHand->TypeOfMonster=TypeMonster;
        newCardInHand->next = nullptr;

        if (!top)
        {
            top = newCardInHand;
        }
        else
        {
            CardPtr = top;
            while (CardPtr->next)
            {
                CardPtr=CardPtr->next;
            }
            CardPtr->next=newCardInHand;
        }
    }
}


int main()
{
    //Draw Cards
    Hand helloCards;
    helloCards.drawFirstCards();

    // Get the users attack monster and defense monster and pass their
    double AttackCardsAttack, AttackCardsDefense, DefenseCardsAttack, DefenseCardsDefense;
    helloCards.displayCardsToUserPickCardsAndUpdateHand(AttackCardsAttack,AttackCardsDefense,DefenseCardsAttack,DefenseCardsDefense);



    return 0;
}