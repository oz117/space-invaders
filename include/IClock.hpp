/*
** File: [IClock.hpp]
** Author: zero.
** Contact: <andre.paulos@epitech.eu> (github.com/oz117)
** Created on 2015-04-29 15:57
**
*/

#ifndef     ICLOCK_HPP_
# define    ICLOCK_HPP_

class                   Clock {
    public:
        virtual         ~Clock(void) {};
        virtual void    startClock(void);
        virtual int     getElapsedTimeAsMilliseconds(void) const;
        virtual void    retartClock(void);
}

#endif      // !ICLOCK_HPP_
