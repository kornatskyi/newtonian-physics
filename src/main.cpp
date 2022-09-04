
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>
#include <SFML/Graphics/CircleShape.hpp>
#include <iostream>
#include <cmath>

#include "../include/CosmicBody.hpp"
#include "../include/SolarSystem.hpp"

class Orbit : public sf::CircleShape
{

public:
    Orbit(float radius = 0, std::size_t pointCount = 30) : sf::CircleShape(radius, pointCount)
    {
    }

    void setCenterPosition(sf::Vector2f position)
    {
        float radius = this->getRadius();
        this->setPosition(position.x - radius, position.y - radius);
    }
};

int main()
{

    sf::Event event;

    sf::Vector2u windowSize(800, 600);

    sf::RenderWindow window(sf::VideoMode(windowSize.x, windowSize.y), "My window");
    window.setPosition(sf::Vector2i(2000, 50));

    sf::Vector2i mousePosition;

    sf::Vector2f centerOfTheScreen(window.getSize().x / 2, window.getSize().y / 2);

    CosmicBody sun(30.f);
    sun.setCenterPosition(centerOfTheScreen);

    CosmicBody planet(10.f);

    sun.setFillColor(sf::Color::Red);

    Orbit orbit(100.f, 100);
    orbit.setOutlineThickness(2.f);
    orbit.setFillColor(sf::Color::Transparent);
    orbit.setOutlineColor(sf::Color::White);
    orbit.setCenterPosition(centerOfTheScreen);

    SolarSystem solarSystem;

    while (window.isOpen())
    {
        mousePosition = sf::Mouse::getPosition(window);
        solarSystem.update();

        window.clear(sf::Color::Black);
        // window.draw(sun);
        // window.draw(planet);
        // window.draw(orbit);
        window.draw(solarSystem);

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

// int main()
// {
//     sf::RenderWindow window(sf::VideoMode(200, 200), "SFML works!");
//     sf::CircleShape shape(100.f);

//     sf::Clock clock; // starts the clock
//     shape.setFillColor(sf::Color::Green);
//     int iterator = 0;
//     while (window.isOpen())
//     {

//         for (int i = 0; i < 1001; i++)
//         {
//             // std::cout << "takesome time" << std::endl;
//             iterator++;
//         }

//         sf::Time elapsed1 = clock.getElapsedTime();
//         std::cout << elapsed1.asSeconds() << std::endl;
//         clock.restart();

//         sf::Event event;
//         while (window.pollEvent(event))
//         {
//             if (event.type == sf::Event::Closed)
//                 window.close();
//         }
//         window.clear();
//         window.draw(shape);
//         window.display();

//         clock.restart();
//     }

//     return 0;
// }
