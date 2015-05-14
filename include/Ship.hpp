/*
** File: [Ship.hpp]
** Author: zero.
** Contact: <andre.paulos@epitech.eu> (github.com/oz117)
** Created on 2015-04-13 20:11
**
*/

#ifndef     SHIP_HPP_
# define    SHIP_HPP_

# include   <iostream>
# include   "Sprite.hpp"
# include   "Properties.hpp"
# include   "IRenderer.hpp"
# include   "Typedefs.hpp"

class                   Ship {
    private:
        Ship(const Ship& other);
        Ship& operator=(const Ship& other);
    public:
        Ship(void);
        ~Ship(void);
    public:
        int             getSpriteNumber(void);
        void            setSpriteNumber(int spriteNumber);
        const float&    getX(void) const;
        const pair2f&   getPosition(void) const;
        void            setPosition(const pair2f& pos);
        void            checkPosition(pair2f& newPosition);
        void            move(Keys::Key direction);
    protected:
        pair2f          _pos;
        int             _spriteNumber;
};

#endif      /* !SHIP_HPP_*/
