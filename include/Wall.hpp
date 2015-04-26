/*
** Created by André Paulos
** andre.paulos@epitech.eu
** Space Invaders game like
*/

#ifndef     WALL_HPP_
# define    WALL_HPP_

# include   <utility>
# include   <SFML/Graphics.hpp>
# include   "Sprite.hpp"
# include   "Properties.hpp"

class       Wall {
    private:
        Wall&   operator=(const Wall& other);
        Wall(const Wall& other);
    public:
        Wall(const std::string& nameOfSprite, const std::string& nbOfSprite);
        ~Wall(void);
    public:
        int                         getLife(void) const;
        void                        setLife(const int life);
    protected:
        int                         _life;
        Sprite                      _wall_sprite;
};

#endif      /* !WALL_HPP_ */
