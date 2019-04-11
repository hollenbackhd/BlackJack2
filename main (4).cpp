#include <stdio.h>
#include "BlackJack.h"
#include <iostream>
#include <string>
using namespace std;


int main()
{

    int exitGame = 1;

    //do
    //{
        BlackJack casino_royale;
        casino_royale.playGame();
        //cout <<"Would you like to play again? (1 - Yes, 2 - No)";
        //cin >> exitGame;
    //}while (exitGame == 1);


    cout << "\nThanks for playing!\n";
    system("pause");
    return 0;
}