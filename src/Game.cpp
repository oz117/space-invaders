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
    for (auto it = this->_adversaries.begin(); it != this->_adversaries.end(); ++it) {
        delete (*it);
    }

    std::cout << "End of the game" << std::endl;
}


bool        Game::init(void)
{
    float   pos;
    float   y_offset;
    int     dice_roll;
    sf::Color   color;
    std::default_random_engine  generator;
    std::uniform_int_distribution<int>  distribution(0, 6);

    pos = 0;
    this->_window = new sf::RenderWindow(sf::VideoMode(X_SIZE, Y_SIZE), "Space Invaders");
    this->_window->setVerticalSyncEnabled(true);
    for (int i = 0; i < 5; ++i) {
        pos = ((X_SIZE / 6) * (i + 1)) - (WALL_LENGTH / 2);
        this->_walls.push_back(new Wall(std::pair<float, float>(pos, WALL_Y_OFFSET)));
    }
    for (int j = 0; j < 5; ++j) {
        y_offset = ADVERSARY_Y_OFFSET + (j * 50.f);
         for (int i = 0; i < 8; ++i) {
            dice_roll = distribution(generator);
            std::cout << dice_roll << std::endl;
            color = what_color[dice_roll];
            pos = ((X_SIZE / 9) * i ) + (j * 10.f);
            this->_adversaries.push_back(new Adversary(std::pair<float, float>(pos, y_offset), color));
        }
    }
    return (true);
}

bool    Game::run(void)
{
    sf::Event   event;
    sf::Clock   clock;
    sf::Time    elapsed;
    Ship        ship;
    int         pause;

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
                        case sf::Keyboard::Space:
                            std::cin >> pause;
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
                (*it)->move();
                this->_window->draw((*it)->getShape());
            }

            this->_window->display();
            clock.restart();
        }
    }
    return (false);
}
