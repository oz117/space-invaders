#ifndef     SPRITE_HPP_
#define     SPRITE_HPP_

# include   <iostream>
# include   <string>

class                       Sprite {
    private:
        Sprite(void);
        Sprite(const Sprite& other);
        Sprite&             operator=(const Sprite& other);
    public:
        Sprite(const std::string& file, const std::pair<int, int>& size);
        const std::string&  getFile(void) const;
    protected:
        std::string         _file;
        std::pair<int, int> _size;
};

#endif      //!SPRITE_HPP_
