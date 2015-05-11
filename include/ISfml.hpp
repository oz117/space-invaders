/*
** File: [ISfml.hpp]
** Author: zero.
** Contact: <andre.paulos@epitech.eu> (github.com/oz117)
** Created on 2015-04-03 17:45
**
*/

#ifndef     ISFML_HPP_
# define    ISFML_HPP_

# include   <SFML/Graphics.hpp>
# include   "IRenderer.hpp"
# include   "SFMLLoader.hpp"
# include   "Properties.hpp"

class       ISfml : public IRenderer {
    private:
        ISfml(const ISfml& other);
        ISfml&              operator=(const ISfml& other);
    public:
        ISfml(void);
        ~ISfml(void);
        void                draw(void);
        void                clear(void);
        void                display(void);
        bool                closeWindow(void);
        Keys::Key           handleInput(void);
        void                updatePosition(const Sprites::Sprite sprite, const pair2f& newPosition);
        SFMLLoader          _loader;
    protected:
        sf::RenderWindow    _window;
};

#endif      // !ISFML_HPP_
