//
// Created by vince on 3/26/2023.
//

#ifndef POKER_ANALYSIS_DECK_H
#define POKER_ANALYSIS_DECK_H
#include "Card.h"
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <random>
class Deck : public Card
{
private:
    const int DECK_SIZE = 52;// this is the size of your deck
    int cardIndex = 0; //marks the index of the next card in the deck
    Card deck[52];// this is your final deck of cards
public:
    Deck(); // this is the constructor
    void shuffle(); // puts cards in random order
    void swap(int num1, int num2);
    friend std::ostream& operator<<(std::ostream& out, const Deck& deck); // prints all the cards to the console
    Card dealCard(); // returns the next card in the deck
    Card getCardAt(int index) const;// gets the SFMLcard at the given index
    void resetDeck();

};


#endif //POKER_ANALYSIS_DECK_H
