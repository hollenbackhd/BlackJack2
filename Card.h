#ifndef CARD_H
#define CARD_H

#include <iostream>
#include <vector>
using namespace std;

class Card{
    public:
    void setName(string cardName);
    void setSuit(string cardSuit);
    void setValue(int cardValue);
    string getName();
    string getSuit();
    int getValue();
    void printCard();
    Card();
    Card(string cardName, string cardSuit, int cardValue);
    
    
    //private:
    string name;// "No Name";
    string suit;// "No Suit";
    int value;// 0;
};
#endif