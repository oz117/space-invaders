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
# include   "Sprite.hpp"

class       Adversary {
    private:
        Adversary(void);
        Adversary&  operator=(const Adversary& other);
        Adversary(const Adversary& other);
    public:
        Adversary(const std::vector<pair2s>& sprites, const pair2f& pos, const std::string& nbOfSprite);
        ~Adversary(void);
    public:
        const float&    getX(void) const;
        const pair2f&   getPosition(void) const;
        void            setPosition(const pair2f& newPosition);
        void            move(void);
        Sprite&         getSprite(void);
        void            checkPosition(pair2f& newPosition);
    protected:
        Sprite          _adversary_sprite;
        pair2f          _pos;
};

#endif      /* !ADVERSARY_HPP_*/
