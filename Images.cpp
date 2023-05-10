//
// Created by vince on 4/10/2023.
//

#include "Images.h"
//this creates out static in our cpp since static is not actually created yet
//this only needs to be created only one time
//objects only need to use this one map
std::map<imagesENUM, sf::Texture> Images::textures;
std::map<fontENUM, sf::Font> Images::fonts;

std::string Images::getPath(imagesENUM image)
{
    switch(image)
    {
        case BUTTON: return "Images/ButtonTemplate.png";
        case POKERBOARD: return "Images/poker_board.jpg";
        case POKERCHIP: return "Images/pokerchip.png";
        case START: return "Images/Start-Button.png";
        case CONTINUE: return "Images/continuebutton (1).png";
        case POKERIMAGE: return "Images/PokerImage.png";
        default: return "";
    }
}

std::string Images::getPath(fontENUM font)
{
    switch(font)
    {
        case RETRO: return "Images/RetroGrade-K7ow7.otf";
        case MONEY: return "Images/BillyMoneyRegular-JReoj.ttf";
        case NAME: return "Images/NameSmile-qLz1.ttf";
        case POKERTITLE: return "Images/ClearSansMedium-D8vR.ttf";
        default: return "";
    }
}

void Images::load(fontENUM font)
{
    fonts[font].loadFromFile(getPath(font));
}

void Images::load(imagesENUM image)
{
    //get the texture that is matched to the image enum
    //mapping image to a file path
    textures[image].loadFromFile(getPath(image));
}

sf::Texture &Images::getImage(imagesENUM image)
{
    load(image);
    return textures[image];
}

sf::Font &Images::getFont(fontENUM font)
{
    load(font);
    return fonts[font];
}
