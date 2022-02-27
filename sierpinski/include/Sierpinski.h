#ifndef SIERPINSKI_H
#define SIERPINSKI_H

#include <SFML\Graphics.hpp>

class Sierpinski : public sf::Drawable
{
public:
    Sierpinski(sf::Vector2f points[3], size_t recursion_num);

    virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;
    void draw(sf::RenderTarget& target, sf::RenderStates states, const sf::Vector2f points[3], const size_t recursion_num) const;
    void move(sf::Vector2f movement);

private:
    size_t recursion_num_;
    sf::Vector2f points_[3];
};

#endif // SIERPINSKI_H