/*
** File: [Game.cpp]
** Author: zero.
** Contact: <andre.paulos@epitech.eu> (github.com/oz117)
** Created on 2015-04-09 23:37
**
*/

#include "Game.hpp"

Game::Game(void) {
    std::cout << "Game started" << std::endl;
}

    Game::~Game(void) {
    std::cout << "End of the game" << std::endl;
}

bool                    Game::init(void) {
    float               pos;
    std::stringstream   ss;
    float               y_offset;

    this->_window = new ISfml();
    dynamic_cast<ISfml*>(this->_window)->_loader.load("Ship", PATH_SHIP_SPRITE_100, this->_ship.getPosition());
    ss.clear();
    for (int i = 0; i < 5; ++i) {
        ss.str("");
        ss.clear();
        ss << i;
        pos = ((X_SIZE / 6) * (i + 1)) - (WALL_LENGTH / 2);
        this->_walls.push_back(new Wall("Wall", ss.str()));
        dynamic_cast<ISfml*>(this->_window)->_loader.load("Wall" + ss.str(), PATH_WALL_SPRITE_100, pair2f(pos, WALL_Y_OFFSET));
    }
    for (size_t j = 0; j < PATH_ADVERSARY_SPRITES.size(); ++j) {
        y_offset = ADVERSARY_Y_OFFSET + (j * 50.f);
        for (int i = 0; i < ADVERSARY_PER_LINE; ++i) {
            ss.str("");
            ss.clear();
            ss << i;
            pos = ((X_SIZE / 12) * i);
            this->_adversaries.push_back(new Adversary(PATH_ADVERSARY_SPRITES[j], pair2f(pos, y_offset), ss.str()));
            dynamic_cast<ISfml*>(this->_window)->_loader.load(PATH_ADVERSARY_SPRITES[j][0].first + ss.str(), PATH_ADVERSARY_SPRITES[j][0].second, pair2f(pos, y_offset));
        }
    }
    return (true);
}

/*
 *void    Game::collision(Bullet& current_bullet) {
 *    (void) current_bullet;
 *    sf::FloatRect boundingBox = current_bullet.getShape().getGlobalBounds();
 *
 *    for (auto it = this->_adversaries.begin(); it != this->_adversaries.end(); ++it) {
 *        if (boundingBox.intersects((*it)->getShape().getGlobalBounds())) {
 *            current_bullet.setOnScreen(false);
 *            this->_adversaries.erase(it);
 *            return ;
 *        }
 *    }
 *}
 */

void    Game::updatePosition(Keys::Key key) {
    this->_ship.move(key);
    for (auto it = this->_adversaries.begin(); it != this->_adversaries.end(); ++it) {
        (*it)->move();
        dynamic_cast<ISfml*>(this->_window)->_loader.updateSprite((*it)->getSprite().getNameOfCurrentSprite(), (*it)->getSprite().getPathNextSprite());
        this->_window->updatePosition((*it)->getSprite().getNameOfCurrentSprite(), (*it)->getPosition());
    }
    this->_window->updatePosition("Ship", this->_ship.getPosition());
}

bool            Game::run(void) {
    bool        isOpen;
    Keys::Key   key;

    isOpen = true;
    while (isOpen) {
        key = this->_window->handleInput();
        if (key == Keys::Key::ESC)
            return (this->_window->closeWindow());
        this->updatePosition(key);
        this->_window->clear();
        this->_window->draw();
        this->_window->display();
    }
    return (true);
}
