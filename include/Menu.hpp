/*
** Created by André Paulos
** paulos_a@epitech.eu
** Menu for a space invader like game
*/

#ifndef		MENU_HPP_
# define	MENU_HPP_

# include	"AScreen.hpp"
# include	"include.hpp"

class			Menu : public AScreen
{
  const static int	FONT_SIZE = 30;
  const static int	NB_MENU = 3;
public:
  Menu(void);
  ~Menu(void);
private:
  Menu(const Menu& other);
  Menu&	operator=(const Menu& other);
public:
  int			run(sf::RenderWindow& app);
  using			AScreen::handleInput;
  int			handleInput(const sf::Event& event);
protected:
  // For use later to show a background
  //sf::Sprite		_background;
  sf::Texture		_texture;
  sf::Font		_font;
  sf::Text		_tabTxt[NB_MENU];
private:
  int			_menuPos;
};

#endif		/* !MENU_HPP_ */
