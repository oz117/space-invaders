/*
** Created by André Paulos
** paulos_a@epitech.eu
** Abstract class for the different windows
** of a space invader like game
*/

#ifndef		ASCREEN_HPP_
# define	ASCREEN_HPP_
# include	"sfml.hpp"

class		AScreen
{
public:
  virtual int	run(sf::RenderWindow& app) = 0;
  virtual int	handleInput() = 0;
};

#endif		/* !ASCREEN_HPP_ */
