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
    std::cout << "End of the game" << std::endl;
}

bool    Game::init(void)
{
    this->_window = new sf::RenderWindow(sf::VideoMode(X_SIZE, Y_SIZE), "Space Invaders");
    this->_window->setVerticalSyncEnabled(true);
    return (true);
}

bool    Game::run(void)
{
    sf::Event   event;
    sf::Clock   clock;
    sf::Time    elapsed;
    Ship        ship;

    while (this->_window->isOpen())
    {
        while (this->_window->pollEvent(event))
        {
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
                            ship.setX(ship.getX() + 10.f);
                            break ;
                        case sf::Keyboard::Left:
                            ship.setX(ship.getX() - 10.f);
                            break ;
                        default:
                            break ;
                    }
                default:
                    break;
            }
        }
        elapsed = clock.getElapsedTime();
        if (FQ <= elapsed.asMilliseconds())
        {
            this->_window->clear();
            this->_window->draw(ship.getShape());
            this->_window->display();
            clock.restart();
        }
    }
    return (false);
}
