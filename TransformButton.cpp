//
// Created by vince on 4/25/2023.
//

#include "TransformButton.h"

void TransformButton::setScale(sf::Sprite &object)
{
    object.setScale(0.15, 0.15);
}

void TransformButton::setCenterOrigin(sf::Sprite &object)
{
    const sf::FloatRect bounds = object.getGlobalBounds();
    object.setOrigin(bounds.width / 2.f, bounds.height / 2.f);
}

void TransformButton::setCenterOrigin(sf::Text &object)
{
    const sf::FloatRect bounds = object.getGlobalBounds();
    object.setOrigin(bounds.width / 2.f, bounds.height / 2.f);
}

void TransformButton::transformText(sf::Text &object, const std::string &text, const sf::Vector2f pos)
{
    object.setString(text);
    object.setStyle(sf::Text::Bold);
    TransformButton::setCenterOrigin(object);
    object.setFillColor(sf::Color(240, 240, 240));
    object.setPosition(pos);
}

void TransformButton::transformMoney(sf::Text &object, const std::string &text, const sf::Vector2f pos)
{
    object.setString(text);
    object.setStyle(sf::Text::Bold);
    TransformButton::setCenterOrigin(object);
    object.setFillColor(sf::Color::Green);
    object.setPosition(pos);
}

void TransformButton::transformText(sf::Text &object, const std::string &text)
{
    object.setString(text);
    object.setStyle(sf::Text::Bold);
    TransformButton::setCenterOrigin(object);
    object.setFillColor(sf::Color::Black);
}

void TransformButton::transformCash(sf::Text &object, const std::string &text, const sf::Vector2f pos)
{
    object.setString(text);
    object.setStyle(sf::Text::Bold);
    object.setFillColor(sf::Color::Green);
    object.setPosition(pos);
}

