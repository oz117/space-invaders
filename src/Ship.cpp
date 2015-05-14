/*
** Created by André Paulos
** andre.paulos@epitech.eu
** Space Invaders game like
*/

#include "Ship.hpp"

Ship::Ship(void) {
    this->_pos.first = (X_SIZE - (SHIP_WIDTH / 2)) / 2;
    this->_pos.second = SHIP_Y_OFFSET;
}

Ship::~Ship(void) {
    std::cout << "Ship destroyed" << std::endl;
}

int             Ship::getSpriteNumber(void) {
    return (this->_spriteNumber);
}

void            Ship::setSpriteNumber(int spriteNumber) {
    this->_spriteNumber = spriteNumber;
}

const float&    Ship::getX(void) const {
    return (this->_pos.first);
}

const pair2f&   Ship::getPosition(void) const {
    return (this->_pos);
}

void            Ship::setPosition(const pair2f& pos) {
    this->_pos = pos;
}

void            Ship::checkPosition(pair2f& newPosition) {
    if (newPosition.first < 0) {
        newPosition.first = 0;
    }
    else if (newPosition.first > (X_SIZE - SHIP_WIDTH)) {
        newPosition.first = X_SIZE - SHIP_WIDTH;
    }
}

void            Ship::move(Keys::Key key) {
    pair2f      newPosition;

    newPosition.second = SHIP_Y_OFFSET;
    newPosition.first = this->getX();
    if (key == Keys::RIGHT)
        newPosition.first += SHIP_SPEED;
    else if (key == Keys::LEFT)
        newPosition.first -= SHIP_SPEED;
    this->checkPosition(newPosition);
    this->setPosition(newPosition);
}
