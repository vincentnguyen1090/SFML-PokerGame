//
// Created by vince on 4/10/2023.
//

#ifndef SFMLAPPLICATIONS_IMAGES_H
#define SFMLAPPLICATIONS_IMAGES_H
#include <map>
#include <SFML/Graphics.hpp>
enum imagesENUM
{
    BUTTON, POKERBOARD, POKERCHIP, START, CONTINUE, POKERIMAGE, LAST_IMAGE
};
enum fontENUM
{
    RETRO, MONEY, NAME, POKERTITLE, LAST_FONT
};
class Images
{
private:
    static std::map<imagesENUM, sf::Texture> textures;
    static std::map<fontENUM, sf::Font> fonts;
    static std::string getPath(imagesENUM image);
    static std::string getPath(fontENUM font);
    static void load(fontENUM font);
    static void load(imagesENUM image);
public:
    static sf::Texture& getImage(imagesENUM image);
    static sf::Font& getFont(fontENUM font);
};


#endif //SFMLAPPLICATIONS_IMAGES_H
