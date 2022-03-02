#include <SFML\Graphics.hpp>
#include "ChargeSet.h"
#include "Field.h"

constexpr size_t DEFAULT_WIDTH = 1024;
constexpr size_t DEFAULT_HEIGHT = 768;

constexpr float DEFAULT_CHARGE_VALUE = 1.0F;

int main()
{
    sf::RenderWindow window(sf::VideoMode(DEFAULT_WIDTH, DEFAULT_HEIGHT), "My window");
    ChargeSet charge_set;
    Field field(charge_set.getSet());

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            // Close window
            if ((event.type == sf::Event::Closed) ||
                ((event.type == sf::Event::KeyPressed) && (event.key.code == sf::Keyboard::Escape)))
            {
                window.close();
            }

            // Resize window
            else if (event.type == sf::Event::Resized)
            {
                sf::FloatRect visible_area(0.0F, 0.0F, static_cast<float>(event.size.width),
                    static_cast<float>(event.size.height));
                window.setView(sf::View(visible_area));
            }

            // Set charge
            else if ((event.type == sf::Event::MouseButtonPressed) && (event.mouseButton.button == sf::Mouse::Left))
            {
                sf::Vector2i pos = sf::Mouse::getPosition(window);
                charge_set.append(Charge(vec2f(pos.x, pos.y), DEFAULT_CHARGE_VALUE));
            }

            // Remove charge
            else if ((event.type == sf::Event::MouseButtonPressed) && (event.mouseButton.button == sf::Mouse::Right))
            {
                sf::Vector2i pos = sf::Mouse::getPosition(window);
                charge_set.remove(vec2f(pos.x, pos.y));
            }

            // Change charge
            else if (event.type == sf::Event::MouseWheelMoved)
            {
                sf::Vector2i pos = sf::Mouse::getPosition(window);
                charge_set.change(vec2f(pos.x, pos.y), 0.4F * static_cast<float>(event.mouseWheel.delta));
            }
        }

        window.clear();
        window.draw(field);
        window.draw(charge_set);
        window.display();
    }

    return 0;
}