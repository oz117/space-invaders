/*
** Created by André Paulos
** 4ndr3p4ul0s@gmail.com
** Space Invaders like game
*/

#ifndef     ADVERSARY_HPP_
# define    ADVERSARY_HPP_

# include   <iostream>
# include   <utility>
# include   <SFML/Graphics.hpp>
# include   "Properties.hpp"

class       Adversary {
    private:
        Adversary(void);
        Adversary&  operator=(const Adversary& other);
        Adversary(const Adversary& other);
    public:
        Adversary(const std::pair<float, float>& pos, const sf::Color& color);
        ~Adversary(void);
    public:
        const std::pair<float, float>&  getPos(void) const;
        const sf::RectangleShape&       getShape(void) const;
        bool    move(void);
    protected:
        std::pair<float, float>     _pos;
        sf::RectangleShape          _shape;
};

#endif      /* !ADVERSARY_HPP_*/
