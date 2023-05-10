//
// Created by vince on 4/25/2023.
//

#ifndef POKER_GAME_RIVER_H
#define POKER_GAME_RIVER_H
#include "Component.h"
#include "cardsSFML.h"
#include "Deck.h"

class River : public Component
{
    cardsSFML river;
    Card card;
public:
    Card& getCard();
    void createRiverCard(const Card &c);

    void update() override;

    void eventHandler(sf::RenderWindow &window, sf::Event event) override;

    void draw(sf::RenderTarget &target, sf::RenderStates states) const override;
};

#endif //POKER_GAME_RIVER_H
