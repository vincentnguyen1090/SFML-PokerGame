//
// Created by vince on 4/29/2023.
//

#ifndef POKER_GAME_POKER_H
#define POKER_GAME_POKER_H
#include <SFML/Graphics.hpp>
#include <vector>
#include "Component.h"
#include <iostream>
#include <SFML/Graphics.hpp>
#include "cardsSFML.h"
#include "PlayerHand.h"
#include "PokerBoard.h"
#include "Flop.h"
#include "Turn.h"
#include "River.h"
#include "Check.h"
#include "Raise.h"
#include "Fold.h"
#include "Call.h"
#include "PokerChip.h"
#include "Money.h"
#include "PlayerIcon.h"
#include "Default.h"
#include "Game.h"
#include "CardHand.h"
#include "StartMenu.h"
#include "Outcome.h"
class Poker
{
private:
    StartMenu menu;
    Default defaultSet;
    Outcome outcome;

    Money money;
    PlayerIcon player1Tag;
    PlayerIcon player2Tag;
    PokerChip chip1;
    PokerChip chip2;

    Check check;
    Raise raise;
    Fold fold;
    //call is interchanged with raise if player raises
    Call call;

     static Deck deck;
     static PlayerHand p1Hand;
     static PlayerHand p2Hand;
     static Flop flop;
    static Turn turn;
    static River river;

    static CardHand cardHand1;
    static CardHand cardHand2;


    static sf::RenderWindow window;
    static std::vector<Component*> outcomeSet;
    static std::vector<Component*> components;
    static std::vector<Component*> cardHands;
    static std::vector<Component*> turnSet;
    static std::vector<Component*> riverSet;
    static std::vector<Component*> flopSet;
    static std::vector<Component*> setOne;
    static std::vector<Component*> setTwo;
    static std::vector<Component*> startScreen;
public:
    Poker();
    void runGame();
    void restartGame();
    static void clearBoard();

    static void setCards();
    void positionItems();
    void setPlayerNames();

    static void dealCards();
    void addStartMenu();
    void addOutcome();
    static void setFlop();
    static void setTurn();
    static void setRiver();
    static void addFlop();
    static void addTurn();
    static void addRiver();
    static void fillCardHands();

    void addDefaultComponent();
    static void addPlayerHands();
    void addSetOne();
    void addSetTwo();
    void addOutcome(Component &component);

    void addStartMenu(Component &component);
    static void addComponent(Component &component);
    static void addPlayerHands(Component &component);
    static void addTurn(Component &component);
    static void addFlop(Component &component);
    static void addRiver(Component &component);
    static void addSetOne(Component &component);
    static void addSetTwo(Component &component);
    static void clearSetOne();
    static void clearCardVectors();
    static void clearCardObj();
    static void clearMenu();

    static void drawCards();
    static void drawStartScreen();
    static void drawOutcome();
    static void clearOutcome();

    //CALCULATE SCORE
    static bool winner();
    static void sortHands();
    static void findWinner();

};

//game ends when both players check, call on river, or fold
//reset the game
//to reset game, we need to clear the flop, clear the turn, clear the river, clear card hands
// also clear the vector set of each card, not just the vector inside the card object
//reshuffle everything and only add player cards


#endif //POKER_GAME_POKER_H
