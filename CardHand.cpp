//
// Created by vince on 3/27/2023.
//

#include "CardHand.h"

void CardHand::addCard(const Card &card)
{
    hand.push_back(card);
    if(hand.size() == 2)
        findHighCard();
    if(hand.size() >= 3)
        board.push_back(card);
}

std::ostream &operator<<(std::ostream &out, const CardHand &card)
{
    for (int i = 0; i < card.hand.size(); ++i) {
        out << card.hand[i].getStrRank()
        << " of " << card.hand[i].getStrSuit() << "\n";
    }
    /*for (int i = 0; i < 5; ++i)
    {
        out << "Board cards: " << card.board[i].getStrRank()
            << " of " << card.board[i].getStrSuit() << "\n";
    }*/
    return out;
}

Card& CardHand::operator[](unsigned int index)
{
    return hand[index];
}

bool operator>(const Card &lCard, const Card &rCard)
{
    return lCard.getRankNum() > rCard.getRankNum();
}

bool operator>=(const Card &lCard, const Card &rCard)
{
    return lCard.getRankNum() >= rCard.getRankNum();
}

bool operator!=(const Card &lCard, const Card &rCard)
{
    return lCard.getRankNum() != rCard.getRankNum() - 1;

}

bool operator==(const Card &lCard, const Card &rCard)
{
    return lCard.getStrSuit() == rCard.getStrSuit();
}

bool compareCardRank(const Card &lCard, const Card &rCard)
{
    return lCard.getRankNum() == rCard.getRankNum(); // compares rank only
}

int operator-(const Card &lCard, const Card &rCard)
{
    return lCard.getRankNum() - rCard.getRankNum();
}

void CardHand::bubbleSort(CardHand &cardHand)
{
    int i, j;
    for (i = 0; i < 7 - 1; i++)
        // Last i elements are already
        // in place
        for (j = 0; j < 7 - i - 1; j++)
            if (cardHand[j] > cardHand[j+1])
                swap(cardHand[j], cardHand[j+1]);
}

void CardHand::swap(Card &card1, Card &card2)
{
    Card temp = card1;
    card1 = card2;
    card2 = temp;
}

bool CardHand::checkForStraight(CardHand &ch)
{
    //# of cards
    int n = 5;

    for (int i = 1; i < n; i++)

        // Unsorted pair found
        if (ch[i - 1] != ch[i])
            return false;

    // No unsorted pair found
    return true;
}

bool CardHand::checkForSameSuit(CardHand &ch)
{
    for (int i = 1; i < 5; ++i) {
        if(ch[i - 1] == ch[i])
            continue;
        else
            return false;
    }
    return true;
}

bool CardHand::checkForSameRank(CardHand &ch)
{
    for (int i = 0; i < 7; ++i) {
        ch.count = 1;
        for (int j = i + 1; j < 7; ++j) {
            if(compareCardRank(ch[i], ch[j])){
                setHighPair(ch[j].getRankNum());
                ch.count++;
            }
        }
        ch.freq[i] = ch.count;
    }
    if(ch.getFreq() > 0)
        return true;
    return false;
}

int CardHand::getCount()
{
    return count;
}

int CardHand::getFreq()
{
    int count = 0;
    for (int i = 0; i < 7; ++i) {
        if(freq[i] == 2)
            count++;
        else if(freq[i] == 3)
        {
            count = 3;
            break;
        }
        else if(freq[i] == 4)
        {
            count = 4;
            break;
        }
    }
    return count;
}

bool CardHand::checkForFH(CardHand &ch)
{
    int count = 0;
    for (int i = 0; i < 5; ++i) {
        if(ch.freq[i] == 2)
            count++;
    }
    if(count == 1)
        return false;
    return true;
}

void CardHand::clearHand()
{
    hand.clear();
}

int CardHand::getHighCard()
{
    return highCard;
}

int CardHand::getKicker()
{
    return kicker;
}

int CardHand::getHighPair()
{
    return highPair;
}

void CardHand::findHighCard()
{
    if(hand[0] > hand[1])
    {
        highCard = hand[0].getRankNum();
        kicker = hand[1].getRankNum();
    }
    else
    {
        highCard = hand[1].getRankNum();
        kicker = hand[0].getRankNum();
    }
}

void CardHand::compareKicker(CardHand &hand1, CardHand &hand2)
{
    if(hand1.kicker > hand2.kicker){
         Game::player1Wins = true;
    }
    else
         Game::player2Wins = true;
}

bool CardHand::checkForPair(CardHand &hand1, CardHand &hand2)
{
    return false;
}

void CardHand::compareHighCard(CardHand &hand1, CardHand &hand2)
{
    if(hand1.highCard == hand2.highCard)
        compareKicker(hand1, hand2);
    else if(hand1.highCard > hand2.highCard){
         Game::player1Wins = true;
    }
    else
         Game::player2Wins = true;
}
void CardHand::setHighPair(int rankNum)
{
    if(rankNum > highPair)
        highPair = rankNum;
}

void CardHand::comparePairs(CardHand &hand1, CardHand &hand2)
{
    if(hand1.highPair == hand2.highPair){
        std::cout << "Compare high card\n";
        compareHighCard(hand1, hand2);
    }
    else if (hand1.highPair > hand2.highPair)
        Game::player1Wins = true;
    else
        Game::player2Wins = true;
}

void CardHand::compareRanks(CardHand &hand1, CardHand &hand2, int freq)
{
    if(hand1.getFreq() == freq && hand2.getFreq() == freq){
        std::cout << "pairs are the same\n";
        comparePairs(hand1, hand2);
    }
    else if(hand1.getFreq() == freq){
        std::cout << "player1 pair is bigger\n";
        Game::player1Wins = true;
    }
    else if(hand2.getFreq() == freq){
        std::cout << "player2 pair is bigger\n";
        Game::player2Wins = true;
    }
}

void CardHand::compareTwoPair(CardHand &hand1, CardHand &hand2, int freq)
{
    if(hand1.getFreq() == freq && hand2.getFreq() == freq){
        std::cout << "each have two pairs\n";
        comparePairs(hand1, hand2);
    }
    else if(hand1.getFreq() == freq && hand1.getFreq() == 1){
        std::cout << "player1 has 2 pairs and player2 has 1 pair";
        Game::player1Wins = true;
    }
    else if(hand2.getFreq() == freq && hand1.getFreq() == 1){
        std::cout << "player2 has 2 pairs and player1 has 1 pair\n";
        Game::player2Wins = true;
    }
}

void CardHand::setHighPair(CardHand &ch)
{
    for (int i = 0; i < 7; ++i) {
        ch.count = 1;
        for (int j = i + 1; j < 7; ++j) {
            if(compareCardRank(ch[i], ch[j])){
                setHighPair(ch[j].getRankNum());
                ch.count++;
            }
        }
        ch.freq[i] = ch.count;
    }
}

void CardHand::compareOnePair(CardHand &hand1, CardHand &hand2, int freq)
{
    if(hand1.getFreq() == freq && hand2.getFreq() == freq){
        std::cout << "pairs are the same\n";
        comparePairs(hand1, hand2);
    }
    else if(hand1.getFreq() == freq && (hand1.highPair > hand2.highPair)){
        std::cout << "player1 pair is bigger\n";
        Game::player1Wins = true;
    }
    else if(hand2.getFreq() == freq && (hand2.highPair > hand1.highPair)){
        std::cout << "player2 pair is bigger\n";
        Game::player2Wins = true;
    }
    else{
        std::cout << "comparing high cards\n";
        compareHighCard(hand1, hand2);
    }
}

void CardHand::resetHighPair()
{
    highPair = 0;
}

HighestAttribute CardHand::getHA()
{
    if(CardHand::straightUpdated(*this) && CardHand::checkForSameSuit(*this) &&
    (hand[0].getRankNum() == 10 || hand[1].getRankNum() == 10))
        return ROYALFLUSH;
    else if (CardHand::straightUpdated(*this) && CardHand::checkForSameSuit(*this))
        return STRAIGHTFLUSH;
    else if(CardHand::straightUpdated(*this))
        return STRAIGHT;
    else if(getHighPair() != 0)
    {
        if(getFreq() == 4)
        {
            return FOUROFAKIND;
        }
        else if(getFreq() == 3)
        {
            return THREEOFAKIND;
        }
        else if(getFreq() == 2)
        {
            return TWOPAIR;
        }
        else
        {
            return PAIR;
        }
    }
    else if(CardHand::checkForSameSuit(*this))
        return FLUSH;
    else
        return HIGHCARD;
}

void CardHand::findBoardPair()
{
    for (int i = 0; i < 7; ++i) {
        count = 1;
        for (int j = i + 1; j < 7; ++j) {
            if(compareCardRank(board[i], board[j])){
                setBoardPair(board[j].getRankNum());
                count++;
            }
        }
        freq[i] = count;
    }
}

void CardHand::setBoardPair(int rankNum)
{
    if(rankNum > boardPair)
        boardPair = rankNum;
}


int CardHand::getBoardPair()
{
    return boardPair;
}

void CardHand::sameAttribute(CardHand &cardHand1, CardHand &cardHand2)
{
    //checking same rank
    if(cardHand1.getHighPair() != 0 || cardHand2.getHighPair() != 0)
    {
        if(cardHand1.getFreq() == 4 || cardHand2.getFreq() == 4)
        {
            std::cout << "Four of a four\n";
            CardHand::compareRanks(cardHand1, cardHand2, 4);
        }
        else if(cardHand1.getFreq() == 3 || cardHand2.getFreq() == 3)
        {
            std::cout << "Three of a kind\n";
            CardHand::compareRanks(cardHand1, cardHand2, 3);
        }
        else if(cardHand1.getFreq() == 2 || cardHand2.getFreq() == 2)
        {
            std::cout << "Two pair\n";
            CardHand::compareRanks(cardHand1,cardHand2, 2);
        }
        else if (cardHand1.getFreq() == 1 || cardHand2.getFreq() == 1){
            std::cout << "Pair\n";
            CardHand::compareRanks(cardHand1, cardHand2, 1);
        }
    }
    else
        CardHand::compareHighCard(cardHand1, cardHand2);
}

bool CardHand::straightUpdated(CardHand &ch)
{
    for(int i = 1; i < 7; i++)
        if(ch.hand[i] - ch.hand[i-1] > 1)
            return false;
    return true;
}













