//
// Created by vince on 5/1/2023.
//

#include "Outcome.h"
#include "Poker.h"

Outcome::Outcome()
{
    setButton();
    setPlayer1();
    setPlayer2();
}

void Outcome::setButton()
{
    continueButton.setTexture(Images::getImage(CONTINUE));
    continueButton.setTextureRect(sf::IntRect(0, 0, 400, 109));
    continueButton.setPosition(530, 250);
    TransformButton::setCenterOrigin(continueButton);
    continueButton.setScale(1, 1);
}

void Outcome::setPlayer1()
{
    player1.setFont(Images::getFont(NAME));
    TransformButton::transformText(player1, "Player1 Wins!", sf::Vector2f(200, 20));
}

void Outcome::setPlayer2()
{
    player2.setFont(Images::getFont(NAME));
    TransformButton::transformText(player2, "Player2 Wins!", sf::Vector2f(200, 20));
}

void Outcome::update()
{

}

void Outcome::eventHandler(sf::RenderWindow &window, sf::Event event)
{
    if(MouseEvents::isHovered(continueButton.getGlobalBounds(), window))
        ShadeColor::shadeColor(continueButton, originalColor);
    else
        ShadeColor::shadeOriginalCol(continueButton, originalColor);

    if(MouseEvents::isClicked(continueButton.getGlobalBounds(), window))
    {
        Game::continueBut = true;
    }
}

void Outcome::draw(sf::RenderTarget &target, sf::RenderStates states) const
{
    target.draw(continueButton);
    if(Game::player1Turn && Game::roundOne){
        target.draw(player2);
    }
    else if (Game::player1Turn || Game::player2Wins){
        target.draw(player2);
    }
    else if (Game::player2Turn || Game::player1Wins){
        target.draw(player1);
    }
}


