#include <iostream>
#include <cctype>
#include <vector>
#include <string>
#include "Deck.h"
#include "Card.h"
#include <cstdlib>
#include <ctime> 
using namespace std;



int Deck::deckSize(){
    int size =myDeck.size();
    //int size = -1;//myDeck.size(); //#FIXME: myDeck is not declared in this scope? 
    return size;
}//end of deckSize()

void Deck::newDeck(){
    Card newCard;
    
    myDeck.clear();
    
    vector<string>cardTypes(4);
    cardTypes.at(0) = "Clubs";
    cardTypes.at(1) = "Hearts";
    cardTypes.at(2) = "Diamonds";
    cardTypes.at(3) = "Spades";
    
    vector<string>cardsPerSuit(13);
    cardsPerSuit.at(0) = "Ace";cardsPerSuit.at(1) = "Two";cardsPerSuit.at(2) = "Three";cardsPerSuit.at(3) = "Four";cardsPerSuit.at(4) = "Five";
    cardsPerSuit.at(5) = "Six";cardsPerSuit.at(6) = "Seven";cardsPerSuit.at(7) = "Eight";cardsPerSuit.at(8) = "Nine";cardsPerSuit.at(9) = "Ten";
    cardsPerSuit.at(10)= "Jack";cardsPerSuit.at(11)= "Queen";cardsPerSuit.at(12)= "King";
    
    vector<int>cardPoint(13);
    cardPoint.at(0) = 11; cardPoint.at(1) = 2; cardPoint.at(2) = 3; cardPoint.at(3) = 4; cardPoint.at(4) = 5; cardPoint.at(5) = 6;
    cardPoint.at(6) = 7; cardPoint.at(7) = 8; cardPoint.at(8) = 9; cardPoint.at(9) = 10; cardPoint.at(10) = 10; cardPoint.at(11) = 10; cardPoint.at(12) = 10;
    
    //vector<Card>myDeck(52);
    
    int i;
    int j;
    int card = 0;
    //#FIXME: the size of myDeck is coming up as 0
    for(j=0;j<4;j++){
        for(i=0;i<13;i++){
            newCard.name = cardsPerSuit.at(i);
            newCard.suit = cardTypes.at(j);
            newCard.value = cardPoint.at(i);
            myDeck.push_back(newCard);
            // newCard.printCard();//test
            // cout<<card<<endl;

            
        }
    }
}//end of newDeck()

Card Deck::dealCard(){
    Card drawCard;
    srand(time(0));
    int randomCardNumber = (rand() % (myDeck.size()+1));
    drawCard = myDeck.at(randomCardNumber);
    
    myDeck.erase(myDeck.begin() + randomCardNumber);
    
    return drawCard;
    //#FIXME: still needs to remove the card from the deck
    
}//end of dealCard()
