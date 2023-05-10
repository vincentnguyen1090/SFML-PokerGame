//
// Created by vince on 4/29/2023.
//

#ifndef POKER_GAME_GAME_H
#define POKER_GAME_GAME_H


class Game
{
public:
    static bool StartMenu;
    static bool continueBut;
    static bool player1Turn;
    static bool player2Turn;
    static bool player1Check;
    static bool player2Check;
    static bool player1Raise;
    static bool player2Raise;
    static bool playerCall;
    static bool roundOne;
    static bool roundTwo;
    static bool roundThree;
    static bool roundFour;
    static bool gameOver;
    static bool roundOver;
    static bool fold;
    static bool player1Wins;
    static bool player2Wins;

    static void resetBools();
};

#endif //POKER_GAME_GAME_H
