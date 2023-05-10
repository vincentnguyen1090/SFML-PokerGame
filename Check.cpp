//
// Created by vince on 4/25/2023.
//

#include "Check.h"
#include "Poker.h"

Check::Check()
{
    check.setTexture(Images::getImage(BUTTON));
    cutSprite();
    setPosition();
    TransformButton::setCenterOrigin(check);
    TransformButton::setScale(check);
    setText();
}

void Check::cutSprite()
{
    intRect.width = 1380;
    intRect.height = 367;
    intRect.left = 300;
    intRect.top = 300;
    check.setTextureRect(intRect);
}

void Check::setPosition()
{
    check.setPosition(512, 460);
}

void Check::setText()
{
    text.setFont(Images::getFont(RETRO));
    TransformButton::transformText(text, "check", sf::Vector2f(512, 450));
}

void Check::update()
{

}

void Check::eventHandler(sf::RenderWindow &window, sf::Event event)
{
    if(MouseEvents::isHovered(check.getGlobalBounds(), window))
        ShadeColor::shadeColor(check, originalColor);
    else
        ShadeColor::shadeOriginalCol(check, originalColor);

    if(MouseEvents::isClicked(check.getGlobalBounds(), window))
    {
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

void Check::draw(sf::RenderTarget &target, sf::RenderStates states) const
{
    target.draw(check);
    target.draw(text);
}

void Check::roundOne()
{
    if(Game::player1Turn && Game::roundOne)
    {
        Game::player1Check = true;
        std::cout << "Player 1 checked\n";

        Game::player2Turn = true;
        Game::player1Turn = false;
    }
    else if(Game::player2Turn && Game::roundOne)
    {
        Game::player2Check = true;
        std::cout << "Player2 checked\n";

        Poker::addFlop();

        Game::player1Turn = true;
        Game::player2Turn = false;
        Game::roundOne = false;
    }
}

void Check::roundTwo()
{
    if(Game::player1Turn && Game::roundTwo)
    {
        Game::player1Check = true;
        std::cout << "Player1 checked\n";

        Game::player2Turn = true;
        Game::player1Turn = false;
    }
    else if(Game::player2Turn && Game::roundTwo)
    {
        Game::player2Check = true;
        std::cout << "Player2 checked\n";

        Poker::addTurn();

        Game::player1Turn = true;
        Game::player2Turn = false;
        Game::roundTwo = false;
    }
}

void Check::roundThree()
{
    if(Game::player1Turn && Game::roundThree)
    {
        Game::player1Check = true;
        std::cout << "Player1 checked\n";

        Game::player2Turn = true;
        Game::player1Turn = false;
    }
    else if(Game::player2Turn && Game::roundThree)
    {
        Game::player2Check = true;
        std::cout << "Player2 checked\n";

        Poker::addRiver();

        Game::player1Turn = true;
        Game::player2Turn = false;
        Game::roundThree = false;
    }
}

void Check::roundFour()
{
    if(Game::player1Turn && Game::roundFour)
    {
        Game::player1Check = true;
        std::cout << "Player1 checked\n";

        Game::player2Turn = true;
        Game::player1Turn = false;
    }
    else if(Game::player2Turn && Game::roundFour)
    {
        Game::player2Check = true;
        std::cout << "Player2 checked\n";

        std::cout << "Find winner!\n";
        Poker::findWinner();

        Game::player1Turn = false;
        Game::player2Turn = false;
        Game::roundFour = false;
        Game::gameOver = true;
    }
    //updateEarnings
    //Game::roundOver = true;
}




