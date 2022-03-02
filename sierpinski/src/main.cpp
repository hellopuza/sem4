#include <SFML\Graphics.hpp>
#include "Sierpinski.h"

constexpr size_t DEFAULT_WIDTH = 1024;
constexpr size_t DEFAULT_HEIGHT = 768;

int main()
{
    sf::RenderWindow window(sf::VideoMode(DEFAULT_WIDTH, DEFAULT_HEIGHT), "My window");

    sf::Vector2f points[3] = { {DEFAULT_WIDTH / 2, 20},
                               {50, 2 * DEFAULT_HEIGHT / 3},
                               {DEFAULT_WIDTH - 50, 2 * DEFAULT_HEIGHT / 3} };

    Sierpinski triangle(points, 7);
    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
            {
                window.close();
            }
        }

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
        {
            triangle.move(sf::Vector2f(-4.0F, 0.0F));
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
        {
            triangle.move(sf::Vector2f(4.0F, 0.0F));
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
        {
            triangle.move(sf::Vector2f(0.0F, -4.0F));
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
        {
            triangle.move(sf::Vector2f(0.0F, 4.0F));
        }

        window.clear();
        window.draw(triangle);
        window.display();
    }

    return 0;
}