/*
** File: [SFMLLoader.hpp]
** Author: zero.
** Contact: <andre.paulos@epitech.eu> (github.com/oz117)
** Created on 2015-04-03 17:45
**
*/

#ifndef     SFMLLOADER_HPP_
# define    SFMLLOADER_HPP_

# include   <SFML/Graphics.hpp>
# include   <iostream>
# include   <string.h>
# include   "Properties.hpp"
# include   "Typedefs.hpp"
# include   "Sprite.hpp"

class       SFMLLoader {
    private:
        SFMLLoader(const SFMLLoader& other);
        SFMLLoader& operator=(const SFMLLoader& other);
    public:
        SFMLLoader(void);
        ~SFMLLoader(void);
        bool                                    createTextures(void);
        void                                    load(const Sprites::Sprite& sprite,
                const float *rect, const pair2f& spritePosition);
        bool                                    setPosition(const int sprite,
                const pair2f& newPosition);
        bool                                    updateSprite(int spriteNumber,
                const float *rect);
        const std::vector<sf::Sprite>&          getSprites(void);
        int                                     getSpriteCount(void);
    protected:
        std::vector<sf::Texture>                _textures;
        std::vector<sf::Sprite>                 _sprites;
        int                                     _spriteCount;
};

#endif      // !SFMLLOADER_HPP_
