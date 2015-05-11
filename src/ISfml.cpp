/*
** File: [ISfml.cpp]
** Author: paulos_a.
** Contact: <andre.paulos@epitech.eu> (github.com/oz117)
** Created on 2015-05-07 22:24
**
*/

#include "ISfml.hpp"

ISfml::ISfml(void) {
    this->_window.create(sf::VideoMode(X_SIZE, Y_SIZE), "Space Invaders");
    this->_window.setVerticalSyncEnabled(true);
    this->_window.setKeyRepeatEnabled(true);
    this->_window.setPosition(sf::Vector2i(200,200));
}

ISfml::~ISfml(void) {
}

void                    ISfml::clear(void) {
    this->_window.clear();
}

void                    ISfml::display(void) {
    this->_window.display();
}

bool            ISfml::closeWindow(void) {
    this->_window.close();
    return (true);
}

Keys::Key       ISfml::handleInput(void) {
    sf::Event   event;

    if (this->_window.pollEvent(event)) {
        switch (event.type) {
            case sf::Event::Closed :
                return (Keys::Key::ESC);
                break;
            case sf::Event::KeyPressed:
                switch (event.key.code) {
                    case sf::Keyboard::Escape :
                        return (Keys::Key::ESC);
                        break ;
                    case sf::Keyboard::Right:
                        return (Keys::Key::RIGHT);
                        break ;
                    case sf::Keyboard::Left:
                        return (Keys::Key::LEFT);
                        break ;
                    default:
                        break ;
                    }
                break ;
            default:
                break ;
        }
    }
    return (Keys::Key::NONE);
}

void                ISfml::updatePosition(const Sprites::Sprite sprite, const pair2f& newPosition) {
    this->_loader.setPosition(sprite, newPosition);
}

/*
 *void                ISfml::updateSprite(const std::string& nameOfSprite, const std::string& pathToFile) {
 *    this->_loader.
 *}
 */

void                ISfml::draw(void) {
    std::vector<sf::Sprite>     sprites;

    sprites = this->_loader.getSprites();
    if (this->_window.isOpen()) {
        for (size_t i = 0; i < sprites.size(); ++i) {
            this->_window.draw(sprites[i]);
        }
    }
}
