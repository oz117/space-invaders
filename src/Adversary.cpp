/*
** File: [Adversary.cpp]
** Author: zero.
** Contact: <andre.paulos@epitech.eu> (github.com/oz117)
** Created on 2015-04-17 21:00
**
*/

#include "Adversary.hpp"

Adversary::Adversary(void) {
    this->_nextSprite = 1;
}

Adversary::~Adversary(void) {
}

int             Adversary::getSpriteNumber(void) {
    return (this->_spriteNumber);
}

void            Adversary::setSpriteNumber(int spriteNumber) {
    this->_spriteNumber = spriteNumber;
}

int             Adversary::getNextSprite(void) {
    return (this->_nextSprite);
}

void            Adversary::setNextSprite(int nextSprite) {
    this->_nextSprite = nextSprite;
}

int             Adversary::getCurrentSprite(void) {
    return (this->_currentSprite);
}

void            Adversary::setCurrentSprite(int currentSprite) {
    this->_currentSprite = currentSprite;
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

void            Adversary::move(void) {
    pair2f      newPosition;

    newPosition = this->getPosition();
    newPosition.first += ADVERSARY_SPEED;
    checkPosition(newPosition);
    this->setPosition(newPosition);
    if (this->_nextSprite == 1) {
        this->_nextSprite = 0;
    }
    else {
        this->_nextSprite = 1;
    }
}
