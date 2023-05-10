//
// Created by vince on 4/26/2023.
//

#ifndef POKER_GAME_MONEY_H
#define POKER_GAME_MONEY_H
#include "Component.h"

//drawing the pot and money of each player
//will update money based on actions each player does

class Money : public Component
{
private:
    static int p1Money, p2Money , fifty, tableMoney;
    static sf::Text t_pot, text1, text2, cash;
    static std::string myMoney;
    static std::string potMoney;
    void setScale();
public:
    static int counter;
    Money();

    static void updateEarnings();
    static void matchBet(bool turn);
    void setPlayerMoney();
    void setPlayerMoneyPosOne(sf::Vector2f pos);
    void setPlayerMoneyPosTwo(sf::Vector2f pos);
    static void updateMoney();

    void update() override;
    void eventHandler(sf::RenderWindow &window, sf::Event event) override;
    void draw(sf::RenderTarget &target, sf::RenderStates states) const override;
};


#endif //POKER_GAME_MONEY_H
