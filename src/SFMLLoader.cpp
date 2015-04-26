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
    }
    texture->setSmooth(true);
    sprite->setTexture(*texture);
    sprite->setPosition(pos.first, pos.second);
    this->_sprites.insert(std::pair<std::string, sf::Sprite*>(nameOfSprite, sprite));
}

void            SFMLLoader::setPosition(const std::string& nameOfSprite, const sf::Vector2f& newPos) {
    this->_sprites.find(nameOfSprite)->second->setPosition(newPos);
}

sf::Sprite*     SFMLLoader::findSprite(const std::string& nameOfSprite) {
    return (this->_sprites.find(nameOfSprite)->second);
}

bool            SFMLLoader::updateSprite(const std::string& nameOfSprite, const std::string& pathToFile) {
    sf::Texture *new_texture = new sf::Texture();
    sf::Sprite  *new_sprite = new sf::Sprite();
    sf::Sprite  *old_sprite = NULL;

    old_sprite = this->_sprites.find(nameOfSprite)->second;
    if (!old_sprite) {
        std::cerr << "No sprite found" << std::endl;
        return (false);
    }
    new_texture->loadFromFile(pathToFile);
    new_texture->setSmooth(true);
    new_sprite->setTexture(*new_texture);
    new_sprite->setPosition(old_sprite->getPosition().x, old_sprite->getPosition().y);
    this->_sprites[nameOfSprite] = new_sprite;
    delete old_sprite;
    return (true);
}
