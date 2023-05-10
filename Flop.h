//
// Created by vince on 4/25/2023.
//

#ifndef POKER_GAME_FLOP_H
#define POKER_GAME_FLOP_H
#include "Component.h"
#include "cardsSFML.h"
#include "Deck.h"

class Poker;

class Flop : public Component
{
private:
    std::vector<cardsSFML> flop;
    std::vector<Card> cards;
public:
    static int index;

    void clearFlop();
    Card& getCard();
    void positionFlop();
    void fillFlop(const Card &c);
    void update() override;
    void eventHandler(sf::RenderWindow &window, sf::Event event) override;
    void draw(sf::RenderTarget &target, sf::RenderStates states) const override;
};


#endif //POKER_GAME_FLOP_H
