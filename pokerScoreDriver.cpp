//
// Created by vince on 5/2/2023.
//

#include "pokerScoreDriver.h"
void pokerScoreDriver()
{
    Deck deck;

    PlayerHand p1Hand;
    PlayerHand p2Hand;

    CardHand cardHand1;
    CardHand cardHand2;

    Flop flop;
    Turn turn;
    River river;

    for (int i = 0; i < 2; ++i)
    {
        p1Hand.addCard(deck.dealCard());
        cardHand1.addCard(p1Hand.getCard());
        p2Hand.addCard(deck.dealCard());
        cardHand2.addCard(p2Hand.getCard());
    }

    for (int i = 0; i < 3; ++i)
    {
        flop.fillFlop(deck.dealCard());
    }
    turn.createTurnCard(deck.dealCard());
    river.createRiverCard(deck.dealCard());

    Flop::index = 0;
    for (int i = 0; i < 3; ++i)
    {
        cardHand1.addCard(flop.getCard());
    }
    Flop::index = 0;
    for (int i = 0; i < 3; ++i)
    {
        cardHand2.addCard(flop.getCard());
    }
    cardHand1.addCard(turn.getCard());
    cardHand2.addCard(turn.getCard());
    cardHand1.addCard(river.getCard());
    cardHand2.addCard(river.getCard());

    CardHand::bubbleSort(cardHand1);
    CardHand::bubbleSort(cardHand2);

    std::cout << cardHand1 << "\n";
    std::cout << cardHand2 << "\n";

    cardHand1.setHighPair(cardHand1);
    cardHand2.setHighPair(cardHand2);
    cardHand1.findBoardPair();
    cardHand2.findBoardPair();

    std::cout << "High card1: " << cardHand1.getHighCard() << "\n";
    std::cout << "High card2: " << cardHand2.getHighCard() << "\n";

    if(cardHand1.getHA() == cardHand2.getHA())
        CardHand::sameAttribute(cardHand1, cardHand2);
    else if(cardHand1.getHA() > cardHand2.getHA())
        Game::player1Wins = true;
    else
        Game::player2Wins = true;

    std::cout << "--------------------------------------\n";
    if(Game::player1Wins){
        std::cout << "player1 wins!\n";
    }
    else
        std::cout << "player2 wins!\n";
};