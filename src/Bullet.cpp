/*
** Created by André Paulos
** andre.paulos@epitech.eu
** Space Invaders game like
*/

#include "Bullet.hpp"

Bullet::Bullet(void) {
    this->_shape.setFillColor(sf::Color::Green);
    this->_shape.setSize(sf::Vector2f(10.f, 10.f));
    this->_onScreen = false;
}

Bullet::~Bullet(void)
{
    std::cout << "Bullet destroyed" << std::endl;
}

const sf::RectangleShape&   Bullet::getShape(void)
{
    return (this->_shape);
}

void    Bullet::setPosition(const sf::Vector2f& pos)
{
    this->_shape.setPosition((pos.x + LENGTH / 2), pos.y - 5);
}

void    Bullet::update(void)
{
    if (this->_shape.getPosition().y < -10.f) {
        this->_onScreen = false;
    }
    this->_shape.setPosition(this->_shape.getPosition().x, this->_shape.getPosition().y - 3);
}

void    Bullet::setOnScreen(bool isOnScreen) {
    this->_onScreen = isOnScreen;
}

bool  Bullet::getOnScreen(void)
{
    return (this->_onScreen);
}
