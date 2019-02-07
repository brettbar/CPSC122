#include <iostream>
#include "Player.h"

using namespace std;

Player createPlayer(int numberPlayer)
{

    if(numberPlayer == 0)
    {
        Player PlayerOne;
        numberPlayer++;
        //cout << "Player One Created\n";
        return PlayerOne;
    }
    else if(numberPlayer == 1)
    {
        Player PlayerTwo;
        numberPlayer++;
        //cout << "Player Two Created\n";
        return PlayerTwo;
    }
    else if(numberPlayer == 2)
    {
        cout << "\nThere is already two players\n";
    }
}

int main() {
    int numberPlayer = 0;
    int whatplayer;
    int choice;
    bool status = true;

    Player PlayerOne; 
    Player PlayerTwo;

    while (status) {
        cout << "What do you want to do? " << endl;
        cout << "1. create player" << endl;
        cout << "2. Add Cards to Player" << endl;
        cout << "3. Trade Cards with a player" << endl;
        cout << "4. Battle Other Player" << endl;
        cin >> choice;

        switch (choice) {
            case 1: {
                createPlayer(numberPlayer);
                if(numberPlayer == 0)
                {
                    numberPlayer++;
                    cout << "PLayer One Created.\n";
                }
                else if(numberPlayer == 1)
                {
                    numberPlayer++;
                    cout << "PLayer two Created.\n";
                }
            }
            break;
            case 2: {
                cout << "\nWhich player wants to draw cards?(1 or 2)\n";
                cin >> whatplayer;
                if (whatplayer == 1) {
                    PlayerOne.fillDeck();
                    PlayerOne.drawFirstHand();
                    break;
                }
                else if (whatplayer == 2) {
                    PlayerTwo.fillDeck();
                    PlayerTwo.drawFirstHand();
                    break;
                }
                break;
            }
            case 3: {
                //travese both hands and then switch them
            }
            break;
            case 4: {

                int AtkCardAtkP1, AtkCardDefP1, DefCardAtkP1, DefCardDefP1;
                PlayerOne.whichCard(AtkCardAtkP1, AtkCardDefP1, DefCardAtkP1, DefCardDefP1);

                cout << "\nPlayerOne\n" << endl;


                int choicePlayerOne;
                cout << "What Card Would you like to activate?(1 or 2)" << endl;
                cout << "1. Attack\n";
                cout << "2. Defense\n";
                cin >> choicePlayerOne;

                //Player Two
                int AtkCardAtkP2, AtkCardDefP2, DefCardAtkP2, DefCardDefP2;
                PlayerTwo.whichCard(AtkCardAtkP2, AtkCardDefP2, DefCardAtkP2, DefCardDefP2);

                cout << "\nPlayerTwo\n" << endl;



                int choicePlayerTwo;
                cout << "What Card Would you like to activate?(1 or 2)" << endl;
                cout << "1. Attack\n";
                cout << "2. Defense\n";
                cin >> choicePlayerTwo;

                //If One player Chooses attack and the other defense
                if (choicePlayerOne == 1 && choicePlayerTwo == 2) {
                    int difference;

                    int RealAtkCardAtkP1, RealAtkCardDefP1;
                    string atkCardtypeP1, AtkCardNameP1;
                    PlayerOne.dequeueAttack(RealAtkCardAtkP1, RealAtkCardDefP1, atkCardtypeP1, AtkCardNameP1);

                    int RealatkCardAtkP2, RealdefCardDefP2;
                    string defCardtypeP2, defCardNameP2;
                    PlayerTwo.dequeueDefense(RealatkCardAtkP2, RealdefCardDefP2, defCardtypeP2, defCardNameP2);

                    difference = RealAtkCardAtkP1 - RealdefCardDefP2;

                    //Subtract the difference

      
                    //ptrForHealthP2->lifePoints = ptrForHealthP2->lifePoints - difference;
                    PlayerTwo.lifePoints = PlayerTwo.lifePoints - difference;
                    cout << "Player 2 health: " << PlayerTwo.lifePoints << endl;
                    if (PlayerTwo.lifePoints < 0) {
                        cout << "Player One has won.\n";
                        status = false;
                    }

                }
                if (choicePlayerOne == 2 && choicePlayerTwo == 1)
                {
                    int difference;
                    int aP1,dp1;
                    string T1,N1;
                    PlayerOne.dequeueDefense(aP1,dp1,T1,N1);

                    int aP2,dp2;
                    string T2,N2;
                    PlayerTwo.dequeueAttack(aP2,dp2,T2,N2);

                    difference = aP2 - dp1;

                    PlayerOne.lifePoints = PlayerOne.lifePoints - difference;
                    cout << "Player One Health: " << PlayerOne.lifePoints << endl;
                    if (PlayerOne.lifePoints < 0)
                    {
                        cout << "Player Two has Won.\n";
                        status = false;
                    }
                }
                if (choicePlayerOne == 2 && choicePlayerTwo == 2)
                {
                    cout << "Both cards get discarded.\n";
                    int a,b;
                    string c,d;
                    PlayerOne.dequeueDefense(a,b,c,d);
                    PlayerTwo.dequeueDefense(a,b,c,d);
                }
                if (choicePlayerOne == 1 && choicePlayerTwo == 1)
                {
                    int a,b;
                    string c,d;
                    PlayerOne.dequeueAttack(a,b,c,d);

                    int e,f;
                    string g,h;
                    PlayerTwo.dequeueAttack(e,f,g,h);

                    if (a>e)
                    {
                        PlayerOne.enqueueAttack(a,b,c,d);
                    }
                    if (e>a)
                    {
                        PlayerTwo.enqueueAttack(e,f,g,h);
                    }
                }
                PlayerOne.drawCards();
                PlayerTwo.drawCards();
            }
            break;
        }

    }
    return 0;
}