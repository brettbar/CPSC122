//
// Created by reidw on 11/3/2017.
//
//Creation of the monster Card and what it has
#ifndef CARDGAME_MONSTER_H
#define CARDGAME_MONSTER_H
#include <iostream>
#include <string>

using namespace std;

class MonsterCard
{
private:
    struct MonsterNode
    {
        double attack;
        double Defense;
        string type;
        string name;
        MonsterNode *next;
    };
    MonsterNode *top;

public:
    MonsterCard()
    {top =nullptr;}

    ~MonsterCard();

    void push(double,double,string,string);
    void pop(double &,double &,string &,string &);
    bool isEmpty();
};

MonsterCard::~MonsterCard()
{
    MonsterNode *nodePtr = nullptr;
    MonsterNode *nextNode = nullptr;
    nodePtr = top;

    while (nodePtr != nullptr)
    {
        nextNode = nodePtr->next;
        delete nodePtr;
        nodePtr = nextNode;
    }
}

void MonsterCard::push(double atk,double dfnse,string typeOftheCard,string NameOftheCard)
{
    MonsterNode *newCard = nullptr;
    newCard = new MonsterNode;
    newCard->attack= atk;
    newCard->Defense=dfnse;
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

void MonsterCard::pop(double &atk,double &dfnse,string &typeOftheCard,string &NameOftheCard)
{
    MonsterNode *temp = nullptr;
    if (isEmpty())
    {
        cout << "There are no cards in the deck.\n";
    }
    else
    {
        atk = top->attack;
        dfnse = top->Defense;
        typeOftheCard = top->type;
        NameOftheCard = top->name;
        temp = top->next;
        delete top;
        top = temp;
    }
}

bool MonsterCard::isEmpty()
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

#endif //CARDGAME_MONSTER_H
