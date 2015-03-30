#ifndef     IRENDERER_HPP_
# define    IRENDERER_HPP_

# include   <iostream>

class                   IRenderer {
    public:
        virtual         ~IRenderer() {};
        virtual void    draw() = 0;
};

#endif      // !IRENDERER_HPP_
