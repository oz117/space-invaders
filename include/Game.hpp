/*
** File: [Game.hpp]
** Author: zero.
** Contact: <andre.paulos@epitech.eu> (github.com/oz117)
** Created on 2015-04-09 23:38
**
*/

#ifndef     GAME_HPP_
# define    GAME_HPP_

# include   <iostream>
# include   <sstream>
# include   "ISfml.hpp"
# include   "Ship.hpp"
# include   "Wall.hpp"
# include   "ISfmlClock.hpp"
# include   "Adversary.hpp"
# include   "Bullet.hpp"
# include   "Sprite.hpp"
# include   "Typedefs.hpp"

class   Game {
 private:
    Game(const Game& other);
    Game& operator=(const Game& other);
 public:
    Game(void);
    ~Game(void);
 public:
    bool                    init(void);
    void                    initAdversaries(int cpt, float y_offset,
            Sprites::Sprite sprite, const float *rect);
    bool                    run(void);
    void                    updatePosition(void);
    void                    updateAnimation(void);
    void                    updateAdversarySprite(int cpt, const float rect[3][4]);
 protected:
    IRenderer               *_window;
    Ship                    _ship;
    Wall                    _walls[WALL_COUNT];
    Adversary               _adversaries[5][11];
};

#endif      /* !GAME_HPP_ */
