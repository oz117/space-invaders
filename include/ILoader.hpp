/*
** File: [ILoader.hpp]
** Author: zero.
** Contact: <andre.paulos@epitech.eu> (github.com/oz117)
** Created on 2015-04-02 18:41
**
*/

#ifndef     ILOADER_HPP_
# define    ILOADER_HPP_

# include   "Sprite.hpp"

class       ILoader {
    private:
        ILoader(void);
    public:
        ILoader(const Sprite& sprite);

};

#endif      // !ILOADER_HPP_
