#include "ISfml.hpp"

ISfml::ISfml(void) {
    this->_window.create(sf::VideoMode(X_SIZE, Y_SIZE), "Space Invaders");
    this->_window.setVerticalSyncEnabled(false);
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

void                ISfml::updatePosition(const std::string& nameOfSprite, const pair2f& newPosition) {
    sf::Vector2f    position;

    position.x = newPosition.first;
    position.y = newPosition.second;
    this->_loader.setPosition(nameOfSprite, position);
}

/*
 *void                ISfml::updateSprite(const std::string& nameOfSprite, const std::string& pathToFile) {
 *    this->_loader.
 *}
 */

void                ISfml::draw() {

    if (this->_window.isOpen()) {
        for (auto it = this->_loader.getSprites().begin(); it != this->_loader.getSprites().end(); ++it)
        {
            this->_window.draw(*((*it).second));
        }
    }
}
