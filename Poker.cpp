//
// Created by vince on 4/29/2023.
//

#include "Poker.h"
Deck Poker::deck;
Flop Poker::flop;
Turn Poker::turn;
River Poker::river;
PlayerHand Poker::p1Hand;
PlayerHand Poker::p2Hand;
CardHand Poker::cardHand1;
CardHand Poker::cardHand2;

sf::RenderWindow Poker::window;
std::vector<Component*> Poker::outcomeSet;
std::vector<Component*> Poker::components;
std::vector<Component*> Poker::cardHands;
std::vector<Component*> Poker::flopSet;
std::vector<Component*> Poker::turnSet;;
std::vector<Component*> Poker::riverSet;
std::vector<Component*> Poker::setOne;
std::vector<Component*> Poker::setTwo;
std::vector<Component*> Poker::startScreen;

void Poker::addComponent(Component &component)
{
    components.push_back(&component);
}

void Poker::addPlayerHands(Component &component)
{
    cardHands.push_back(&component);
}

void Poker::addTurn(Component &component)
{
    turnSet.push_back(&component);
}

void Poker::addFlop(Component &component)
{
    flopSet.push_back(&component);
}

void Poker::addRiver(Component &component)
{
    riverSet.push_back(&component);
}

void Poker::addSetOne(Component &component)
{
    setOne.push_back(&component);
}

void Poker::addSetTwo(Component &component)
{
    setTwo.push_back(&component);
}

void Poker::clearSetOne()
{
    setOne.clear();
}

void Poker::clearMenu()
{
    startScreen.clear();
}

void Poker::addStartMenu(Component &component)
{
    startScreen.push_back(&component);
}

void Poker::addPlayerHands()
{
    addPlayerHands(p1Hand);
    addPlayerHands(p2Hand);
}

void Poker::addFlop()
{
    Poker::addFlop(flop);
}

void Poker::addTurn()
{
    Poker::addTurn(turn);
}

void Poker::addRiver()
{
    Poker::addRiver(river);
}

void Poker::addSetOne()
{
    Poker::addSetOne(check);
    Poker::addSetOne(raise);
    Poker::addSetOne(fold);
    Game::playerCall = false;
}

void Poker::addSetTwo()
{
    Poker::addSetTwo(call);
    Poker::addSetTwo(raise);
    Poker::addSetTwo(fold);
}

void Poker::addStartMenu()
{
    Poker::addStartMenu(menu);
}

void Poker::addDefaultComponent()
{
    Poker::addComponent(defaultSet);
    Poker::addComponent(money);
    Poker::addComponent(player1Tag);
    Poker::addComponent(player2Tag);
    addSetOne();
    addSetTwo();
}

void Poker::addOutcome()
{
    Poker::addOutcome(outcome);
}

void Poker::clearOutcome()
{
    outcomeSet.clear();
}

void Poker::addOutcome(Component &component)
{
    outcomeSet.push_back(&component);
}

void Poker::dealCards()
{
    for (int i = 0; i < 2; ++i)
    {
        p1Hand.addCard(deck.dealCard());
        p2Hand.addCard(deck.dealCard());
    }

    p1Hand.rotateCard();
    p2Hand.rotateCard();
    p1Hand.positionPlayerOneHand();
    p2Hand.positionPlayerTwoHand();
}

void Poker::setFlop()
{
    for (int i = 0; i < 3; ++i)
    {
        flop.fillFlop(deck.dealCard());
    }
    flop.positionFlop();
}

void Poker::setCards()
{
    dealCards();
    setFlop();
    setTurn();
    setRiver();
    fillCardHands();
}


void Poker::setTurn()
{
    turn.createTurnCard(deck.dealCard());
}

void Poker::setRiver()
{
    river.createRiverCard(deck.dealCard());
}

void Poker::positionItems()
{
    chip1.setPositionOne();
    chip2.setPositionTwo();
    money.setPlayerMoneyPosOne(chip1.getChipPos());
    money.setPlayerMoneyPosTwo(chip2.getChipPos());
    player1Tag.setPositionOne(chip1._getChipPos());
    player2Tag.setPositionTwo(chip2._getChipPos());
}

void Poker::setPlayerNames()
{
    player1Tag.setString("Player1");
    player2Tag.setString("Player2");
}

Poker::Poker()
{
    addStartMenu();

    addDefaultComponent();
    setPlayerNames();
    positionItems();
    setCards();
    Poker::addPlayerHands();

    runGame();
}

void Poker::runGame()
{
    window.create({1024, 720, 32}, "Poker");
    window.setFramerateLimit(60);
    while(window.isOpen())
    {
        sf::Event event;
        while(window.pollEvent(event))
        {
            for(Component* c: startScreen)
                c->eventHandler(window, event);
            if(event.type == sf::Event::Closed)
                window.close();
            for(Component* c : cardHands)
                c->eventHandler(window, event);
            for(Component* c : components)
                c->eventHandler(window, event);
            for(Component* c: components)
                c->update();
            for(Component* c: outcomeSet)
                c->eventHandler(window, event);
            if(!setOne.empty())
            {
                for(Component* item: setOne)
                    item->eventHandler(window, event);
                for(Component* item: setOne)
                    item->update();
            }
            else if(!setTwo.empty())
            {
                for(Component* item: setTwo)
                    item->eventHandler(window, event);
                for(Component* item: setTwo)
                    item->update();
            }
        }
        window.clear(sf::Color::White);

        for(Component* item : components)
            window.draw(*item);
        if(!setOne.empty()) {
            for(Component* item : setOne)
                window.draw(*item);
        }
        if(Game::player1Raise || Game::player2Raise) {
            for(Component* item : setTwo)
                window.draw(*item);
        }
        if(Game::playerCall || Game::fold) {
            if(setOne.empty()) {
                addSetOne();
            }
        }
        drawCards();
        if(Game::roundOver || winner())
        {
            Money::updateEarnings();
            addOutcome();
            drawOutcome();
            if(Game::continueBut){
                clearOutcome();
                Poker::restartGame();
                Game::roundOver = false;
            }
        }
        drawStartScreen();
        window.display();
    }
}
void Poker::drawStartScreen()
{
    if(!startScreen.empty()) {
        for(Component* item : startScreen)
            window.draw(*item);
    }
}

void Poker::drawCards()
{
    if(!cardHands.empty()){
        for(Component* item : cardHands)
            window.draw(*item);
    }
    if(!flopSet.empty()){
        for(Component* item: flopSet)
            window.draw(*item);
    }
    if(!turnSet.empty()){
        for(Component* item: turnSet)
            window.draw(*item);
    }
    if(!riverSet.empty()){
        for(Component* item: riverSet)
            window.draw(*item);
    }
}

void Poker::restartGame()
{
    Game::continueBut = false;
    deck.shuffle();
    Game::resetBools();
    clearBoard();
    setCards();
    Poker::addPlayerHands();
}

void Poker::clearBoard()
{
    clearCardVectors();
    clearCardObj();
}

void Poker::clearCardVectors()
{
    cardHands.clear();
    flopSet.clear();
    turnSet.clear();
    riverSet.clear();
}

void Poker::clearCardObj()
{
    p1Hand.clearHand();
    p2Hand.clearHand();
    cardHand1.clearHand();
    cardHand2.clearHand();
    flop.clearFlop();
}

void Poker::drawOutcome()
{
    if(!outcomeSet.empty()){
        for(Component* item : outcomeSet)
            window.draw(*item);
    }
}
///CALCULATE SCORES
void Poker::fillCardHands()
{
    cardHand1.resetHighPair();
    cardHand2.resetHighPair();

    for (int i = 0; i < 2; ++i)
    {
        cardHand1.addCard(p1Hand.getCard());
        cardHand2.addCard(p2Hand.getCard());
    }

    std::cout << "Hand1 kicker: " << cardHand1.getKicker() << "\n";
    std::cout << "Hand1 high: " << cardHand1.getHighCard() << "\n";

    std::cout << "Hand2 kicker: " << cardHand2.getKicker() << "\n";
    std::cout << "Hand2 high: " << cardHand2.getHighCard() << "\n";

    Flop::index = 0;
    for (int i = 0; i < 3; ++i)
    {
        cardHand1.addCard(flop.getCard());
    }
    Flop::index = 0;
    for (int i = 0; i < 3; ++i)
    {
        cardHand2.addCard(flop.getCard());
    }
    cardHand1.addCard(turn.getCard());
    cardHand2.addCard(turn.getCard());
    cardHand1.addCard(river.getCard());
    cardHand2.addCard(river.getCard());

}

bool Poker::winner()
{
    return (Game::player1Wins || Game::player2Wins);
}

void Poker::sortHands()
{
    CardHand::bubbleSort(cardHand1);
    CardHand::bubbleSort(cardHand2);
}

void Poker::findWinner()
{
    sortHands();
    cardHand1.setHighPair(cardHand1);
    cardHand2.setHighPair(cardHand2);

    if(cardHand1.getHA() == cardHand2.getHA())
        CardHand::sameAttribute(cardHand1, cardHand2);
    else if(cardHand1.getHA() > cardHand2.getHA())
        Game::player1Wins = true;
    else
        Game::player2Wins = true;


    Poker::winner();
}














