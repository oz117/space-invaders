/*
** File: [Game.cpp]
** Author: zero.
** Contact: <andre.paulos@epitech.eu> (github.com/oz117)
** Created on 2015-04-09 23:37
**
*/

#include "Game.hpp"

//{ Default constructor and destructor
Game::Game(void) {
    std::cout << "Game started" << std::endl;
}

Game::~Game(void) {
    delete this->_window;
    std::cout << "End of the game" << std::endl;
}
//}

// { Sets the sprites of the game and their positions
bool                    Game::init(void) {
    float               pos;
    float               y_offset;

    pos = 0;
    this->_window = new ISfml();
    if (!(dynamic_cast<ISfml*>(this->_window)->_loader.createTextures()))
        return (false);
    this->_ship.setSpriteNumber(dynamic_cast<ISfml*>(this->_window)->_loader.getSpriteCount());
    dynamic_cast<ISfml*>(this->_window)->_loader.load(Sprites::SHIP, SHIPSPRITES[0], this->_ship.getPosition());
    for (int i = 0; i < WALL_COUNT; ++i) {
        pos = ((X_SIZE / (WALL_COUNT + 1)) * (i + 1)) - (WALL_LENGTH / 2);
        this->_walls[i].setSpriteNumber(dynamic_cast<ISfml*>(this->_window)->_loader.getSpriteCount());
        dynamic_cast<ISfml*>(this->_window)->_loader.load(Sprites::WALL, WALL_SPRITES[0], pair2f(pos, WALL_Y_OFFSET));
    }
    y_offset = ADVERSARY_Y_OFFSET + (0 * 50.f);
    initAdversaries(0, y_offset, Sprites::ADVERSARY_0, ADVERSARY_SPRITES_0[0]);
    y_offset = ADVERSARY_Y_OFFSET + (1 * 50.f);
    initAdversaries(1, y_offset, Sprites::ADVERSARY_1, ADVERSARY_SPRITES_1[0]);
    y_offset = ADVERSARY_Y_OFFSET + (2 * 50.f);
    initAdversaries(2, y_offset, Sprites::ADVERSARY_1, ADVERSARY_SPRITES_1[0]);
    y_offset = ADVERSARY_Y_OFFSET + (3 * 50.f);
    initAdversaries(3, y_offset, Sprites::ADVERSARY_2, ADVERSARY_SPRITES_2[0]);
    y_offset = ADVERSARY_Y_OFFSET + (4 * 50.f);
    initAdversaries(4, y_offset, Sprites::ADVERSARY_2, ADVERSARY_SPRITES_2[0]);
    return (true);
}

void        Game::initAdversaries(int cpt, float y_offset,
        Sprites::Sprite sprite, const float *rect) {
    float   pos;

    pos = 0;
    for (int j = 0; j < ADVERSARY_PER_LINE; ++j) {
        pos = ((X_SIZE / (ADVERSARY_PER_LINE + 1)) * j);
        this->_adversaries[cpt][j].setSpriteNumber(dynamic_cast<ISfml*>(this->_window)->_loader.getSpriteCount());
        this->_adversaries[cpt][j].setPosition(pair2f(pos, y_offset));
        dynamic_cast<ISfml*>(this->_window)->_loader.load(sprite, rect, this->_adversaries[cpt][j].getPosition());
    }
}
//}

// { Updates the position of every sprite
void    Game::updatePosition() {
    for (int j = 0; j < ADVERSARY_ROW_COUNT; ++j) {
        for (int i = 0; i < ADVERSARY_PER_LINE; ++i) {
            this->_window->updatePosition(this->_adversaries[j][i].getSpriteNumber(), this->_adversaries[j][i].getPosition());
        }
        this->_window->updatePosition(Sprites::SHIP, this->_ship.getPosition());
    }
}
// }

// { changes the sprite of the adversary
void    Game::updateAnimation(void) {
    for (int i = 0; i < ADVERSARY_ROW_COUNT; ++i) {
        this->updateAdversarySprite(i, ADVERSARY_SPRITES[i]);
    }
}

void            Game::updateAdversarySprite(int cpt, const float rect[3][4]) {
    for (int i = 0; i < ADVERSARY_PER_LINE; ++i) {
        this->_adversaries[cpt][i].move();
        dynamic_cast<ISfml*>(this->_window)->_loader.updateSprite(this->_adversaries[cpt][i].getSpriteNumber(),
                rect[this->_adversaries[cpt][i].getNextSprite()]);
    }
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
            this->updateAnimation();
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
