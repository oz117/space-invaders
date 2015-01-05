/*
** Created by André Paulos
** paulos_a@epitech.eu
** source code: Menu for a space invader like game
*/

#include "Menu.hpp"

Menu::Menu(void)
{
  std::cout << "Creating menu" << std::endl;
  sf::FloatRect   rect;
  int             pos;
  int             cpt;

  pos = 75;
  cpt = -1;
  this->_menuPos = 0;
  //Todo load a Sprite or a shadow copy of the game
  // if (!this->_texture.loadFromFile("./sprites/r-type_level1.gif"))
  //   std::cerr << "Error could not load r-type level 1" << std::endl
  // this->_background.setTexture(this->_texture);
  this->_texture.setSmooth(true);
  this->_texture.setRepeated(true);
  if (!this->_font.loadFromFile("./fonts/Bradley Hand Bold.ttf"))
    std::cerr << "Error could not load the font" << std::endl;
  this->_tabTxt[0].setString("Play");
  this->_tabTxt[1].setString("HighScores");
  this->_tabTxt[2].setString("Quit");
  for (int cpt = 0; cpt < NB_MENU; ++cpt)
    {
      this->_tabTxt[cpt].setFont(this->_font);
      this->_tabTxt[cpt].setCharacterSize(FONT_SIZE);
      this->_tabTxt[cpt].setColor(sf::Color::White);
      rect = this->_tabTxt[cpt].getGlobalBounds();
      this->_tabTxt[cpt].setPosition((WINDOW_WIDTH  - rect.width ) / 2, pos);
      pos += 100;
    }
  this->_tabTxt[this->_menuPos].setStyle(sf::Text::Underlined);
}

Menu::~Menu(void)
{
  std::cout << "Destroying menu" << std::endl;
}

int		Menu::run(sf::RenderWindow& app)
{
  bool		running;
  sf::Event	event;

  running = true;
  std::cout << "In run" << std::endl;
  while (running)
    {
      //Verifying events
      while (app.pollEvent(event))
	{
	  this->handleInput(event);
	}
      //Clearing screen
      app.clear();
      //Drawing
      for (int cpt = 0; cpt < NB_MENU; ++cpt)
	app.draw(this->_tabTxt[cpt]);
      app.display();
    }
  return (-1);
}

int		Menu::handleInput(const sf::Event& event)
{
  int		menuPos;

  menuPos = this->_menuPos;
  // Window closed
  if (event.type == sf::Event::Closed ||
      (event.type == sf::Event::KeyPressed
       && event.key.code == sf::Keyboard::Escape))
    {
      return (-1);
    }
  //Key pressed
  if (event.type == sf::Event::KeyPressed)
    {
      // Taking out underline
      this->_tabTxt[menuPos].setStyle(!sf::Text::Underlined);
      switch (event.key.code)
	{
	case sf::Keyboard::Up:
	  menuPos--;
	  std::cout << "up" << std::endl;
	  break;
	case sf::Keyboard::Down:
	  menuPos++;
	  std::cout << "down" << std::endl;
	  break;
	case sf::Keyboard::Return:
	  this->_menuPos = menuPos;
	  switch (menuPos)
	    {
	    case 0:
	      //Let's get play !
	      // playing = true;
	      return (1);
	    case 1:
	      // TODO: Show highscores
	      return (-1);
	    case 2:
	      // Quit position
	      return (-1);
	    default:
	      break ;
	    }
	  break;
	default:
	  break;
	}
    }
  // Is menuPos out of bounds
  if (menuPos > NB_MENU - 1)
    {
      menuPos = 0;
    }
  else if (menuPos < 0)
    {
      menuPos = NB_MENU - 1;
    }
  this->_tabTxt[menuPos].setStyle(sf::Text::Underlined);
  return (-1);
}

  //When getting at alpha_max, we stop modifying the sprite
  // if (alpha<alpha_max)
  // 	{
  // 	  alpha++;
  // 	}
  // Sprite.setColor(sf::Color(255, 255, 255, alpha / alpha_div));
  // if (menu == 0)
  // 	{
  // 	  Menu1.setColor(sf::Color(255, 0, 0, 255));
  // 	  Menu2.setColor(sf::Color(255, 255, 255, 255));
  // 	  Menu3.setColor(sf::Color(255, 0, 0, 255));
  // 	}
  // else
  // 	{
  // 	  Menu1.setColor(sf::Color(255, 255, 255, 255));
  // 	  Menu2.setColor(sf::Color(255, 0, 0, 255));
  // 	  Menu3.setColor(sf::Color(255, 255, 255, 255));
  // 	}

  //   if (alpha == alpha_max)
  // 	{
  // 	  if (playing)
  // 	    {
  // 	      app.draw(Menu3);
  // 	    }
  // 	  else
  // 	    {
  // 	      app.draw(Menu1);
  // 	    }
  // 	  app.draw(Menu2);
  // 	}

  //Never reaching this point normally, but just in case, exit the application
