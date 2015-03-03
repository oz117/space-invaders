/*
** Created by André Paulos
** 4ndr3p4ul0s@gmail.com
** Space Invaders like game
*/

#ifndef     BULLET_HPP_
# define    BULLET_HPP_

# include   <iostream>
# include   <SFML/Graphics.hpp>
# include   "Properties.hpp"

class       Bullet {
    private:
        Bullet(const Bullet& other);
        Bullet& operator=(const Bullet& other);
    public:
        Bullet(void);
        ~Bullet(void);
        void                        update(void);
        void                        setPosition(const sf::Vector2f& pos);
        const sf::RectangleShape&   getShape(void);
        void                        setOnScreen(bool isOnScreen);
        bool                        getOnScreen(void);
    protected:
        bool                _onScreen;
        sf::RectangleShape  _shape;
};

#endif      // !BULLET_HPP_
