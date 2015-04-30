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
    bool                    run(void);
    void                    updatePosition(void);
    void                    updateAnimation(void);
 protected:
    IRenderer               *_window;
    Ship                    _ship;
    std::vector<Wall*>      _walls;
    //std::vector<std::vector<Adversary*>>    _adversaries;
    std::vector<Adversary*> _adversaries;
};

#endif      /* !GAME_HPP_ */
