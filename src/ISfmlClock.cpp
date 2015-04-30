#include "ISfmlClock.hpp"

ISfmlClock::ISfmlClock(void) {
    this->_clock.restart();
}

ISfmlClock::~ISfmlClock(void) {
}

void    ISfmlClock::start(void) {
    this->_clock.restart();
}

int     ISfmlClock::getElapsedTimeAsSeconds(void) {
    this->_timeElapsed = this->_clock.getElapsedTime();
    return (this->_timeElapsed.asSeconds());
}

int     ISfmlClock::getElapsedTimeAsMilliseconds(void) {
    this->_timeElapsed = this->_clock.getElapsedTime();
    return (this->_timeElapsed.asMilliseconds());
}

void    ISfmlClock::restart(void) {
    this->_clock.restart();
}
