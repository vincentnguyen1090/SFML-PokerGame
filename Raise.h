//
// Created by vince on 4/25/2023.
//

#ifndef POKER_GAME_RAISE_H
#define POKER_GAME_RAISE_H
#include "Component.h"
#include "ShadeColor.h"
#include "Money.h"

class Poker;

class Raise : public Component
{
private:
    sf::Sprite raise;
    sf::Text text;
    sf::IntRect intRect;
    void cutSprite();
    void setPosition();
    void setText();

    sf::Color originalColor = raise.getColor();
public:
    Raise();
    void roundOne();
    void roundTwo();
    void roundThree();
    void roundFour();

    void update() override;
    void eventHandler(sf::RenderWindow &window, sf::Event event) override;
    void draw(sf::RenderTarget &target, sf::RenderStates states) const override;
};


#endif //POKER_GAME_RAISE_H
