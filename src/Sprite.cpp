//
// Sprite.cpp for Space Invaders in /home/zero/dev/space-invaders/src
//
// Made by André Paulos
// <paulos_a@epitech.net>
//
// Started on  Tue Mar 24 17:53:32 2015 André Paulos
// Last update Tue Mar 24 17:53:37 2015 André Paulos
//

#include "Sprite.hpp"

Sprite::Sprite(const std::string& file, const std::pair<int, int>& size) {
    this->_file = file;
    this->_size = size;
}

const std::string&  Sprite::getFile(void) const {
    return (this->_file);
}
