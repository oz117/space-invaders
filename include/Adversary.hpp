/*
** File: [Adversary.hpp]
** Author: zero.
** Contact: <andre.paulos@epitech.eu> (github.com/oz117)
** Created on 2015-04-13 20:10
**
*/

#ifndef     ADVERSARY_HPP_
# define    ADVERSARY_HPP_

# include   <iostream>
# include   <utility>
# include   "Typedefs.hpp"
# include   "Properties.hpp"

class       Adversary {
    private:
        Adversary&  operator=(const Adversary& other);
        Adversary(const Adversary& other);
    public:
        Adversary(void);
        ~Adversary(void);
    public:
        const float&    getX(void) const;
        const pair2f&   getPosition(void) const;
        void            setPosition(const pair2f& newPosition);
        void            move(void);
        void            checkPosition(pair2f& newPosition);
        int             getSpriteNumber(void);
        void            setSpriteNumber(int spriteNumber);
        int             getNextSprite(void);
        void            setNextSprite(int nextSprite);
        int             getCurrentSprite(void);
        void            setCurrentSprite(int currentSprite);
    protected:
        pair2f          _pos;
        int             _spriteNumber;
        int             _nextSprite;
        int             _currentSprite;
};

#endif      /* !ADVERSARY_HPP_*/
