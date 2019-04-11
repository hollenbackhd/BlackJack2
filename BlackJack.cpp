#include <stdio.h>
#include "BlackJack.h"
#include "Deck.h"
#include "Card.h"
#include <iostream>
#include <string>
using namespace std;


BlackJack::BlackJack()
{
    srand(time(0));

    playerMoney = 0;
    playerDone = false;
    dealerDone = false;
    Deck d1;
    Card playerCard;
    Card dealerCard;
    vector<Card> playerHand;
    vector<Card> dealerHand;
    playerHandTotal = 0;
}//end of constructor
//-----------------------------------------------------------------------------------------------------------------------playGame
void BlackJack::playGame()
{
    int draw = 1;
    int playing = 1;
    playerMoney = 1;
    //int bidAmount;
    
    cout << "Welcome to Blackjack!\n";
    setPlayerMoney();
    while(playing == 1 && playerMoney>0){
        clearPlayersHand();
        clearDealersHand();
        cout<<"DeckSize: "<<d1.deckSize()<<endl;
        if(d1.deckSize()<20){
            cout<<"Shuffling"<<endl<<"."<<endl<<"."<<endl<<"."<<endl;
            d1.newDeck();
        }
        cout<<"Pot: "<<playerMoney<<endl;
        cout<<"Enter bid amount:"<<endl;
        cin>>bidAmount;

        /*d1.newDeck(); */     Card dealersFirstCard;
        addPlayerCard();     addPlayerCard();
        printPlayerHand();
        cout<<endl;
        addDealerCard();    addDealerCard();
        dealersFirstCard = dealerHand.at(0);
        cout<<"Dealer's Hand: "<<endl;
        dealersFirstCard.printCard();
        cout<<"____________________"<<endl;

    
        cout<<"Would you like to hit? (1 - Hit, 2 - Stand)"<<endl;
        cin>>draw;
        while(draw == 1){
            addPlayerCard();
            printPlayerHand();
            cout<<endl;
            cout<<"Dealer's Hand: "<<endl;
            dealersFirstCard.printCard();
            cout<<"____________________"<<endl;

            if(getPlayerHandTotal()>21){
                break;
            }
            cout<<endl<<"Would you like to hit? (1 - Hit, 2 - Stand)"<<endl;
            cin>>draw;
        }
        if(getPlayerHandTotal()>21){
            dealersFirstCard = dealerHand.at(1);
            dealersFirstCard.printCard();
            cout<<endl;
            cout<<"Your total: "<<getPlayerHandTotal()<<"   Dealer's total: "<<getDealerHandTotal()<<endl;
            cout<<"You lose"<<endl;
            playerMoney = playerMoney - bidAmount;
        }
        else{
            dealersTurn();
        }
        
        cout<<"Play again? (1 - Yes, 2 - No)"<<endl;
        cin>>playing;
        cout<<endl<<endl<<endl;
    }
    

    
}//end of playGame function
//-----------------------------------------------------------------------------------------------------------------------addPlayerCard
void BlackJack::addPlayerCard()
{
    int i;
    playerCard = d1.dealCard();
    playerHand.push_back(playerCard);

}//end of addPlayerCard
//-----------------------------------------------------------------------------------------------------------------------getPlayerHandTotal
int BlackJack::getPlayerHandTotal(){
    int i;
    playerHandTotal = 0;
    Card playerCard;
    for(i=0;i<playerHand.size();i++){
        playerCard = playerHand.at(i);
        playerHandTotal = playerHandTotal + playerCard.getValue();
    }
    for(i=0;i<playerHand.size();i++){
        playerCard = playerHand.at(i);
        if(playerCard.getName() == "Ace" && playerHandTotal>21){
        playerHandTotal = playerHandTotal - 10;
        }
    }
    
    return playerHandTotal;
}//end of getPlayerHandTotal
//-----------------------------------------------------------------------------------------------------------------------addDealerCard
void BlackJack::addDealerCard()
{
    int i;
    dealerCard = d1.dealCard();
    dealerHand.push_back(dealerCard);

}//end of addDealerCard
//-----------------------------------------------------------------------------------------------------------------------getDealersHandTotal
int BlackJack::getDealerHandTotal(){
    int i;
    dealerHandTotal = 0;
    Card dealerCard;
    for(i=0;i<dealerHand.size();i++){
        dealerCard = dealerHand.at(i);
        dealerHandTotal = dealerHandTotal + dealerCard.getValue();
    }
    for(i=0;i<dealerHand.size();i++){
        dealerCard = dealerHand.at(i);
        if(dealerCard.getName() == "Ace" && dealerHandTotal>21){
        dealerHandTotal = dealerHandTotal - 10;
        }
    }
    
    return dealerHandTotal;
}//end of getDealerHandTotal
//-----------------------------------------------------------------------------------------------------------------------printPlayerHand
void BlackJack::printPlayerHand()
{
    int i;
    Card playerCard;
    cout<<endl<<"____________________"<<endl;
    cout<<"Player's Hand:"<<endl;
    for(i=0;i<playerHand.size();i++){
        playerCard = playerHand.at(i);
        playerCard.printCard();
    }
    cout<<"TOTAL: "<<getPlayerHandTotal()<<endl;
    cout<<"____________________";
}//end of printPlayerHand
//-----------------------------------------------------------------------------------------------------------------------printDealerHand
void BlackJack::printDealerHand(){
    int i;
    Card dealerCard;
    cout<<endl<<"____________________"<<endl;
    cout<<"Dealer's Hand:"<<endl;
    for(i=0;i<dealerHand.size();i++){
        dealerCard = dealerHand.at(i);
        dealerCard.printCard();
    }
    cout<<"TOTAL: "<<getDealerHandTotal()<<endl;
    cout<<"____________________"<<endl;
}//end of printPlayerHand
//-----------------------------------------------------------------------------------------------------------------------setPlayerMoney
void BlackJack::setPlayerMoney(){
    cout<<"Enter total bidding amount:"<<endl;
    cin>>playerMoney;
}//end of setPlayerMoney
//-----------------------------------------------------------------------------------------------------------------------dealersTurn
void BlackJack::dealersTurn(){
    if(getDealerHandTotal() == 21){
        cout<<"DEALER'S BLACKJACK!"<<endl;
        playerMoney = playerMoney + bidAmount + (bidAmount/2);
    }
    if(getDealerHandTotal()<17){
        addDealerCard();
    }
    printDealerHand();
    cout<<"Your total: "<<getPlayerHandTotal()<<"   Dealer's total: "<<getDealerHandTotal()<<endl;
    if(getDealerHandTotal()<=21){
        if(getPlayerHandTotal()>getDealerHandTotal()){
            cout<<"You Win!"<<endl;
            cout<<endl;
            playerMoney = playerMoney + bidAmount;
        }
        if(getDealerHandTotal()> getPlayerHandTotal()){
            cout<<"Dealer Wins!"<<endl;
            cout<<endl;
            playerMoney = playerMoney - bidAmount;
        }
        if(getDealerHandTotal() == getPlayerHandTotal()){
            cout<<"Tie!"<<endl;
        }
    }
    else{
        cout<<"You Win!"<<endl;
        playerMoney = playerMoney + bidAmount;
        cout<<endl;
    }
}//end of dealersTurn
//-----------------------------------------------------------------------------------------------------------------------clearPlayersHand
void BlackJack::clearPlayersHand(){
    playerHand.clear();
}//end of clearPlayersHand
//-----------------------------------------------------------------------------------------------------------------------clearDealersHand
void BlackJack::clearDealersHand(){
    dealerHand.clear();
}//end of clearDealersHand
