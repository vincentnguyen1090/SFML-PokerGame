//
// Created by vince on 4/29/2023.
//
#include "ShadeColor.h"

void ShadeColor::shadeColor(sf::Sprite &sprite, sf::Color originalColor)
{
    sf::Color shadedColor = sf::Color(
            originalColor.r * 0.5,
            originalColor.g * 0.5,
            originalColor.b * 0.5
    );
    sprite.setColor(shadedColor);
}

void ShadeColor::shadeOriginalCol(sf::Sprite &sprite, sf::Color ogColor)
{
    sprite.setColor(ogColor);
}
