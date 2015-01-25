/*
** Created by André Paulos
** 4ndr3p4ul0s@gmail.com
** Space Invaders like game
*/

#ifndef     COMPONENTS_HPP_
# define    COMPONENTS_HPP_

#include <SFML/Graphics.hpp>

struct Position {
    sf::Vector2f    _vec;
    Position(sf::Vector2f vec) : _vec(vec)
    { }
};

#endif      /* COMPONENTS_HPP_ */
