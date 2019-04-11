#include <cctype>
#include <iostream>
#include <cctype>
#include <vector>
#include <string>
#include "Card.h"
using namespace std;

Card::Card(){
    name = "No Name";
    suit = "No Suit";
    value = 0;
}
void Card::setName(string cardName){
    name = cardName;
}
void Card::setSuit(string cardSuit){
    suit = cardSuit;
}
void Card::setValue(int cardValue){
    value = cardValue;
}
string Card::getName(){
    return name;
}
string Card::getSuit(){
    return suit;
}
int Card::getValue(){
    return value;
}
void Card::printCard(){
    cout<<name<<" of "<<suit<<endl;
}