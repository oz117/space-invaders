/*
** File: [ISfmlClock.hpp]
** Author: zero.
** Contact: <andre.paulos@epitech.eu> (github.com/oz117)
** Created on 2015-04-29 17:15
**
*/

#ifndef     ISFMLCLOCK_HPP_
# define    ISFMLCLOCK_HPP_

# include   <SFML/System.hpp>
# include   "IClock.hpp"

class ISfmlClock : public IClock {
    private:
        ISfmlClock(const ISfmlClock& other);
        ISfmlClock& operator=(const ISfmlClock& other);
    public:
        ISfmlClock(void);
        ~ISfmlClock(void);
        void        start(void);
        int         getElapsedTimeAsSeconds(void);
        int         getElapsedTimeAsMilliseconds(void);
        void        restart(void);
    private:
        sf::Clock   _clock;
        sf::Time    _timeElapsed;
};

#endif      // !ISFMLCLOCK_HPP_
