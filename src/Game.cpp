/*
** File: [Game.cpp]
** Author: zero.
** Contact: <andre.paulos@epitech.eu> (github.com/oz117)
** Created on 2015-04-09 23:37
**
*/

#include "Game.hpp"

/*{ Default constructor and destructor */
Game::Game(void) {
    std::cout << "Game started" << std::endl;
}

Game::~Game(void) {
    delete this->_window;
    std::cout << "End of the game" << std::endl;
}
/*}*/

bool                    Game::init(void) {
    float               pos;

    pos = 0;
    this->_window = new ISfml();
    if (!(dynamic_cast<ISfml*>(this->_window)->_loader.createTextures()))
        return (false);
    dynamic_cast<ISfml*>(this->_window)->_loader.load(Sprites::SHIP, pair2f(26, 16), this->_ship.getPosition());
    for (int i = 0; i < WALL_COUNT; ++i) {
        pos = ((X_SIZE / (WALL_COUNT + 1)) * (i + 1)) - (WALL_LENGTH / 2);
        dynamic_cast<ISfml*>(this->_window)->_loader.load(Sprites::WALL, pair2f(44, 32), pair2f(pos, WALL_Y_OFFSET));
    }
    return (true);
}

void    Game::updatePosition() {
    /*
     *for (auto it = this->_adversaries.begin(); it != this->_adversaries.end(); ++it) {
     *    this->_window->updatePosition((*it)->getSprite().getNameOfCurrentSprite(), (*it)->getPosition());
     *}*/
    this->_window->updatePosition(Sprites::SHIP, this->_ship.getPosition());
}

void    Game::updateAnimation(void) {
    /*
     *for (auto it = this->_adversaries.begin(); it != this->_adversaries.end(); ++it) {
     *    (*it)->move();
     *    dynamic_cast<ISfml*>(this->_window)->_loader.updateSprite((*it)->getSprite().getNameOfCurrentSprite(), (*it)->getSprite().getPathNextSprite());
     *}
     */
}

bool            Game::run(void) {
    bool        isOpen;
    Keys::Key   key;
    IClock*     gameClock;
    IClock*     animationClock;

    gameClock = new ISfmlClock();
    animationClock = new ISfmlClock();
    gameClock->start();
    animationClock->start();
    isOpen = true;
    while (isOpen) {
        key = this->_window->handleInput();
        if (key == Keys::ESC) {
                delete gameClock;
                delete animationClock;
                return (this->_window->closeWindow());
        }
        this->_ship.move(key);
        if (animationClock->getElapsedTimeAsSeconds() >= 1) {
            //this->updateAnimation();
            animationClock->restart();
        }
        if (FQ <= gameClock->getElapsedTimeAsMilliseconds()) {
            this->updatePosition();
            this->_window->clear();
            this->_window->draw();
            this->_window->display();
            gameClock->restart();
        }
    }
    delete gameClock;
    delete animationClock;
    return (true);
}
