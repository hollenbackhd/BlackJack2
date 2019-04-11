#ifndef DECK_H
#define DECK_H

#include <iostream>
#include <vector>
#include "Card.h"

using namespace std;

class Deck{
    public:
    int deckSize();
    void newDeck();
    Card dealCard(); //#FIXME should return Card


    private:
    vector<Card> myDeck;
    
};
#endif
