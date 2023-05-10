//
// Created by vince on 4/25/2023.
//

#ifndef POKER_GAME_TURN_H
#define POKER_GAME_TURN_H
#include "Component.h"
#include "cardsSFML.h"
#include "Deck.h"
class Turn : public Component
{
    cardsSFML turn;
    Card card;
    int index = 0;
public:
    Card& getCard();
    void createTurnCard(const Card &c);
    void update() override;
    void eventHandler(sf::RenderWindow &window, sf::Event event) override;
    void draw(sf::RenderTarget &target, sf::RenderStates states) const override;
};


#endif //POKER_GAME_TURN_H
