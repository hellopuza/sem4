#include "Charge.h"

Charge::Charge(vec2f position_, float value_) :
    position(position_), value(value_)
{}

void Charge::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
    sf::CircleShape circle(CHARGE_RADIUS);
    circle.setPosition(sf::Vector2f(position.x - CHARGE_RADIUS, position.y - CHARGE_RADIUS));
    circle.setFillColor(value > 0.0F ? sf::Color::Red : sf::Color::Blue);
    target.draw(circle, states);
}