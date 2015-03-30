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
