//
// Created by vince on 4/27/2023.
//

#ifndef POKER_GAME_DEFAULT_H
#define POKER_GAME_DEFAULT_H
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

//creates the default board
//resets to round 1
//nothing here needs to be modified

class Default : public Component
{
private:
    PokerBoard board;
    PokerChip chip1;
    PokerChip chip2;
    PlayerIcon playerOne;
    PlayerIcon playerTwo;
    Money money;
public:
    Default();

    void positionMoney();
    void setTagName();
    void positionTagName();
    void update() override;
    void eventHandler(sf::RenderWindow &window, sf::Event event) override;
    void draw(sf::RenderTarget &target, sf::RenderStates states) const override;

};


#endif //POKER_GAME_DEFAULT_H
