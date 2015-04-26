/*
** Created by André Paulos
** andre.paulos@epitech.eu
** Space Invaders game like
*/
#include "Wall.hpp"

Wall::Wall(const std::string& nameOfSprite, const std::string& nbOfSprite) {
    std::vector<pair2s> sprites;

    sprites.push_back(pair2s(nameOfSprite, PATH_WALL_SPRITE_100));
    this->_wall_sprite.create(sprites, pair2i(0, 0), nbOfSprite);
    this->_life = WALL_LIFE;
}

Wall::~Wall(void) {

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
