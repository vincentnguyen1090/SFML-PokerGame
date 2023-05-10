//
// Created by vince on 3/26/2023.
//

#include "Deck.h"
const suitENUM suits[] = {SPADES, CLUBS, DIAMONDS, HEARTS};
const rankENUM ranks[] = {ACE, TWO, THREE, FOUR, FIVE, SIX, SEVEN, EIGHT, NINE, TEN, JACK, QUEEN, KING};
Deck::Deck()
{
    int temp = 0;
    for (int i = 0; i < LAST_SUIT; ++i) {
        for (int j = 0; j < LAST_RANK; ++j){
        deck[temp] = Card(suits[i], ranks[j]);
        temp++;
        }
    }
    shuffle();
}
Card Deck::getCardAt(int index) const
{
    return deck[index];
}
Card Deck::dealCard()
{
    return deck[cardIndex++];
}
void Deck::shuffle()
{
    srand(time(nullptr));
    int count = 0;
    while(count != 3) //shuffle 3 times
    {
        for (int i = 0; i < 52; i++) {
            int j = rand() % 52; // generate a random index in the array
            swap(i, j);
        }
        count++;
    }
    cardIndex = 0;
}

void Deck::swap(int num1, int num2)
{
    Card temp;
    temp = deck[num1];
    deck[num1] = deck[num2];
    deck[num2] = temp;
}
std::ostream& operator<<(std::ostream& out, const Deck& deck)
{
    for (int i = 0; i < 52; i++) {
         out << ". " << deck.deck[i].getStrRank() << " of "
             << deck.deck[i].getStrSuit() << "\n";
    }
    return out;
}

void Deck::resetDeck()
{
    cardIndex = 0;
}


