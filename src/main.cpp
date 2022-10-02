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
    const sf::Color BACKGROUND_COLOR = sf::Color(139, 139, 139);
    // const sf::Color BACKGROUND_COLOR = sf::Color::Black;

    sf::Event event;

    sf::Vector2u windowSize(1400, 800);

    sf::RenderWindow window(sf::VideoMode(windowSize.x, windowSize.y), "My window", sf::Style::Default);
    window.setPosition(sf::Vector2i(2000, 50));

    sf::Vector2i mousePosition;

    sf::Vector2f centerOfTheScreen(window.getSize().x / 2, window.getSize().y / 2);

    GravitationalSystem gravitySystem(centerOfTheScreen);

    sf::View view(centerOfTheScreen, sf::Vector2f(windowSize.x, windowSize.y));

    sf::Vector2f oldPos;
    bool moving = false;
    while (window.isOpen())
    {
        window.setView(view);
        mousePosition = sf::Mouse::getPosition(window);
        gravitySystem.update();

        window.clear(BACKGROUND_COLOR);
        window.draw(gravitySystem);

        window.display();

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
                break;
            case sf::Event::MouseWheelScrolled:
                if (event.mouseWheelScroll.delta < 0.f)
                {
                    view.zoom(0.8);
                }
                else
                {
                    view.zoom(1.5);
                }
                break;
            case sf::Event::Resized:
                view.setSize(window.getSize().x, window.getSize().y);
                break;
            case sf::Event::MouseButtonPressed:
                // Mouse button is pressed, get the position and set moving as active
                if (event.mouseButton.button == 0)
                {
                    moving = true;
                    oldPos = window.mapPixelToCoords(sf::Vector2i(event.mouseButton.x, event.mouseButton.y));
                }
                break;
            case sf::Event::MouseButtonReleased:
                // Mouse button is released, no longer move
                if (event.mouseButton.button == 0)
                {
                    moving = false;
                }
                break;
            case sf::Event::MouseMoved:
            {
                // Ignore mouse movement unless a button is pressed (see above)
                if (!moving)
                    break;
                // Determine the new position in world coordinates
                const sf::Vector2f newPos = window.mapPixelToCoords(sf::Vector2i(event.mouseMove.x, event.mouseMove.y));
                // Determine how the cursor has moved
                // Swap these to invert the movement direction
                const sf::Vector2f deltaPos = oldPos - newPos;

                // Move our view accordingly and update the window
                view.setCenter(view.getCenter() + deltaPos);
                window.setView(view);

                // Save the new position as the old one
                // We're recalculating this, since we've changed the view
                oldPos = window.mapPixelToCoords(sf::Vector2i(event.mouseMove.x, event.mouseMove.y));
                break;
            }
            default:
                break;
            }
        }
    }

    return 0;
}
