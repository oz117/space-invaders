/*
** File: [Adversary.cpp]
** Author: zero.
** Contact: <andre.paulos@epitech.eu> (github.com/oz117)
** Created on 2015-04-17 21:00
**
*/

#include "Adversary.hpp"

Adversary::Adversary(const std::vector<pair2s>& sprites, const pair2f& pos, const std::string& nbOfSprite) {
    this->_adversary_sprite.create(sprites, pair2i(0, 0), nbOfSprite);
    this->_pos = pos;
}

Adversary::~Adversary(void) {
}

const float&    Adversary::getX(void) const {
    return (this->_pos.first);
}

const pair2f&   Adversary::getPosition(void) const {
    return (this->_pos);
}

void            Adversary::setPosition(const pair2f& newPosition) {
    this->_pos = newPosition;
}

void            Adversary::checkPosition(pair2f& newPosition) {
    if (newPosition.first >= X_SIZE) {
        newPosition.first = 0;
        newPosition.second += ADVERSARY_FALL_SPEED;
    }
}

Sprite&   Adversary::getSprite(void) {
    return (this->_adversary_sprite);
}

void            Adversary::move(void) {
    pair2f      newPosition;

    newPosition = this->getPosition();
    newPosition.first += ADVERSARY_SPEED;
    checkPosition(newPosition);
    this->setPosition(newPosition);
}
