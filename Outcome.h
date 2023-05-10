//
// Created by vince on 5/1/2023.
//

#ifndef POKER_GAME_OUTCOME_H
#define POKER_GAME_OUTCOME_H
#include "Component.h"

class Poker;

class Outcome : public Component
{
private:
    sf::Text player1;
    sf::Text player2;
    sf::Sprite continueButton;

    sf::IntRect intRect;
    sf::Color originalColor = continueButton.getColor();
public:

    Outcome();
    void setButton();
    void setPlayer1();
    void setPlayer2();

    void update() override;
    void eventHandler(sf::RenderWindow &window, sf::Event event) override;
    void draw(sf::RenderTarget &target, sf::RenderStates states) const override;
};


#endif //POKER_GAME_OUTCOME_H
