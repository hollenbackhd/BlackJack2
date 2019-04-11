#pragma once
#include <stdio.h>
#include "Deck.h"
#include "Card.h"
#ifndef BLACKJACK_H
#define BLACKJACK_H



class BlackJack
{
public:
    BlackJack();
    void playGame();

private:
    int playerHandTotal;
    int dealerHandTotal;
    Deck d1;
    Card playerCard;
    Card dealerCard;
    vector<Card> playerHand;
    vector<Card> dealerHand;
    int bidAmount;
    int playerMoney;
    bool playerDone;
    bool dealerDone;
    int getPlayerHandTotal();
    void clearPlayersHand();
    void clearDealersHand();
    void dealersTurn();
    void setPlayerMoney();
    void addPlayerCard();
    int getDealerHandTotal();
    void addDealerCard();
    void printPlayerHand();
    void printDealerHand();
};

#endif