/*
** Created by André Paulos
** 4ndr3p4ul0s@gmail.com
** Space Invaders like game
*/

#include <iostream>
#include "Game.hpp"

int         main(void)
{
    Game    game;

    game.init();
    game.run();
    return (EXIT_SUCCESS);
}
