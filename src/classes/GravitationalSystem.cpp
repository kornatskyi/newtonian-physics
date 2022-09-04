#include "../../include/CosmicBody.hpp"
#include "../../include/GravitationalSystem.hpp"

GravitationalSystem::GravitationalSystem() : sun(40.f, sf::Vector2f(100.f, 70.f)), planet(10.f, sf::Vector2f(40.f, 50.f))
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

float GravitationalSystem::distnceBetweenTwoPoints(sf::Vector2f point1, sf::Vector2f point2)
{
    return std::sqrt(std::abs(point1.x - point2.x) + std::abs(point1.y - point2.y));
}

float GravitationalSystem::calcForce(float m1, float m2, float r)
{
    return (GRAVITY_CONSTANT * m1 * m2) / (r * r);
}

void GravitationalSystem::update()
{
}

void GravitationalSystem::draw(sf::RenderTarget &target, sf::RenderStates states) const
{
    target.draw(sun, states);
    target.draw(planet, states);
    // target.draw(planetSpeedText);
    // target.draw(planetAccselerationText);

    // Draw a center
    sf::CircleShape point(2.f);
    point.setPosition(center);
    point.setFillColor(sf::Color::White);
    target.draw(point);
    // Draw an axis
    sf::RectangleShape axis(sf::Vector2f(1500.f, 2));
    axis.setPosition(sf::Vector2f(center.x - 750.f, center.y));
    target.draw(axis);
}

void GravitationalSystem::setCenter(sf::Vector2f center)
{
    this->center = center;
}
