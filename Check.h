//
// Created by vince on 4/25/2023.
//

#ifndef POKER_GAME_CHECK_H
#define POKER_GAME_CHECK_H
#include "Component.h"
#include "ShadeColor.h"
class Poker;

class Check : public Component
{
private:
    sf::Sprite check;
    sf::Text text;
    sf::IntRect intRect;
    void cutSprite();
    void setPosition();
    void setText();

    sf::Color originalColor = check.getColor();
public:
    Check();

    void roundOne();
    void roundTwo();
    void roundThree();
    void roundFour();
    void update() override;
    void eventHandler(sf::RenderWindow &window, sf::Event event) override;
    void draw(sf::RenderTarget &target, sf::RenderStates states) const override;
};


#endif //POKER_GAME_CHECK_H
