#ifndef CHARGESET_H
#define CHARGESET_H

#include <SFML\Graphics.hpp>
#include "Charge.h"

struct ChargeSet : public sf::Drawable
{
    ChargeSet() = default;

    virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;
    const std::vector<Charge>* getSet() const;

    void append(const Charge& charge);
    void remove(const vec2f& position);
    void change(const vec2f& position, float value);

private:
    std::vector<Charge> charges;
};

#endif // CHARGESET_H