//
// Created by vince on 4/25/2023.
//

#include "Raise.h"
#include "Poker.h"
Raise::Raise()
{
    raise.setTexture(Images::getImage(BUTTON));
    cutSprite();
    setPosition();
    TransformButton::setCenterOrigin(raise);
    TransformButton::setScale(raise);
    setText();
}

void Raise::cutSprite()
{
    intRect.width = 1380;
    intRect.height = 367;
    intRect.left = 300;
    intRect.top = 422 + intRect.height;
    raise.setTextureRect(intRect);
}

void Raise::setPosition()
{
    raise.setPosition(512, 560);
}

void Raise::setText()
{
    text.setFont(Images::getFont(RETRO));
    TransformButton::transformText(text, "raise $50", sf::Vector2f(512, 555));
}

void Raise::update()
{

}

void Raise::eventHandler(sf::RenderWindow &window, sf::Event event)
{
    if(MouseEvents::isHovered(raise.getGlobalBounds(), window))
        ShadeColor::shadeColor(raise, originalColor);
    else
        ShadeColor::shadeOriginalCol(raise, originalColor);

    if(MouseEvents::isClicked(raise.getGlobalBounds(), window))
    {
        if(Game::roundOne)
        {
            roundOne();
            Game::playerCall = false;
        }
        else if (Game::roundTwo)
        {
            roundTwo();
            Game::playerCall = false;
        }
        else if (Game::roundThree)
        {
            roundThree();
            Game::playerCall = false;
        }
        else if (Game::roundFour)
        {
            roundFour();
            Game::playerCall = false;
        }
    }
}

void Raise::draw(sf::RenderTarget &target, sf::RenderStates states) const
{
    target.draw(raise);
    target.draw(text);
}

void Raise::roundOne()
{
    if(Game::player1Turn && Game::roundOne)
    {
        Game::player2Raise = false;
        Game::player1Raise = true;
        std::cout << "Player1 raised\n";

        Money::updateMoney();
        Poker::clearSetOne();

        Game::player2Turn = true;
        Game::player1Turn = false;
    }
    else if(Game::player2Turn && Game::roundOne)
    {
        Game::player1Raise = false;
        Game::player2Raise = true;
        std::cout << "Player2 raised\n";

        Money::updateMoney();
        Poker::clearSetOne();

        Game::player1Turn = true;
        Game::player2Turn = false;
    }
}

void Raise::roundTwo()
{
    if(Game::player1Turn && Game::roundTwo)
    {
        Game::player2Raise = false;
        Game::player1Raise = true;
        std::cout << "Player1 raised\n";

        Money::updateMoney();
        Poker::clearSetOne();

        Game::player2Turn = true;
        Game::player1Turn = false;
    }
    else if(Game::player2Turn && Game::roundTwo)
    {
        Game::player1Raise = false;
        Game::player2Raise = true;
        std::cout << "Player2 raised\n";

        Money::updateMoney();
        Poker::clearSetOne();

        Game::player1Turn = true;
        Game::player2Turn = false;
    }
}

void Raise::roundThree()
{
    if(Game::player1Turn && Game::roundThree)
    {
        Game::player2Raise = false;
        Game::player1Raise = true;
        std::cout << "Player1 raised\n";

        Money::updateMoney();
        Poker::clearSetOne();

        Game::player2Turn = true;
        Game::player1Turn = false;
    }
    else if(Game::player2Turn && Game::roundThree)
    {
        Game::player1Raise = false;
        Game::player2Raise = true;
        std::cout << "Player2 raised\n";

        Money::updateMoney();
        Poker::clearSetOne();

        Game::player1Turn = true;
        Game::player2Turn = false;
    }
}

void Raise::roundFour()
{
    if(Game::player1Turn && Game::roundFour)
    {
        Game::player2Raise = false;
        Game::player1Raise = true;
        std::cout << "Player1 raised\n";

        Money::updateMoney();
        Poker::clearSetOne();

        Game::player2Turn = true;
        Game::player1Turn = false;
    }
    else if(Game::player2Turn && Game::roundFour)
    {
        Game::player1Raise = false;
        Game::player2Raise = true;
        std::cout << "Player2 raised\n";

        Money::updateMoney();
        Poker::clearSetOne();

        Game::player1Turn = true;
        Game::player2Turn = false;
    }
}


