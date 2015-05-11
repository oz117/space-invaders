/*
** File: [IRenderer.hpp]
** Author: zero.
** Contact: <andre.paulos@epitech.eu> (github.com/oz117)
** Created on 2015-04-13 20:09
**
*/

#ifndef     IRENDERER_HPP_
# define    IRENDERER_HPP_

# include   <iostream>
# include   "Sprite.hpp"
# include   "Typedefs.hpp"

namespace                   Keys {
    enum                    Key{
        LEFT,
        RIGHT,
        ESC,
        NONE
    };
}

class                       IRenderer {
    public:
        virtual             ~IRenderer() {};
        virtual void        draw(void) = 0;
        virtual void        clear(void) = 0;
        virtual void        display(void) = 0;
        virtual bool        closeWindow(void) = 0;
        virtual Keys::Key   handleInput(void) = 0;
        virtual void        updatePosition(const Sprites::Sprite sprite, const pair2f& newPosition) = 0;
};

#endif      // !IRENDERER_HPP_
