//
// Created by vince on 4/24/2023.
//

#include "PokerBoard.h"

PokerBoard::PokerBoard()
{
    table.setTexture(Images::getImage(POKERBOARD));
    setScale();
}

void PokerBoard::draw(sf::RenderTarget &target, sf::RenderStates states) const
{
    target.draw(table);
}

void PokerBoard::setScale()
{
    table.setScale(sf::Vector2f(3,3));
}

void PokerBoard::eventHandler(sf::RenderWindow &window, sf::Event event)
{

}

void PokerBoard::update()
{

}
