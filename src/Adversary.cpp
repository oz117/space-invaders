/*
** Created by André Paulos
** 4ndr3p4ul0s@gmail.com
** Space Invaders like game
*/

#include "Adversary.hpp"

Adversary::Adversary(const std::pair<float, float>& pos, const sf::Color& color)
{
    this->_pos = pos;
    this->_shape.setSize(sf::Vector2f(ADVERSARY_LENGTH, ADVERSARY_HEIGHT));
    this->_shape.setFillColor(color);
    this->_shape.setPosition(pos.first, pos.second);
}

Adversary::~Adversary(void)
{
    std::cout << "Adversary down" << std::endl;
}

const std::pair<float, float>&  Adversary::getPos(void) const
{
    return (this->_pos);
}

const sf::RectangleShape&       Adversary::getShape(void) const
{
    return (this->_shape);
}

void                            Adversary::move(void)
{
    if ((this->_shape.getPosition().x + ADVERSARY_LENGTH) >= X_SIZE) {
        this->_shape.setPosition(0 + ADVERSARY_SPEED,this->_shape.getPosition().y + 20.f);
    }
    else {
        this->_shape.setPosition(this->_shape.getPosition().x + ADVERSARY_SPEED,this->_shape.getPosition().y);
    }
}
