//
// Created by vince on 4/25/2023.
//

#ifndef POKER_GAME_TRANSFORMBUTTON_H
#define POKER_GAME_TRANSFORMBUTTON_H
#include <SFML/Graphics.hpp>

//To transform the options but could be used as functions for other classes if needed

class TransformButton
{
public:
    static void transformText(sf::Text& object, const std::string &text, const sf::Vector2f pos);
    static void transformMoney(sf::Text& object, const std::string& text, const sf::Vector2f pos);
    static void transformCash(sf::Text& object, const std::string& text, const sf::Vector2f pos);
    static void transformText(sf::Text& object, const std::string &text);
    static void setScale(sf::Sprite& object);
    static void setCenterOrigin(sf::Sprite& object);
    static void setCenterOrigin(sf::Text& object);
};


#endif //POKER_GAME_TRANSFORMBUTTON_H
