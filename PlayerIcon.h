//
// Created by vince on 4/26/2023.
//

#ifndef POKER_GAME_PLAYERICON_H
#define POKER_GAME_PLAYERICON_H
#include "Component.h"

class PlayerIcon : public Component
{
private:
    sf::Text text;
public:
    PlayerIcon();

    void setString(const std::string& name);
    void setPositionOne(const sf::Vector2f pos);
    void setPositionTwo(const sf::Vector2f pos);

    void update() override;
    void eventHandler(sf::RenderWindow &window, sf::Event event) override;
    void draw(sf::RenderTarget &target, sf::RenderStates states) const override;
};


#endif //POKER_GAME_PLAYERICON_H
