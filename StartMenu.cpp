//
// Created by vince on 5/1/2023.
//

#include "StartMenu.h"
#include "Poker.h"
StartMenu::StartMenu()
{
    startButton.setTexture(Images::getImage(START));
    TransformButton::setCenterOrigin(startButton);
    cutSpite();
    scaleButton();
    posButton();
    setImage();
    setText();
}

void StartMenu::cutSpite()
{
    intRect.left = 0;
    intRect.top = 0;
    intRect.width = 1390;
    intRect.height = 580;
    startButton.setTextureRect(intRect);
}

void StartMenu::setText()
{
    title.setFont(Images::getFont(POKERTITLE));
    TransformButton::transformText(title, "POKER", sf::Vector2f(512, 200));
    scaleTitle();
    myInfo.setFont(Images::getFont(NAME));
    TransformButton::transformText(myInfo, "Vincent Nguyen   CRN:37045   Spring2023", sf::Vector2f(512,30));
    myInfo.setScale(sf::Vector2f(0.8, 0.8));
}

void StartMenu::posButton()
{
    startButton.setPosition(sf::Vector2f(512, 400));
}

void StartMenu::scaleButton()
{
    startButton.setScale(sf::Vector2f(0.15, 0.15));
}

void StartMenu::scaleTitle()
{
    title.setScale(sf::Vector2f(5,5));
}

void StartMenu::setImage()
{
    image.setTexture(Images::getImage(POKERIMAGE));
    TransformButton::setCenterOrigin(image);
    image.setScale(sf::Vector2f(0.2,0.2));
    image.setPosition(812, startButton.getPosition().y + 180);
}

void StartMenu::update()
{

}

void StartMenu::eventHandler(sf::RenderWindow &window, sf::Event event)
{
    if(MouseEvents::isHovered(startButton.getGlobalBounds(), window))
        ShadeColor::shadeColor(startButton, originalColor);
    else
        ShadeColor::shadeOriginalCol(startButton, originalColor);

    if(MouseEvents::isClicked(startButton.getGlobalBounds(), window))
    {
        Poker::clearMenu();
    }
}

void StartMenu::draw(sf::RenderTarget &target, sf::RenderStates states) const
{
    target.draw(board);
    target.draw(startButton);
    target.draw(image);
    target.draw(title);
    target.draw(myInfo);
}