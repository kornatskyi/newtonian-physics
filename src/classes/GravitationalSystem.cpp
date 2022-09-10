#include "../../include/CosmicBody.hpp"
#include "../../include/GravitationalSystem.hpp"

GravitationalSystem::GravitationalSystem(sf::Vector2f center) : body1(30.f, 10), body2(30.f, 10)
{
    this->center = center;

    body1.setFillColor(sf::Color(105, 143, 63));
    body2.setFillColor(sf::Color(10, 18, 42));
    setPositionOnA1DimensionalPlot(-50.f, body1);
    setPositionOnA1DimensionalPlot(0.f, body2);

    body1.applyForce(sf::Vector2f(20.f, 15.f));
    body2.applyForce(sf::Vector2f(10.f, -40.f));

    secondConunt = 0.0f;
    seconds = 0.f;
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

    seconds += deltaTime.asSeconds();

    informationDisplayer.setTextField("Seconds", "Seconds:" + std::to_string(seconds));

    // call time dependent functions on the bodies to calculate it's characteristics
    body1.functionOverTime(deltaTime.asSeconds());
    body2.functionOverTime(deltaTime.asSeconds());
}
float GravitationalSystem::deltaDisplacement(float speed, float time)
{
    return speed * time;
}
void GravitationalSystem::draw(sf::RenderTarget &target, sf::RenderStates states) const
{
    target.draw(body1, states);
    target.draw(body2, states);
    target.draw(informationDisplayer, states);
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
