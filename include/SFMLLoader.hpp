#ifndef     SFMLLOADER_HPP_
# define    SFMLLOADER_HPP_

# include   <SFML/Graphics.hpp>
# include   "Sprite.hpp"

class       SFMLLoader {
    private:
        SFMLLoader(const SFMLLoader& other);
        SFMLLoader& operator=(const SFMLLoader& other);
    public:
        SFMLLoader(void);
        sf::Sprite& load(const Sprite& sprite);
};

#endif      // !SFMLLOADER_HPP_
