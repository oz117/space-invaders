#include "Wall.hpp"

Wall::Wall(const std::pair<float, float>& pos)
{
    this->_wallTexture.loadFromFile("./Sprite/Wall.png");
    this->_wall.setScale(1.5f, 1.5f);
    this->_wall.setTexture(this->_wallTexture);
    this->_pos = pos;
    this->_life = WALL_LIFE;
    this->_wall.setPosition(sf::Vector2<float>(pos.first, pos.second));
}

Wall::~Wall(void)
{

}

int     Wall::getLife(void) const
{
    return (this->_life);
}

const std::pair<float, float>&  Wall::getPos(void) const
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

const sf::Sprite&   Wall::getWall(void) const
{
    return (this->_wall);
}
