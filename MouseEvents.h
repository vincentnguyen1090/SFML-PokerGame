//
// Created by vince on 4/25/2023.
//

#ifndef POKER_GAME_MOUSEEVENTS_H
#define POKER_GAME_MOUSEEVENTS_H
#include <SFML/Graphics.hpp>

class MouseEvents
{
public:
    static bool isHovered(const sf::FloatRect &bounds, const sf::RenderWindow &window);
    static bool isClicked(const sf::FloatRect &bounds, const sf::RenderWindow &window);
};



#endif //POKER_GAME_MOUSEEVENTS_H
