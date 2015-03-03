/*
** Created by André Paulos
** andre.paulos@epitech.eu
** Space Invaders game like
*/

#include "Ship.hpp"

Ship::Ship(void)
{
    this->_ship.setFillColor(sf::Color::Green);
    this->_ship.setSize(sf::Vector2<float>(LENGTH, HEIGHT));
    this->_ship.setPosition(240, Y_OFFSET);
    std::cout << "Ship created" << std::endl;
}

Ship::~Ship(void)
{
    std::cout << "Ship destroyed" << std::endl;
}

sf::RectangleShape&     Ship::getShape(void)
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
    else if (offsetX > (X_SIZE - LENGTH))
        this->_ship.setPosition((X_SIZE - LENGTH), Y_OFFSET);
    else
        this->_ship.setPosition(offsetX, Y_OFFSET);
}
