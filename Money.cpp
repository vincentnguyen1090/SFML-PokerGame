//
// Created by vince on 4/26/2023.
//

#include "Money.h"
int Money::counter = 1;
int Money::p1Money = 1000;
int Money::p2Money = 1000;
int Money::fifty = 50;
int Money::tableMoney = 0;
sf::Text Money::cash;
sf::Text Money::t_pot;
sf::Text Money::text1;
sf::Text Money::text2;
std::string Money::myMoney;
std::string Money::potMoney;

Money::Money()
{
    t_pot.setFont(Images::getFont(MONEY));
    cash.setFont(Images::getFont(MONEY));
    TransformButton::transformMoney(t_pot, "Pot: $", sf::Vector2f(582, 67));
    TransformButton::transformCash(cash, "0", sf::Vector2f(576, 3));
    setScale();
    setPlayerMoney();
}

void Money::setScale()
{
    t_pot.setScale(2.2, 2.2);
    cash.setScale(2.2, 2.2);
}

void Money::updateMoney()
{
    if(Game::player1Raise)
    {
        std::cout << "Update p1 money\n";
        p1Money = p1Money - (fifty * counter);
        myMoney = std::to_string(p1Money);
        tableMoney = tableMoney + (fifty * counter);
        potMoney = std::to_string(tableMoney);
        text1.setString(myMoney);
        cash.setString(potMoney);
        counter++;
    }
    else if(Game::player2Raise)
    {
        std::cout << "Update p2 money\n";
        p2Money = p2Money - (fifty * counter);
        myMoney = std::to_string(p2Money);
        tableMoney = tableMoney + (fifty * counter);
        potMoney = std::to_string(tableMoney);
        text2.setString(myMoney);
        cash.setString(potMoney);
        counter++;
    }

}

void Money::update()
{

}

void Money::eventHandler(sf::RenderWindow &window, sf::Event event)
{

}

void Money::draw(sf::RenderTarget &target, sf::RenderStates states) const
{
    target.draw(t_pot);
    target.draw(cash);
    target.draw(text1);
    target.draw(text2);
}

void Money::setPlayerMoney()
{
    text1.setFont(Images::getFont(MONEY));
    TransformButton::transformText(text1, "$1000");
    text2.setFont(Images::getFont(MONEY));
    TransformButton::transformText(text2, "$1000");
}

void Money::setPlayerMoneyPosOne(sf::Vector2f pos)
{
    text1.setPosition(pos);
}

void Money::setPlayerMoneyPosTwo(sf::Vector2f pos)
{
    text2.setPosition(pos);
}

void Money::matchBet(bool turn)
{
    if(Game::player1Turn == turn)
    {
        std::cout << "Player1 Match Bet\n";
        int temp = p1Money - p2Money;
        tableMoney = tableMoney + temp;
        p1Money = p2Money;
        myMoney = std::to_string(p1Money);
        text1.setString(myMoney);
        potMoney = std::to_string(tableMoney);
        cash.setString(potMoney);
    }
    else
    {
        std::cout << "Player2 Match Bet\n";
        int temp = p2Money - p1Money;
        tableMoney = tableMoney + temp;
        p2Money = p1Money;
        myMoney = std::to_string(p2Money);
        text2.setString(myMoney);
        potMoney = std::to_string(tableMoney);
        cash.setString(potMoney);
    }
}

void Money::updateEarnings()
{
    if(Game::player1Turn || Game::player2Wins)
    {
        p2Money += tableMoney;
        myMoney = std::to_string(p2Money);
        text2.setString(myMoney);
        tableMoney = 0;
        potMoney = std::to_string(tableMoney);
        cash.setString(potMoney);
    }
    else
    {
        p1Money += tableMoney;
        myMoney = std::to_string(p1Money);
        text1.setString(myMoney);
        tableMoney = 0;
        potMoney = std::to_string(tableMoney);
        cash.setString(potMoney);
    }
}



