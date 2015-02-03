#include "Wall.hpp"

Wall::Wall(const std::pair<float, float>& pos)
{
    this->_pos = pos;
    this->_life = WALL_LIFE;
    this->_wall.setSize(sf::Vector2<float>(WALL_LENGHT, WALL_HEIGHT));
    this->_wall.setFillColor(sf::Color::Red);
    this->_wall.setPosition(sf::Vector2<float>(pos.first, pos.second));
}

Wall::~Wall(void)
{

}

int     Wall::getLife(void) const
{
    return (this->_life);
}

const std::pair<int, int>&  Wall::getPos(void) const
{
    return (this->_pos);
}

void    Wall::setLife(const int life)
{
    if (this->_life - life < 0) {
        this->_life = 0;
    }
    else {
        this->_life -= life;
    }
}

const sf::RectangleShape&   Wall::getWall(void) const
{
    return (this->_wall);
}
