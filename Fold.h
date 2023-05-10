//
// Created by vince on 4/25/2023.
//

#ifndef POKER_GAME_FOLD_H
#define POKER_GAME_FOLD_H
#include "Component.h"
#include "ShadeColor.h"
class Fold : public Component
{
private:
    sf::Sprite fold;
    sf::Text text;
    sf::IntRect intRect;
    void cutSprite();
    void setPosition();
    void setText();

    sf::Color originalColor = fold.getColor();
public:
    Fold();

    void update() override;
    void eventHandler(sf::RenderWindow &window, sf::Event event) override;
    void draw(sf::RenderTarget &target, sf::RenderStates states) const override;

};



#endif //POKER_GAME_FOLD_H
