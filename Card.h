//
// Created by vince on 3/26/2023.
//

#ifndef POKER_ANALYSIS_CARD_H
#define POKER_ANALYSIS_CARD_H
#include <iostream>
#include "rankENUM.h"
#include "suitENUM.h"
class Card
{
private:
    std::string strSuit, strRank;
    int rankNum;
    rankENUM rank;
public:
    rankENUM getRank() const;

    suitENUM getSuit() const;

private:
    suitENUM suit;
    std::string s[4] = {"Hearts", "Diamonds", "Clubs", "Spades"};
    std::string r[13] = {"Two", "Three", "Four", "Five", "Six",
                         "Seven", "Eight", "Nine", "Ten", "Jack", "Queen", "King", "Ace"};
    int rankArr[13] = {2,3,4,5,6,7,8,9,10,11,12,13, 14};
public:
    Card();
    Card(std::string suit, std::string rank);
    Card(suitENUM suit, rankENUM rank);

    std::string getStrSuit() const;
    std::string getStrRank() const;
    int getRankNum() const;

    friend std::ostream& operator<<(std::ostream& out, const Card& card);
};


#endif //POKER_ANALYSIS_CARD_H
