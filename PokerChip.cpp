//
// Created by vince on 4/26/2023.
//

#include "PokerChip.h"

PokerChip::PokerChip()
{
    chip.setTexture(Images::getImage(POKERCHIP));
    cutSpite();
    TransformButton::setCenterOrigin(chip);
    setScale();
}

void PokerChip::cutSpite()
{
    intRect.left = 0;
    intRect.top = 0;
    intRect.height = 592;
    intRect.width = 592;
    chip.setTextureRect(intRect);
}

void PokerChip::setPositionOne()
{
    chip.setPosition(50, 500);
}

void PokerChip::setPositionTwo()
{
    chip.setPosition(750,500);
}

void PokerChip::setScale()
{
    chip.setScale(0.1,0.1);
}

void PokerChip::update()
{

}

void PokerChip::eventHandler(sf::RenderWindow &window, sf::Event event)
{

}

void PokerChip::draw(sf::RenderTarget &target, sf::RenderStates states) const
{
    target.draw(chip);
}


//to position $0000 next to chip
sf::Vector2f PokerChip::getChipPos()
{
    return sf::Vector2f(chip.getGlobalBounds().left + chip.getGlobalBounds().width+50,
                        chip.getGlobalBounds().top+20);
}


//to position playertag next to $0000
sf::Vector2f PokerChip::_getChipPos()
{
    return sf::Vector2f(chip.getGlobalBounds().left + chip.getGlobalBounds().width,
                        chip.getGlobalBounds().top- 30);
}





