/*
** Created by André Paulos
** andre.paulos@epitech.eu
** Space Invaders game like
*/

#include "Bullet.hpp"

Bullet::Bullet(void)
{
    this->_bulletTexture.loadFromFile("./Sprite/Ship_Bullet.png");
    this->_sprite.setTexture(this->_bulletTexture);
    this->_sprite.setScale(1.5f, 1.5f);
    this->_onScreen = false;
}

Bullet::~Bullet(void)
{
}

const sf::Sprite&   Bullet::getShape(void) const
{
    return (this->_sprite);
}

void    Bullet::setPosition(const sf::Vector2f& pos)
{
    this->_sprite.setPosition((pos.x + ((SHIP_WIDTH - 8.0f)/ 2.0f)), (pos.y - SHIP_HEIGHT));
}

void    Bullet::update(void)
{
    if (this->_sprite.getPosition().y < -10.f) {
        this->_onScreen = false;
    }
    this->_sprite.setPosition(this->_sprite.getPosition().x, this->_sprite.getPosition().y - BULLET_SPEED);
}

void    Bullet::setOnScreen(bool isOnScreen)
{
    this->_onScreen = isOnScreen;
}

bool  Bullet::getOnScreen(void)
{
    return (this->_onScreen);
}
