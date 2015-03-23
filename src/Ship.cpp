/*
** Created by André Paulos
** andre.paulos@epitech.eu
** Space Invaders game like
*/

#include "Ship.hpp"

Ship::Ship(void)
{
    this->_ship.setPosition(240, Y_OFFSET);
    this->_shipTexture.loadFromFile("./Sprite/Ship.png");
    this->_shipTexture.setSmooth(true);
    this->_ship.setTexture(this->_shipTexture);
    this->_ship.setScale(X_SCALE_FACTOR, Y_SCALE_FACTOR);
}

Ship::~Ship(void)
{
    std::cout << "Ship destroyed" << std::endl;
}

sf::Sprite&     Ship::getSprite(void)
{
    return (this->_ship);
}

const float&            Ship::getX(void)
{
    return (this->_ship.getPosition().x);
}

const sf::Vector2f&     Ship::getPosition(void)
{
    return (this->_ship.getPosition());
}

void                    Ship::setX(const float& offsetX)
{
    if (offsetX < 0)
        this->_ship.setPosition(0, Y_OFFSET);
    else if (offsetX > (X_SIZE - SHIP_WIDTH))
        this->_ship.setPosition((X_SIZE - SHIP_WIDTH), Y_OFFSET);
    else
        this->_ship.setPosition(offsetX, Y_OFFSET);
}
