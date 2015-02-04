/*
** Created by André Paulos
** andre.paulos@epitech.eu
** Space Invaders game like
*/

#include "Game.hpp"

Game::Game(void)
{
    std::cout << "Game started" << std::endl;
}

Game::~Game(void)
{
    delete this->_window;
    for (auto it = this->_walls.begin(); it != this->_walls.end(); ++it) {
        delete (*it);
    }
    std::cout << "End of the game" << std::endl;
}

bool        Game::init(void)
{
    float   pos;

    pos = 0;
    this->_window = new sf::RenderWindow(sf::VideoMode(X_SIZE, Y_SIZE), "Space Invaders");
    this->_window->setVerticalSyncEnabled(true);
    for (int i = 0; i < 5; ++i) {
        pos = ((X_SIZE / 6) * (i + 1)) - (WALL_LENGTH / 2);
        this->_walls.push_back(new Wall(std::pair<float, float>(pos, WALL_Y_OFFSET)));
    }
    for (int i = 0; i < 8; ++i) {
        pos = ((X_SIZE / 8) * i);
        this->_adversaries.push_back(new Adversary(std::pair<float, float>(pos, ADVERSARY_Y_OFFSET), sf::Color::White));
    }
    return (true);
}

bool    Game::run(void)
{
    sf::Event   event;
    sf::Clock   clock;
    sf::Time    elapsed;
    Ship        ship;

    while (this->_window->isOpen()) {
        while (this->_window->pollEvent(event)) {
            switch (event.type) {
                case sf::Event::Closed :
                    this->_window->close();
                    break;
                case sf::Event::KeyPressed:
                    switch (event.key.code) {
                        case sf::Keyboard::Escape :
                            this->_window->close();
                            break ;
                        case sf::Keyboard::Right:
                            ship.setX(ship.getX() + SHIP_SPEED);
                            break ;
                        case sf::Keyboard::Left:
                            ship.setX(ship.getX() - SHIP_SPEED);
                            break ;
                        default:
                            break ;
                    }
                default:
                    break;
            }
        }
        elapsed = clock.getElapsedTime();
        if (FQ <= elapsed.asMilliseconds()) {
            this->_window->clear();
            this->_window->draw(ship.getShape());
            for (auto it = this->_walls.begin(); it != this->_walls.end(); ++it) {
                this->_window->draw((*it)->getWall());
            }
            for (auto it = this->_adversaries.begin(); it != this->_adversaries.end(); ++it) {
                this->_window->draw((*it)->getShape());
            }
            this->_window->display();
            clock.restart();
        }
    }
    return (false);
}
