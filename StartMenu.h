//
// Created by vince on 5/1/2023.
//

#ifndef POKER_GAME_STARTMENU_H
#define POKER_GAME_STARTMENU_H
#include "Component.h"
#include "PokerBoard.h"

class Poker;

class StartMenu : public Component
{
private:
    PokerBoard board;
    sf::Sprite background, startButton, image;
    sf::Text title, myInfo;
    sf::IntRect intRect;

    sf::Color originalColor = startButton.getColor();
public:
    StartMenu();

    void setImage();

    void cutSpite();
    void posButton();
    void scaleButton();

    void setText();
    void scaleTitle();

    void update() override;
    void eventHandler(sf::RenderWindow &window, sf::Event event) override;
    void draw(sf::RenderTarget &target, sf::RenderStates states) const override;
};


#endif //POKER_GAME_STARTMENU_H
