//
// Created by vince on 4/25/2023.
//

#include "Flop.h"
int Flop::index = 0;

void Flop::update()
{

}

void Flop::eventHandler(sf::RenderWindow &window, sf::Event event)
{

}

void Flop::draw(sf::RenderTarget &target, sf::RenderStates states) const
{
    for (const auto& card : flop) {
        target.draw(card);
    }
}

void Flop::positionFlop()
{
    for (int i = 1; i <= 3; ++i)
    {
        flop.at(i-1).setPosition(150 * i,150);
    }
}

void Flop::fillFlop(const Card &c)
{
    flop.push_back(cardsSFML(c.getRank(), c.getSuit(), false));
    cards.push_back(Card(c.getSuit(), c.getRank()));
}

Card &Flop::getCard()
{
    return cards[index++];
}

void Flop::clearFlop()
{
    flop.clear();
    cards.clear();
}
