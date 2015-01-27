/*
** Created by André Paulos
** andre.paulos@epitech.eu
** Space Invaders game like
*/

#ifndef     GAME_HPP_
# define    GAME_HPP_

# include   <iostream>
# include   <cstdlib>
# include   <SFML/Graphics.hpp>
# include   "Ship.hpp"

class   Game{
 private:
    Game(const Game& other);
    Game& operator=(const Game& other);
 public:
    Game(void);
    ~Game(void);
 public:
    bool    init(void);
    bool    run(void);
 protected:
    sf::RenderWindow    *_window;
};

#endif      /* !GAME_HPP_ */
