/*
** Created by André Paulos
** paulos_a@epitech.eu
** A space invader like game
*/

#include "Menu.hpp"
#include "screen_1.hpp"
int			main(void)
{
  sf::RenderWindow	app(sf::VideoMode(WINDOW_WIDTH, WINDOW_HEIGHT, 32), "Space Invader");
  std::vector<AScreen*> screens;
  Menu			menu;
  Screen_1		game;
  int			running;

  running = 0;
  app.setMouseCursorVisible(false);
  app.setVerticalSyncEnabled(true);
  screens.push_back(&menu);
  screens.push_back(&game);
  while (running >= 0)
    running = screens[running]->run(app);
  return (EXIT_SUCCESS);
}
