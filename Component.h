//
// Created by vince on 3/29/2023.
//

#ifndef SFMLAPPLICATIONS_COMPONENT_H
#define SFMLAPPLICATIONS_COMPONENT_H
#include <SFML/Graphics.hpp>
#include "MouseEvents.h"
#include "Images.h"
#include "TransformButton.h"
#include <iostream>
#include "Game.h"
class Component : public sf::Drawable
{
public:
    virtual void update() = 0;
    virtual void eventHandler(sf::RenderWindow &window, sf::Event event) = 0;
};

#endif //SFMLAPPLICATIONS_COMPONENT_H
