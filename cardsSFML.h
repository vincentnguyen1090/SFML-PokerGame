//
// Created by vince on 3/29/2023.
//

#ifndef SFMLAPPLICATIONS_CARDSSFML_H
#define SFMLAPPLICATIONS_CARDSSFML_H
#include "Component.h"
#include "rankENUM.h"
#include "suitENUM.h"
class cardsSFML : public Component
{
private:
    rankENUM rank;
    suitENUM suit;
    sf::Sprite background;
    sf::IntRect intRect;
    static sf::Texture texture;
    void updateCard(rankENUM rank, suitENUM suit);
    bool flipped = false;
public:
    cardsSFML();
    cardsSFML(rankENUM rank, suitENUM suit, bool isFlipped);
    void draw(sf::RenderTarget &target, sf::RenderStates states) const override;
    void setPosition(float x, float y);
    void setRotation(float angle);
    void setScale();
    void flipCard();
    void setCardOrientation(bool isFlipped);
    sf::Sprite getBackground() const;

    void update() override;
    void eventHandler(sf::RenderWindow &window, sf::Event event) override;
};


#endif //SFMLAPPLICATIONS_CARDSSFML_H
