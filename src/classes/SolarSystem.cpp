#include "../../include/CosmicBody.hpp"
#include "../../include/SolarSystem.hpp"

SolarSystem::SolarSystem() : sun(40.f, sf::Vector2f(100.f, 70.f)), planet(10.f, sf::Vector2f(40.f, 50.f))
{
    // sun = CosmicBody(40.f, sf::Vector2f(100.f, 70.f));
    // planet = CosmicBody(10.f, sf::Vector2f(40.f, 50.f));

    sun.setFillColor(sf::Color::Yellow);
    planet.setFillColor(sf::Color::Green);
    sun.setCenterPosition(center);
    planet.setCenterPosition(sf::Vector2f(this->center.x - 50, this->center.y - 50));

    if (!font.loadFromFile("./assets/fonts/MesloLGS NF Regular.ttf"))
    {
        std::cout << "Font not found" << std::endl;
    }
    planetSpeedText.setFont(font);
    planetSpeedText.setCharacterSize(16);
    planetSpeedText.setString("Hello world");
    planetSpeedText.setFillColor(sf::Color::Red);

    planetAccselerationText.setPosition(0.0f, 20.0f);
    planetAccselerationText.setFont(font);
    planetAccselerationText.setCharacterSize(16);
    planetAccselerationText.setString("Hello world");
    planetAccselerationText.setFillColor(sf::Color::Red);

    secondConunt = 0.0f;
    seconds = 0;
}

float SolarSystem::distnceBetweenTwoPoints(sf::Vector2f point1, sf::Vector2f point2)
{
    return std::sqrt(std::abs(point1.x - point2.x) + std::abs(point1.y - point2.y));
}

float SolarSystem::calcForce(float m1, float m2, float r)
{
    return (GRAVITY_CONSTANT * m1 * m2) / (r * r);
}

void SolarSystem::update()
{
}

void SolarSystem::draw(sf::RenderTarget &target, sf::RenderStates states) const
{
    target.draw(sun, states);
    target.draw(planet, states);
    // target.draw(planetSpeedText);
    // target.draw(planetAccselerationText);
}

// SolarSystem::SolarSystem()
// {
//     sun.setFillColor(sf::Color::Yellow);
//     planet.setFillColor(sf::Color::Green);
//     sun.setCenterPosition(center);
//     planet.setCenterPosition(sf::Vector2f(this->center.x - 50, this->center.y - 50));

//     if (!font.loadFromFile("./assets/fonts/MesloLGS NF Regular.ttf"))
//     {
//         std::cout << "Font not found" << std::endl;
//     }
//     planetSpeedText.setFont(font);
//     planetSpeedText.setCharacterSize(16);
//     planetSpeedText.setString("Hello world");
//     planetSpeedText.setFillColor(sf::Color::Red);

//     planetAccselerationText.setPosition(0.0f, 20.0f);
//     planetAccselerationText.setFont(font);
//     planetAccselerationText.setCharacterSize(16);
//     planetAccselerationText.setString("Hello world");
//     planetAccselerationText.setFillColor(sf::Color::Red);

//     secondConunt = 0.0f;
//     seconds = 0;
// }

// void SolarSystem::update()
// {
//     deltaTime = clock.getElapsedTime();
//     clock.restart();

//     // Counting seconds and printing them
//     secondConunt = secondConunt + deltaTime.asSeconds();
//     float acceleration;
//     if (secondConunt > 1)
//     {
//         seconds++;
//         secondConunt = 0;
//         std::cout << seconds << std::endl;
//         acceleration = calcForce(sun.getMass(), planet.getMass(), distnceBetweenTwoPoints(sun.getPosition(), planet.getPosition())) / planet.getMass();
//         planet.setSpeed(planet.getSpeed() + acceleration);
//         planet.move(planet.getSpeed(), planet.getSpeed());
//     }

//     // Calculate acceleration and speed
//     //   float acceleration = calcForce(sun.getMass(), planet.getMass(), distnceBetweenTwoPoints(sun.getPosition(), planet.getPosition())) / planet.getMass();
//     //         planet.setSpeed(planet.getSpeed() + (acceleration * deltaTime.asSeconds()));
//     // planet.move((planet.getSpeed() * deltaTime.asSeconds()), (planet.getSpeed() * deltaTime.asSeconds()));

//     planetSpeedText.setString("Planets speed: " + std::to_string(planet.getSpeed()));
//     planetAccselerationText.setString("Planets acseleration: " + std::to_string(acceleration));
// }

// float SolarSystem::distnceBetweenTwoPoints(sf::Vector2f point1, sf::Vector2f point2)
// {
//     return std::sqrt(std::abs(point1.x - point2.x) + std::abs(point1.y - point2.y));
// }

// float SolarSystem::calcForce(float m1, float m2, float r)
// {
//     return (GRAVITY_CONSTANT * m1 * m2) / (r * r);
// }

// void SolarSystem::draw(sf::RenderTarget &target, sf::RenderStates states) const
// {
//     target.draw(sun, states);
//     target.draw(planet, states);
//     target.draw(planetSpeedText);
//     target.draw(planetAccselerationText);
// }