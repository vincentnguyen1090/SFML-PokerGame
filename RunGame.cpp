//
// Created by vince on 4/27/2023.
//

#include "RunGame.h"

bool RunGame::player1 = true;
bool RunGame::player2 = false;
bool RunGame::roundOne = true;

bool RunGame::switchTurn()
{
    player2 = true;
    player1 = false;
}

void RunGame::options()
{

}

