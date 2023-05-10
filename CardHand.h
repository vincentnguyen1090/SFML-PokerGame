//
// Created by vince on 3/27/2023.
//

#ifndef POKER_ANALYSIS_CARDHAND_H
#define POKER_ANALYSIS_CARDHAND_H
#include <vector>
#include "Deck.h"
#include "Game.h"
#include "Money.h"

enum HighestAttribute {
    TEMP, HIGHCARD, PAIR, TWOPAIR, THREEOFAKIND, STRAIGHT, FLUSH, FULLHOUSE, FOUROFAKIND, STRAIGHTFLUSH, ROYALFLUSH
};

class CardHand
{
private:
    std::vector<Card> hand, board;
    int highCard = -1, kicker = -1, highPair = 0, boardPair = 0;
    int count = 1;
    int freq[7];
    HighestAttribute hAttribute;
public:
    int getCount();
    int getFreq();

    void clearHand();
    void addCard(const Card &card);
    static void bubbleSort(CardHand &cardHand);
    static void swap(Card &card1, Card &card2);
    friend std::ostream& operator<<(std::ostream& out, const CardHand& card);
    friend bool operator>(const Card &lCard, const Card &rCard);
    friend bool operator>=(const Card &lCard, const Card &rCard);
    friend bool operator!=(const Card &lCard, const Card &rCard);
    friend bool operator==(const Card &lCard, const Card &rCard);
    friend int operator-(const Card &lCard, const Card &rCard);
    Card& operator[](unsigned int index);
    static bool checkForStraight(CardHand &ch);
    static bool straightUpdated(CardHand &ch);
    static bool checkForSameSuit(CardHand &ch);
    //checking for pairs
    bool checkForSameRank(CardHand &ch);
    static bool checkForFH(CardHand &ch);


    int getHighCard();
    int getKicker();
    int getHighPair();
    int getBoardPair();
    void findHighCard();
    void resetHighPair();
    void setHighPair(CardHand &ch);
    void findBoardPair();
    void setBoardPair(int rankNum);
    void setHighPair(int rankNum);
    static void sameAttribute(CardHand &cardHand1, CardHand &cardHand2);
    //should be last one checked
    static void compareKicker(CardHand &hand1, CardHand &hand2);
    //checked after pair
    static void compareHighCard(CardHand &hand1, CardHand &hand2);
    //check for pair in all 7 cards
    bool checkForPair(CardHand &hand1, CardHand &hand2);
    //comparePairs if they both have pair of cards
    static void comparePairs(CardHand &hand1, CardHand &hand2);
    //compareOnePair
    static void compareOnePair(CardHand &hand1, CardHand &hand2, int freq);
    //compare two pairs
    static void compareTwoPair(CardHand &hand1, CardHand &hand2, int freq);
    //compare the three of kinds
    static void compareRanks(CardHand &hand1, CardHand &hand2, int freq);
    //function

    HighestAttribute getHA();
};


#endif //POKER_ANALYSIS_CARDHAND_H
