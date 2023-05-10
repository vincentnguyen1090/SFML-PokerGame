//
// Created by vince on 4/25/2023.
//

#include "Fold.h"
#include "Poker.h"

Fold::Fold()
{
    fold.setTexture(Images::getImage(BUTTON));
    cutSprite();
    setPosition();
    TransformButton::setCenterOrigin(fold);
    TransformButton::setScale(fold);
    setText();
}

void Fold::cutSprite()
{
    intRect.width = 1380;
    intRect.height = 367;
    intRect.left = 300;
    intRect.left = 300;
    intRect.top = 235 + (intRect.height*3);
    fold.setTextureRect(intRect);
}

void Fold::setPosition()
{
    fold.setPosition(512, 660);
}

void Fold::setText()
{
    text.setFont(Images::getFont(RETRO));
    TransformButton::transformText(text, "fold", sf::Vector2f(512, 650));
}

void Fold::update()
{

}

void Fold::eventHandler(sf::RenderWindow &window, sf::Event event)
{
    if(MouseEvents::isHovered(fold.getGlobalBounds(), window))
        ShadeColor::shadeColor(fold, originalColor);
    else
        ShadeColor::shadeOriginalCol(fold, originalColor);

    if(MouseEvents::isClicked(fold.getGlobalBounds(), window))
    {
        if(Game::player1Turn)
        {
            Game::fold = true;
            Money::updateEarnings();
            Game::roundOver = true;
        }
        else if(Game::player2Turn)
        {
            Game::fold = true;
            Money::updateEarnings();
            Game::roundOver = true;
        }
    }
}

void Fold::draw(sf::RenderTarget &target, sf::RenderStates states) const
{
    target.draw(fold);
    target.draw(text);
}

