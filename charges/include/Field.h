#ifndef FIELD_H
#define FIELD_H

#include <SFML\Graphics.hpp>
#include "ChargeSet.h"

constexpr size_t FIELD_LINES_NUM = 20;
constexpr size_t FIELD_ITERATION = 300;
constexpr float FIELD_LINE_LEN = 5.0F;

struct Field : public sf::Drawable
{
    Field(const std::vector<Charge> *charges_);

    virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;

    const std::vector<Charge> *charges;
};

#endif // FIELD_H