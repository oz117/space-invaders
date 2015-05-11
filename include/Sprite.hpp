/*
** file: [Sprite.hpp]
** Author: zero.
** Contact: <andre.paulos@epitech.eu> (github.com/oz117)
** Created on 2015-04-07 19:28
**
*/

#ifndef     SPRITE_HPP_
#define     SPRITE_HPP_

# include   <iostream>
# include   <string>
# include   <vector>
# include   "Typedefs.hpp"

namespace                   Sprites {
    enum                    Sprite {
        SHIP = 0,
        WALL,
        ADVERSARY_0,
        ADVERSARY_1,
        ADVERSARY_2
    };
}

class                       Sprite {
    private:
        Sprite(const Sprite& other);
        Sprite&             operator=(const Sprite& other);
    public:
        Sprite(void);
        ~Sprite(void);
        Sprite(const std::vector<pair2s>& sprites, const pair2i& size);
        void                        create(const std::vector<pair2s>& sprites, const pair2i& size, const std::string& nbOfSprite);
        const std::vector<pair2s>&  getSprites(void) const;
        const pair2s&               getIndex(int index) const;
        const std::string           getNameOfCurrentSprite(void) const;
        const std::string           getNameOfNextSprite(void) const;
        const std::string&          getPathNextSprite(void);
        void                        setNextSprite(const int newNextSprite);
        void                        setCurrentSprite(const int newCurrentSprite);
    protected:
        std::vector<pair2s>         _sprites;
        pair2i                      _size;
        std::string                 _nbOfSprite;
        int                         _currentSprite;
        int                         _nextSprite;
};

#endif      //!SPRITE_HPP_
