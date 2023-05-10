//
// Created by vince on 4/25/2023.
//

#include "River.h"

void River::createRiverCard(const Card &c)
{
    river = cardsSFML(c.getRank(), c.getSuit(), false);
    card = Card(c.getSuit(), c.getRank());
    river.setPosition(750, 150);
}

void River::update()
{

}

void River::eventHandler(sf::RenderWindow &window, sf::Event event)
{

}

void River::draw(sf::RenderTarget &target, sf::RenderStates states) const
{
    target.draw(river);
}

Card &River::getCard()
{
    return card;
}
