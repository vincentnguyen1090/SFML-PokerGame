//
// Created by vince on 4/29/2023.
//

#ifndef POKER_GAME_SHADECOLOR_H
#define POKER_GAME_SHADECOLOR_H
#include <SFML/Graphics.hpp>
class ShadeColor
{
public:
    static void shadeOriginalCol(sf::Sprite &sprite, sf::Color ogColor);
    static void shadeColor(sf::Sprite &sprite, sf::Color originalColor);
};

#endif //POKER_GAME_SHADECOLOR_H
