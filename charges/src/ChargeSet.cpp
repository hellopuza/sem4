#include "ChargeSet.h"

void ChargeSet::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
    for (const auto& charge : charges)
    {
        target.draw(charge, states);
    }
}

const std::vector<Charge>* ChargeSet::getSet() const
{
    return &charges;
}

void ChargeSet::append(const Charge& charge)
{
    charges.push_back(charge);
}

void ChargeSet::remove(const vec2f& position)
{
    for (auto it = charges.begin(), ite = charges.end(); it != ite; ++it)
    {
        if ((position - it->position).magnitute() < CHARGE_RADIUS)
        {
            charges.erase(it);
            return;
        }
    }
}

void ChargeSet::change(const vec2f& position, float value)
{
    for (auto it = charges.begin(), ite = charges.end(); it != ite; ++it)
    {
        if ((position - it->position).magnitute() < CHARGE_RADIUS)
        {
            it->value += value;
            return;
        }
    }
}