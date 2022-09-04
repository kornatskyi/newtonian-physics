#include "../../include/CosmicBody.hpp"
#include "../../include/GravitationalSystem.hpp"

GravitationalSystem::GravitationalSystem(sf::Vector2f center) : body1(30.f, 10), body2(30.f, 10)
{
    this->center = center;

    body1.setFillColor(sf::Color(105, 143, 63));
    body2.setFillColor(sf::Color(10, 18, 42));
    setPositionOnA1DimensionalPlot(-10.f, body1);
    setPositionOnA1DimensionalPlot(0.f, body2);

    body1.setVelocity(sf::Vector2f(1, 0));

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

void GravitationalSystem::setPositionOnA1DimensionalPlot(float coordinate, CosmicBody &body)
{
    body.setCenterPosition(sf::Vector2f(this->center.x + coordinate, this->center.y));
}

float GravitationalSystem::getPositionOnA1DimensionalPlot(CosmicBody &body)
{
    return body.getCenterPosition().x - this->center.x;
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
    deltaTime = clock.getElapsedTime();
    clock.restart();
    std::cout << deltaTime.asSeconds() << std::endl;
    float body1DeltaDisplacement = deltaDisplacement(body1.getVelocity().x, deltaTime.asSeconds());
    float body1XPosition = getPositionOnA1DimensionalPlot(body1);
    setPositionOnA1DimensionalPlot(body1XPosition + body1DeltaDisplacement, body1);
}
float GravitationalSystem::deltaDisplacement(float speed, float time)
{
    return speed * time;
}
void GravitationalSystem::draw(sf::RenderTarget &target, sf::RenderStates states) const
{
    target.draw(body1, states);
    target.draw(body2, states);
    // target.draw(planetSpeedText);
    // target.draw(planetAccselerationText);

    // Draw a center
    sf::CircleShape point(2.f);
    point.setPosition(sf::Vector2f(center.x - 1, center.y - 1));
    point.setFillColor(sf::Color::Black);
    target.draw(point);
    // Draw an axis
    sf::RectangleShape axis(sf::Vector2f(1500.f, 2));
    axis.setPosition(sf::Vector2f(center.x - 750.f, center.y - 1));
    axis.setFillColor(sf::Color::Black);

    target.draw(axis);
}

void GravitationalSystem::setCenter(sf::Vector2f center)
{
    this->center = center;
}
