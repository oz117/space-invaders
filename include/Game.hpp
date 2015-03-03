/*
** Created by André Paulos
** andre.paulos@epitech.eu
** Space Invaders game like
*/

#ifndef     GAME_HPP_
# define    GAME_HPP_

# include   <iostream>
# include   <random>
# include   <cstdlib>
# include   <SFML/Graphics.hpp>
# include   "Ship.hpp"
# include   "Wall.hpp"
# include   "Adversary.hpp"
# include   "Bullet.hpp"

const sf::Color what_color[] = {
    sf::Color::White,
    sf::Color::Red,
    sf::Color::Green,
    sf::Color::Blue,
    sf::Color::Yellow,
    sf::Color::Magenta,
    sf::Color::Cyan
};

class   Game {
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
    sf::RenderWindow        *_window;
    std::vector<Wall*>      _walls;
    std::vector<Adversary*> _adversaries;
    Bullet                  _bullets[MAXBULLETS];
};

#endif      /* !GAME_HPP_ */
