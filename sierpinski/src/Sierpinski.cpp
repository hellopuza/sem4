#include "Sierpinski.h"

Sierpinski::Sierpinski(sf::Vector2f points[3], size_t recursion_num) :
    recursion_num_(recursion_num)
{
    for (size_t i = 0; i < 3; i++)
    {
        points_[i] = points[i];
    }
}

void Sierpinski::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
    draw(target, states, points_, recursion_num_);
}

void Sierpinski::draw(sf::RenderTarget& target, sf::RenderStates states, const sf::Vector2f points[3], const size_t recursion_num) const
{
    sf::VertexArray lines(sf::LineStrip, 4);
    for (size_t i = 0; i < 3; i++)
    {
        lines[i].position = points[i];
    }
    lines[3].position = points[0];

    target.draw(lines, states);

    if (recursion_num)
    {
        sf::Vector2f middle_points[3] = { {(points[0].x + points[1].x) / 2, (points[0].y + points[1].y) / 2},
                                          {(points[1].x + points[2].x) / 2, (points[1].y + points[2].y) / 2},
                                          {(points[2].x + points[0].x) / 2, (points[2].y + points[0].y) / 2}, };

        sf::Vector2f new_points[3] = { points[0], middle_points[0], middle_points[2] };
        draw(target, states, new_points, recursion_num - 1);

        new_points[0] = points[1];
        new_points[1] = middle_points[1];
        new_points[2] = middle_points[0];
        draw(target, states, new_points, recursion_num - 1);

        new_points[0] = points[2];
        new_points[1] = middle_points[2];
        new_points[2] = middle_points[1];
        draw(target, states, new_points, recursion_num - 1);
    }
}

void Sierpinski::move(sf::Vector2f movement)
{
    for (size_t i = 0; i < 3; i++)
    {
        points_[i] += movement;
    }
}