/*
** File: [SFMLLoader.cpp]
** Author: zero.
** Contact: <andre.paulos@epitech.eu> (github.com/oz117)
** Created on 2015-04-09 23:48
**
*/

#include "SFMLLoader.hpp"

/*{  Default constructor; inits the vectors of texture and sprites (size) */
SFMLLoader::SFMLLoader(void) : _textures(TEXTURE_COUNT), _sprites(SPRITE_COUNT), _spriteCount(0) {
}

SFMLLoader::~SFMLLoader(void) {
}
/*}*/

/*{ Create Texture sets all the texture that will be used in the game */
bool    SFMLLoader::createTextures(void) {
    if (!this->_textures[Sprites::SHIP].loadFromFile(PATH_SHIP_SPRITE)) {
        std::cerr << PATH_SHIP_SPRITE << " is nowhere to be found" << std::endl;
        return (false);
    }
    if (!this->_textures[Sprites::WALL].loadFromFile(PATH_WALL_SPRITE)) {
        std::cerr << PATH_WALL_SPRITE << " is nowhere to be found" << std::endl;
        return (false);
    }
    if (!this->_textures[Sprites::ADVERSARY_0].loadFromFile(PATH_ADVERSARY_SPRITE_0)) {
        std::cerr << PATH_ADVERSARY_SPRITE_0 << " is nowhere to be found" << std::endl;
        return (false);
    }
    if (!this->_textures[Sprites::ADVERSARY_1].loadFromFile(PATH_ADVERSARY_SPRITE_1)) {
        std::cerr << PATH_ADVERSARY_SPRITE_1 << " is nowhere to be found" << std::endl;
        return (false);
    }
    if (!this->_textures[Sprites::ADVERSARY_2].loadFromFile(PATH_ADVERSARY_SPRITE_2)) {
        std::cerr << PATH_ADVERSARY_SPRITE_2 << " is nowhere to be found" << std::endl;
        return (false);
    }
    return (true);
}
/*}*/

void            SFMLLoader::load(const Sprites::Sprite& sprite, const pair2f& rect,
        const pair2f& spritePosition) {
    sf::IntRect rectangle(0, 0, rect.first, rect.second);

    this->_sprites[_spriteCount].setTexture((this->_textures[sprite]));
    this->_sprites[_spriteCount].setTextureRect(rectangle);
    this->_sprites[_spriteCount].setPosition(spritePosition.first, spritePosition.second);
    ++_spriteCount;
}

const std::vector<sf::Sprite>&  SFMLLoader::getSprites(void) {
    return (this->_sprites);
}

bool            SFMLLoader::setPosition(const Sprites::Sprite sprite, const pair2f& newPosition) {
    if (sprite > this->_sprites.size()) {
        return (false);
    }
    this->_sprites[sprite].setPosition(newPosition.first, newPosition.second);
    return (true);
}

bool            SFMLLoader::updateSprite(const pair2f& pos) {
(void) pos;
    /*
 *    sf::Texture *texture;
 *    sf::Sprite  *sprite;
 *
 *    sprite = NULL;
 *    texture = NULL;
 *    sprite = this->_sprites.find(nameOfSprite)->second;
 *    texture = this->_textures.find(nameOfSprite)->second;
 *    if (!sprite || !texture) {
 *        std::cerr << "No sprite found" << std::endl;
 *        return (false);
 *    }
 *    texture->loadFromFile(pathToFile);
 *    texture->setSmooth(true);
 *    sprite->setTexture(*texture);
 */
    return (true);
}
