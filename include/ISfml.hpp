#ifndef     ISFML_HPP_
# define    ISFML_HPP_

# include   "IRenderer.hpp"
# include   "SFMLLoader.hpp"

class       ISfml : public IRenderer {
    private:
        ISfml(void);
        ISfml(const ISfml& other);
        ISfml&          operator=(const ISfml& other);
    public:
        virtual ~ISfml(void);
        virtual void    draw();
    protected:
        SFMLLoader      _loader;
};

#endif      // !ISFML_HPP_
