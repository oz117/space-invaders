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
# include   <string.h>
# include   "Typedefs.hpp"
# include   "Sprite.hpp"

class       SFMLLoader {
    private:
        SFMLLoader(const SFMLLoader& other);
        SFMLLoader& operator=(const SFMLLoader& other);
    public:
        SFMLLoader(void);
        ~SFMLLoader(void);
        void                                    load(const std::string& nameOfSprite, const std::string& pathToFile,
                                                            const pair2f& pos);
        sf::Sprite*                             findSprite(const std::string& name);
        void                                    setPosition(const std::string& nameOfSprite, const sf::Vector2f& newPos);
        bool                                    updateSprite(const std::string& nameOfSprite, const std::string& pathToFile);
        std::map<std::string, sf::Sprite*>&     getSprites(void);
    protected:
        std::map<std::string, sf::Sprite*>      _sprites;
        std::map<std::string, sf::Texture*>     _textures;
};

#endif      // !SFMLLOADER_HPP_
