//
// Created by vince on 4/25/2023.
//

#include "Call.h"
#include "Poker.h"

Call::Call()
{
    call.setTexture(Images::getImage(BUTTON));
    cutSprite();
    setPosition();
    TransformButton::setCenterOrigin(call);
    TransformButton::setScale(call);
    setText();
}

void Call::cutSprite()
{
    intRect.width = 1380;
    intRect.height = 367;
    intRect.left = 300;
    intRect.top = 300;
    call.setTextureRect(intRect);
}

void Call::setPosition()
{
    call.setPosition(512, 460);
}

void Call::setText()
{
    text.setFont(Images::getFont(RETRO));
    TransformButton::transformText(text, "call", sf::Vector2f(512, 451));
}

void Call::update()
{

}

void Call::eventHandler(sf::RenderWindow &window, sf::Event event)
{
    if(MouseEvents::isHovered(call.getGlobalBounds(), window))
        ShadeColor::shadeColor(call, originalColor);
    else
        ShadeColor::shadeOriginalCol(call, originalColor);

    if(MouseEvents::isClicked(call.getGlobalBounds(), window))
    {
        Game::playerCall = true;
        if(Game::roundOne)
            roundOne();
        else if(Game::roundTwo)
            roundTwo();
        else if(Game::roundThree)
            roundThree();
        else if(Game::roundFour)
            roundFour();
    }
}

void Call::draw(sf::RenderTarget &target, sf::RenderStates states) const
{
    target.draw(call);
    target.draw(text);
}

void Call::roundOne()
{
    Poker::addFlop();
    if(Game::player1Turn)
    {
        Money::matchBet(Game::player1Turn);
        Game::roundOne = false;
        Game::player1Raise = false;
        Game::player2Raise = false;
        Money::counter = 1;

    }
    else
    {
        Money::matchBet(Game::player2Turn);
        Game::roundOne = false;
        Game::player1Raise = false;
        Game::player2Raise = false;
        Money::counter = 1;

        Game::player2Turn = false;
        Game::player1Turn = true;
    }
}

void Call::roundTwo()
{
    Poker::addTurn();
    if(Game::player1Turn)
    {
        Money::matchBet(Game::player1Turn);
        Game::roundTwo = false;
        Game::player1Raise = false;
        Game::player2Raise = false;
        Money::counter = 1;

    }
    else
    {
        Money::matchBet(Game::player2Turn);
        Game::roundTwo = false;
        Game::player1Raise = false;
        Game::player2Raise = false;
        Money::counter = 1;

        Game::player2Turn = false;
        Game::player1Turn = true;
    }
}

void Call::roundThree()
{
    Poker::addRiver();
    if(Game::player1Turn)
    {
        Money::matchBet(Game::player1Turn);
        Game::roundThree = false;
        Game::player1Raise = false;
        Game::player2Raise = false;
        Money::counter = 1;

    }
    else
    {
        Money::matchBet(Game::player2Turn);
        Game::roundThree = false;
        Game::player1Raise = false;
        Game::player2Raise = false;
        Money::counter = 1;

        Game::player2Turn = false;
        Game::player1Turn = true;
    }
}

void Call::roundFour()
{
    if(Game::player1Turn)
    {
        Money::matchBet(Game::player1Turn);
        Game::roundThree = false;
        Game::player1Raise = false;
        Game::player2Raise = false;
        Money::counter = 1;

        std::cout << "end game\n";
    }
    else
    {
        Money::matchBet(Game::player2Turn);
        Game::roundThree = false;
        Game::player1Raise = false;
        Game::player2Raise = false;
        Money::counter = 1;

        Game::player2Turn = false;
        Game::player1Turn = true;
        std::cout << "end game\n";
    }
    Game::roundFour = false;
}
