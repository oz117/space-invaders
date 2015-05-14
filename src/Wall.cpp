/*
** Created by André Paulos
** andre.paulos@epitech.eu
** Space Invaders game like
*/
#include "Wall.hpp"

Wall::Wall(void) {
    this->_life = WALL_LIFE;
}

Wall::~Wall(void) {

}

int             Wall::getSpriteNumber(void) {
    return (this->_spriteNumber);
}

void            Wall::setSpriteNumber(int spriteNumber) {
    this->_spriteNumber = spriteNumber;
}

int     Wall::getLife(void) const {
    return (this->_life);
}

void    Wall::setLife(const int life) {
    if (this->_life - life < 0) {
        this->_life = 0;
    }
    else {
        this->_life -= life;
    }
}
