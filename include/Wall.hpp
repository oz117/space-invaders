/*
** Created by André Paulos
** andre.paulos@epitech.eu
** Space Invaders game like
*/

#ifndef     WALL_HPP_
# define    WALL_HPP_

# include   <utility>
# include   <SFML/Graphics.hpp>
# include   "Properties.hpp"

class       Wall {
    private:
        Wall(void);
        Wall&   operator=(const Wall& other);
        Wall(const Wall& other);
    public:
        Wall(const std::pair<float, float>& pos);
        ~Wall(void);
    public:
        int                         getLife(void) const;
        const std::pair<float, float>&  getPos(void) const;
        void                        setLife(const int life);
        const sf::RectangleShape&   getWall(void) const;
    protected:
        int                         _life;
        std::pair<float, float>     _pos;
        sf::RectangleShape          _wall;
};

#endif      /* !WALL_HPP_ */
