//
// Created by vince on 4/29/2023.
//

#include "Game.h"
bool Game::StartMenu = true;
bool Game::continueBut = false;
bool Game::player1Turn = true;
bool Game::player2Turn = false;
bool Game::roundOne = true;
bool Game::roundTwo = true;
bool Game::roundThree = true;
bool Game::roundFour = true;
bool Game::player1Check = false;
bool Game::player2Check = false;
bool Game::player1Raise = false;
bool Game::player2Raise = false;
bool Game::playerCall = false;
bool Game::gameOver = false;
bool Game::roundOver = false;
bool Game::fold = false;
bool Game::player1Wins = false;
bool Game::player2Wins = false;

void Game::resetBools()
{
     Game::StartMenu = true;
     Game::continueBut = false;
     Game::player1Turn = true;
     Game::player2Turn = true;
     Game::roundOne = true;
     Game::roundTwo = true;
     Game::roundThree = true;
     Game::roundFour = true;
     Game::player1Check = false;
     Game::player2Check = false;
     Game::player1Raise = false;
     Game::player2Raise = false;
     Game::playerCall = false;
     Game::gameOver = false;
     Game::roundOver = false;
     Game::fold = false;
     Game::player1Wins = false;
     Game::player2Wins = false;
}
