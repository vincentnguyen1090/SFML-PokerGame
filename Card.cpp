//
// Created by vince on 3/26/2023.
//

#include "Card.h"
Card::Card()
{

}

Card::Card(std::string suit, std::string value)
: strSuit(suit), strRank(value)
{

}
Card::Card(suitENUM suit, rankENUM rank)
:suit(suit), rank(rank)
{
    strSuit = s[suit];
    strRank = r[rank];
    rankNum = rankArr[rank];
}

std::ostream& operator<<(std::ostream& out, const Card& card)
{
    return out << card.strRank << " of " << card.strSuit;
}

std::string Card::getStrSuit() const
{
    return strSuit;
}

std::string Card::getStrRank() const
{
    return strRank;
}

int Card::getRankNum() const
{
    return rankNum;
}

rankENUM Card::getRank() const
{
    return rank;
}

suitENUM Card::getSuit() const
{
    return suit;
}




