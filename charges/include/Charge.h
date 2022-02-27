#ifndef CHARGE_H
#define CHARGE_H

#include <SFML\Graphics.hpp>
#include "vec2.h"

constexpr float CHARGE_RADIUS = 10.0F;

struct Charge : public sf::Drawable
{
    Charge(vec2f position_, float value_);

    virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;

    vec2f position;
    float value;
};

#endif // CHARGE_H