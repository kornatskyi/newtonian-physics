#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>
#include <SFML/Graphics/CircleShape.hpp>
#include <iostream>
#include <cmath>

#include "../include/CosmicBody.hpp"
#include "../include/GravitationalSystem.hpp"

int main()
{

    // Settings
    const sf::Color BACKGROUND_COLOR = sf::Color(231, 222, 205);

    sf::Event event;

    sf::Vector2u windowSize(1500, 900);

    sf::RenderWindow window(sf::VideoMode(windowSize.x, windowSize.y), "My window");
    window.setPosition(sf::Vector2i(2000, 50));

    sf::Vector2i mousePosition;

    sf::Vector2f centerOfTheScreen(window.getSize().x / 2, window.getSize().y / 2);

    sf::Vector2f sunPosition{30.f, 50.f};

    GravitationalSystem gravitySystem(centerOfTheScreen);

    while (window.isOpen())
    {
        mousePosition = sf::Mouse::getPosition(window);
        gravitySystem.update();

        window.clear(BACKGROUND_COLOR);
        // window.draw(sun);
        // window.draw(planet);
        // window.draw(orbit);
        window.draw(gravitySystem);

        window.display();

        // std::cout << mousePosition.x << ", " << mousePosition.y << std::endl;

        while (window.pollEvent(event))
        {
            switch (event.type)
            {
            case sf::Event::Closed:
                window.close();
                break;
            case sf::Event::KeyPressed:
                if (event.key.code == sf::Keyboard::Escape)
                {
                    window.close();
                }
            default:
                break;
            }
        }
    }

    return 0;
}
