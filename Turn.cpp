//
// Created by vince on 4/25/2023.
//

#include "Turn.h"

void Turn::createTurnCard(const Card &c)
{
    turn = cardsSFML(c.getRank(), c.getSuit(), false);
    card = Card(c.getSuit(), c.getRank());
    turn.setPosition(600, 150);
}

void Turn::update()
{

}

void Turn::eventHandler(sf::RenderWindow &window, sf::Event event)
{

}

void Turn::draw(sf::RenderTarget &target, sf::RenderStates states) const
{
    target.draw(turn);
}

Card &Turn::getCard()
{
    return card;
}




