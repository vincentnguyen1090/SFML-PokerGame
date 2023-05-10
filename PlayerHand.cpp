//
// Created by vince on 4/19/2023.
//

#include "PlayerHand.h"

PlayerHand::PlayerHand()
{

}

void PlayerHand::addCard(const Card &c)
{
    playerCard.push_back(cardsSFML(c.getRank(), c.getSuit(), true));
    cards.push_back(Card(c.getSuit(), c.getRank()));
}

void PlayerHand::draw(sf::RenderTarget &target, sf::RenderStates states) const
{
    for (const auto& card : playerCard) {
        target.draw(card);
    }
}

void PlayerHand::positionPlayerOneHand()
{
    playerCard.at(0).setPosition(50, 550);
    playerCard.at(1).setPosition(150, 525);
}


void PlayerHand::positionPlayerTwoHand()
{
    playerCard.at(0).setPosition(750,550);
    playerCard.at(1).setPosition(850,525);
}

void PlayerHand::rotateCard()
{
    ApplyRotation::Rotate(playerCard);
}

void PlayerHand::update()
{

}

void PlayerHand::eventHandler(sf::RenderWindow &window, sf::Event event)
{
    if (event.type == sf::Event::MouseButtonPressed && event.mouseButton.button == sf::Mouse::Left)
    {
        for (cardsSFML &card: playerCard)
        {
            if (MouseEvents::isClicked(card.getBackground().getGlobalBounds(), window))
            {
                card.flipCard();
            }
        }
    }
}

Card& PlayerHand::getCard()
{
    return cards[index++];
}

void PlayerHand::clearHand()
{
    playerCard.clear();
    cards.clear();
    index = 0;
}











