//
// Created by vince on 4/26/2023.
//

#include "PlayerIcon.h"

PlayerIcon::PlayerIcon()
{
    text.setFont(Images::getFont(NAME));
    TransformButton::setCenterOrigin(text);
}

void PlayerIcon::setPositionOne(const sf::Vector2f pos)
{
    text.setPosition(pos);
}

void PlayerIcon::setPositionTwo(const sf::Vector2f pos)
{
    text.setPosition(pos);
}

void PlayerIcon::update()
{

}

void PlayerIcon::eventHandler(sf::RenderWindow &window, sf::Event event)
{

}

void PlayerIcon::draw(sf::RenderTarget &target, sf::RenderStates states) const
{
    target.draw(text);
}

void PlayerIcon::setString(const std::string &name)
{
    text.setString(name);
}
