#include "Field.h"

const float PI = atanf(1.0f) * 4.0F;

Field::Field(const std::vector<Charge>* charges_) :
    charges(charges_)
{}

void Field::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
    vec2f area_size = vec2f(target.getSize().x, target.getSize().y);

    sf::Vertex line[] = { sf::Vertex(sf::Vector2f(), sf::Color::White), sf::Vertex(sf::Vector2f(), sf::Color::White) };

    for (const auto& charge : *charges)
    {
        for (size_t i = 0; i < FIELD_LINES_NUM; i++)
        {
            float angle = static_cast<float>(i) / static_cast<float>(FIELD_LINES_NUM) * PI * 2.0F;
            vec2f begin = charge.position;
            vec2f end = vec2f(std::cos(angle), std::sin(angle)) * FIELD_LINE_LEN + begin;

            for (size_t n = 0; n < FIELD_ITERATION; n++)
            {
                line[0].position = sf::Vector2f(begin.x, begin.y);
                line[1].position = sf::Vector2f(end.x, end.y);
                target.draw(line, 2, sf::Lines, states);

                begin = end;

                vec2f delta;
                for (const auto& other : *charges)
                {
                    delta += (end - other.position) * other.value / std::pow((end - other.position).magnitute(), 3.0F);
                }
                end += delta.normalized() * FIELD_LINE_LEN;
            }
        }
    }
}