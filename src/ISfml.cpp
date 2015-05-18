/*
** File: [ISfml.cpp]
** Author: paulos_a.
** Contact: <andre.paulos@epitech.eu> (github.com/oz117)
** Created on 2015-05-07 22:24
**
*/

#include "ISfml.hpp"

// { inits the size of the window, the title, etc...
ISfml::ISfml(void) {
    this->_window.create(sf::VideoMode(X_SIZE, Y_SIZE), "Space Invaders");
    this->_window.setVerticalSyncEnabled(true);
    this->_window.setKeyRepeatEnabled(true);
    this->_window.setPosition(sf::Vector2i(200,200));
}
// }

// { destructor
ISfml::~ISfml(void) {
}
// }

// { Clear function of sfml Graphics
void                    ISfml::clear(void) {
    this->_window.clear();
}
// }

// { Display function of sfml Graphics
void                    ISfml::display(void) {
    this->_window.display();
}
// }

// { Close function of sfml Graphics, closes the window.
bool            ISfml::closeWindow(void) {
    this->_window.close();
    return (true);
}
// }

// { Handles the input, return a value based on the key pressed
Keys::Key       ISfml::handleInput(void) {
    sf::Event   event;

    if (this->_window.pollEvent(event)) {
        switch (event.type) {
            case sf::Event::Closed :
                return (Keys::ESC);
                break;
            case sf::Event::KeyPressed:
                switch (event.key.code) {
                    case sf::Keyboard::Escape :
                        return (Keys::ESC);
                        break ;
                    case sf::Keyboard::Right:
                        return (Keys::RIGHT);
                        break ;
                    case sf::Keyboard::Left:
                        return (Keys::LEFT);
                        break ;
                    default:
                        break ;
                    }
                break ;
            default:
                break ;
        }
    }
    return (Keys::NONE);
}
// }

// { Calls a function in the SFMLLoader that will update the position of a sprite
void                ISfml::updatePosition(const int sprite, const pair2f& newPosition) {
    this->_loader.setPosition(sprite, newPosition);
}
// }

// { Draw all the sprites
void                ISfml::draw(void) {
    std::vector<sf::Sprite>     sprites;

    sprites = this->_loader.getSprites();
    if (this->_window.isOpen()) {
        for (size_t i = 0; i < sprites.size(); ++i) {
            this->_window.draw(sprites[i]);
        }
    }
}
//}
