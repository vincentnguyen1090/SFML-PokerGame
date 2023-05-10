//
// Created by vince on 4/26/2023.
//

#ifndef POKER_GAME_POKERCHIP_H
#define POKER_GAME_POKERCHIP_H
#include "Component.h"

class PokerChip : public Component
{
private:
    sf::IntRect intRect;
    sf::Sprite chip;
    void cutSpite();
    void setScale();
public:
    PokerChip();

    void setPositionOne();
    void setPositionTwo();

    sf::Vector2f getChipPos();
    sf::Vector2f _getChipPos();
    void update() override;
    void eventHandler(sf::RenderWindow &window, sf::Event event) override;
    void draw(sf::RenderTarget &target, sf::RenderStates states) const override;
};


#endif //POKER_GAME_POKERCHIP_H
