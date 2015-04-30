/*
** File: [IClock.hpp]
** Author: zero.
** Contact: <andre.paulos@epitech.eu> (github.com/oz117)
** Created on 2015-04-29 15:57
**
*/

#ifndef     ICLOCK_HPP_
# define    ICLOCK_HPP_

class                   IClock {
    public:
        virtual         ~IClock(void) {};
        virtual void    start(void) = 0;
        virtual int     getElapsedTimeAsMilliseconds(void) = 0;
        virtual int     getElapsedTimeAsSeconds(void) = 0;
        virtual void    restart(void) = 0;
};

#endif      // !ICLOCK_HPP_
