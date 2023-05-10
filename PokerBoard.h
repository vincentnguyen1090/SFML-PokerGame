//
// Created by vince on 4/24/2023.
//

#ifndef POKER_GAME_POKERBOARD_H
#define POKER_GAME_POKERBOARD_H
#include <SFML/Graphics.hpp>
#include "Component.h"
class PokerBoard : public Component
{
private:
    sf::Sprite table;
public:
    PokerBoard();
    void setScale();
    void draw(sf::RenderTarget &target, sf::RenderStates states) const override;
    void update() override;
    void eventHandler(sf::RenderWindow &window, sf::Event event) override;
};


#endif //POKER_GAME_POKERBOARD_H
