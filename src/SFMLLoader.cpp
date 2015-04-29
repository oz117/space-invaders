/*
** File: [SFMLLoader.cpp]
** Author: zero.
** Contact: <andre.paulos@epitech.eu> (github.com/oz117)
** Created on 2015-04-09 23:48
**
*/

#include "SFMLLoader.hpp"

SFMLLoader::SFMLLoader(void) {
}

SFMLLoader::~SFMLLoader(void) {
    for (auto it = this->_sprites.begin(); it != this->_sprites.end(); ++it) {
        delete (*it).second;
    }
    for (auto it = this->_textures.begin(); it != this->_textures.end(); ++it) {
        delete (*it).second;
    }
}

std::map<std::string, sf::Sprite*>& SFMLLoader::getSprites(void) {
    return (this->_sprites);
}

void            SFMLLoader::load(const std::string& nameOfSprite, const std::string& pathToFile,
        const pair2f& pos) {
    sf::Texture *texture = new sf::Texture();
    sf::Sprite  *sprite = new sf::Sprite();

    if (!texture->loadFromFile(pathToFile)){
        std::cerr << "Error could not load " << nameOfSprite << std::endl;
        return ;
    }
    texture->setSmooth(true);
    sprite->setTexture(*texture);
    sprite->setPosition(pos.first, pos.second);
    this->_sprites.insert(std::pair<std::string, sf::Sprite*>(nameOfSprite, sprite));
    this->_textures.insert(std::pair<std::string, sf::Texture*>(nameOfSprite, texture));
}

void            SFMLLoader::setPosition(const std::string& nameOfSprite, const sf::Vector2f& newPos) {
    this->_sprites.find(nameOfSprite)->second->setPosition(newPos);
}

sf::Sprite*     SFMLLoader::findSprite(const std::string& nameOfSprite) {
    return (this->_sprites.find(nameOfSprite)->second);
}

bool            SFMLLoader::updateSprite(const std::string& nameOfSprite, const std::string& pathToFile) {
    sf::Texture *texture;
    sf::Sprite  *sprite;

    sprite = NULL;
    texture = NULL;
    sprite = this->_sprites.find(nameOfSprite)->second;
    texture = this->_textures.find(nameOfSprite)->second;
    if (!sprite || !texture) {
        std::cerr << "No sprite found" << std::endl;
        return (false);
    }
    texture->loadFromFile(pathToFile);
    texture->setSmooth(true);
    sprite->setTexture(*texture);
    return (true);
}
