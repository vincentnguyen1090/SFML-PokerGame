//
// Created by vince on 4/19/2023.
//

#ifndef POKER_GAME_PLAYERHAND_H
#define POKER_GAME_PLAYERHAND_H
#include "Deck.h"
#include "Check.h"
#include "Call.h"
#include "Fold.h"
#include "Raise.h"
#include "cardsSFML.h"
#include <vector>
#include <SFML/Graphics.hpp>
#include "ApplyRotation.h"
class PlayerHand : public Component
{
private:
    std::vector<cardsSFML> playerCard;
    std::vector<Card> cards;
    int index = 0;
public:
    PlayerHand();
    void addCard(const Card &c);
    void positionPlayerOneHand();
    void positionPlayerTwoHand();
    void rotateCard();
    Card& getCard();

    void clearHand();
    void update() override;
    void eventHandler(sf::RenderWindow &window, sf::Event event) override;
    void draw(sf::RenderTarget &target, sf::RenderStates states) const override;

};


#endif //POKER_GAME_PLAYERHAND_H
