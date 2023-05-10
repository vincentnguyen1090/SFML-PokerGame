//
// Created by vince on 3/27/2023.
//

#include "CardHandScorer.h"
/*
PokerScore CardHandScorer::scorePokerHand(CardHand &ch)
{
    PokerScore pokerScore;


    //royal flush
    if(CardHand::checkForStraight(ch) && (ch[0].getRankNum() == 10) && CardHand::checkForSameSuit(ch))
    {
        pokerScore.scores.push_back(ROYAL_FLUSH);
        pokerScore.scores.push_back(STRAIGHT_FLUSH);
        pokerScore.scores.push_back(FLUSH);
        pokerScore.scores.push_back(STRAIGHT);
        pokerScore.scores.push_back(HIGH_CARD);
    }
    //straight flush
    else if(CardHand::checkForStraight(ch) && CardHand::checkForSameSuit(ch))
    {
        pokerScore.scores.push_back(STRAIGHT_FLUSH);
        pokerScore.scores.push_back(FLUSH);
        pokerScore.scores.push_back(STRAIGHT);
        pokerScore.scores.push_back(HIGH_CARD);
    }
    //straight
    else if(CardHand::checkForStraight(ch))
    {
        pokerScore.scores.push_back(STRAIGHT);
        pokerScore.scores.push_back(HIGH_CARD);
    }

    else if(CardHand::checkForSameRank(ch))
    {
        //full house
        if(ch.getFreq() == 3 && CardHand::checkForFH(ch))
        {
            pokerScore.scores.push_back(FULL_HOUSE);
            pokerScore.scores.push_back(THREE_OF_A_KIND);
            pokerScore.scores.push_back(ONE_PAIR);
            pokerScore.scores.push_back(HIGH_CARD);
        }
        //four of a kind
        else if(ch.getFreq() == 4)
        {
            pokerScore.scores.push_back(FOUR_OF_A_KIND);
            pokerScore.scores.push_back(THREE_OF_A_KIND);
            pokerScore.scores.push_back(ONE_PAIR);
            pokerScore.scores.push_back(HIGH_CARD);
        }
        //three of a kind
        else if(ch.getFreq() == 3)
        {
            pokerScore.scores.push_back(THREE_OF_A_KIND);
            pokerScore.scores.push_back(ONE_PAIR);
            pokerScore.scores.push_back(HIGH_CARD);
        }
        //two of a kind
        else if(ch.getFreq() == 2)
        {
            pokerScore.scores.push_back(TWO_PAIR);
            pokerScore.scores.push_back(ONE_PAIR);
            pokerScore.scores.push_back(HIGH_CARD);
        }
        //one pair
        else
        {
            pokerScore.scores.push_back(ONE_PAIR);
            pokerScore.scores.push_back(HIGH_CARD);
        }
    }
    //flush
    else if(CardHand::checkForSameSuit(ch))
    {
        pokerScore.scores.push_back(FLUSH);
        pokerScore.scores.push_back(HIGH_CARD);
    }
    else
        pokerScore.scores.push_back(HIGH_CARD);

    return pokerScore;

}
*/


















