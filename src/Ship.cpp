/*
** Created by André Paulos
** andre.paulos@epitech.eu
** Space Invaders game like
*/

#include "Ship.hpp"

Ship::Ship(void)
{
    this->_ship.setFillColor(sf::Color(255, 255, 255, 150));
    this->_ship.setSize(sf::Vector2<float>(10.f, 10.f));
    this->_ship.setPosition(240, 320);
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
