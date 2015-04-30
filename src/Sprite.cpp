/*
** nameOfSprite: [Sprite.cpp]
** Author: zero.
** Contact: <andre.paulos@epitech.eu> (github.com/oz117)
** Created on 2015-04-07 19:28
**
*/

#include "Sprite.hpp"

Sprite::Sprite(void) {
    this->_sprites.resize(1);
    this->_sprites[0].first = "";
    this->_sprites[0].second = "";
    this->_currentSprite = 0;
    this->_nextSprite = 0;
    this->_size = std::pair<int, int>(0, 0);
}

Sprite::Sprite(const std::vector<pair2s>& sprites, const pair2i& size) {
    this->_sprites = sprites;
    this->_size = size;
    this->_currentSprite = 0;
    this->_nextSprite = 1;
}

Sprite::~Sprite(void) {
}

void                Sprite::create(const std::vector<pair2s>& sprites, const pair2i& size, const std::string& nbOfSprite) {
    this->_sprites = sprites;
    this->_size = size;
    this->_nbOfSprite = nbOfSprite;
    this->_nextSprite = 1;
}

const std::vector<pair2s>&      Sprite::getSprites(void) const {
    return (this->_sprites);
}

const pair2s&                   Sprite::getIndex(int index) const {
    return (this->_sprites[index]);
}

const std::string               Sprite::getNameOfCurrentSprite(void) const {
    return (this->_sprites[this->_currentSprite].first + this->_nbOfSprite);
}

const std::string               Sprite::getNameOfNextSprite(void) const {
    return (this->_sprites[this->_nextSprite].first + this->_nbOfSprite);
}

void                            Sprite::setNextSprite(const int newNextSprite) {
    this->_nextSprite = newNextSprite;
}

void                            Sprite::setCurrentSprite(const int newCurrentSprite) {
    this->_currentSprite = newCurrentSprite;
}

const std::string&              Sprite::getPathNextSprite(void) {
    if (this->_nextSprite == 1) {
        this->setCurrentSprite(this->_nextSprite);
        this->setNextSprite(0);
    }
    else {
        this->setCurrentSprite(0);
        this->setNextSprite(1);
    }
    return (this->_sprites[this->_currentSprite].second);
}
