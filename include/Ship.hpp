/*
** Created by André Paulos
** andre.paulos@epitech.eu
** Space Invaders game like
*/

#ifndef     SHIP_HPP_
# define    SHIP_HPP_

# include   <iostream>
# include   <SFML/Graphics.hpp>

class   Ship {
    private:
        Ship(const Ship& other);
        Ship& operator=(const Ship& other);
    public:
        Ship(void);
        ~Ship(void);
    public:
        sf::RectangleShape&     getShape(void);
    protected:
        sf::RectangleShape  _ship;
};

#endif      /* !SHIP_HPP_*/
