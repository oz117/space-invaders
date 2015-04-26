/*
** File: [Bullet.hpp]
** Author: zero.
** Contact: <andre.paulos@epitech.eu> (github.com/oz117)
** Created on 2015-04-13 20:10
**
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
        const sf::Sprite&           getShape(void) const;
        void                        setOnScreen(bool isOnScreen);
        bool                        getOnScreen(void);
    protected:
        bool                        _onScreen;
        sf::Sprite                  _sprite;
        sf::Texture                 _bulletTexture;
};

#endif      // !BULLET_HPP_
