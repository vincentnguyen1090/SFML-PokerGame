//
// Created by vince on 3/29/2023.
//

#include "cardsSFML.h"
#include <iostream>
sf::Texture cardsSFML::texture;

void cardsSFML::draw(sf::RenderTarget &target, sf::RenderStates states) const
{
    target.draw(background);
}

cardsSFML::cardsSFML()
{

}

cardsSFML::cardsSFML(rankENUM rank, suitENUM suit, bool isFlipped)
: rank(rank), suit(suit)
{
    texture.loadFromFile("Images/cardSprite.gif");
    background.setTexture(texture);
    intRect.width = 1053/13;
    intRect.height = 587/5;
    setCardOrientation(isFlipped);
    setScale();
}


void cardsSFML::updateCard(rankENUM rank, suitENUM suit)
{
    intRect.left = rank * intRect.width;
    intRect.top = suit * intRect.height;
    background.setTextureRect(intRect);
}

void cardsSFML::setPosition(float x, float y)
{
    background.setPosition(x, y);
}

sf::Sprite cardsSFML::getBackground() const {
    return background;
}

void cardsSFML::setScale()
{
    background.setScale(sf::Vector2f(1.4, 1.4));
}

void cardsSFML::setRotation(float angle)
{
    background.setRotation(angle);
}

void cardsSFML::update()
{

}

void cardsSFML::eventHandler(sf::RenderWindow &window, sf::Event event)
{
    if(MouseEvents::isClicked(background.getGlobalBounds(), window))
    {
        flipCard();
    }
}

void cardsSFML::flipCard()
{
    if(flipped)
    {
        updateCard(rank, suit);
    }
    else
    {
        intRect.left = 0;
        intRect.top = 4 * intRect.height;
        background.setTextureRect(intRect);
    }
    flipped = !flipped;
}

void cardsSFML::setCardOrientation(bool isFlipped)
{
    if(isFlipped)
        flipCard();
    else
        updateCard(rank, suit);
}
