//
// Created by vince on 4/27/2023.
//

#include "Default.h"


Default::Default()
{
    setTagName();
    positionMoney();
    positionTagName();
}

void Default::setTagName()
{
    playerOne.setString("Player1");
    playerTwo.setString("Player2");
}

void Default::update()
{

}

void Default::eventHandler(sf::RenderWindow &window, sf::Event event)
{

}

void Default::draw(sf::RenderTarget &target, sf::RenderStates states) const
{
    target.draw(board);
    target.draw(playerOne);
    target.draw(playerTwo);
    target.draw(chip1);
    target.draw(chip2);
    target.draw(money);
}

void Default::positionMoney()
{
    chip1.setPositionOne();
    chip2.setPositionTwo();
    money.setPlayerMoneyPosOne(chip1.getChipPos());
    money.setPlayerMoneyPosTwo(chip2.getChipPos());
}

void Default::positionTagName()
{
    playerOne.setPositionOne(chip1._getChipPos());
    playerTwo.setPositionTwo(chip2._getChipPos());
}
