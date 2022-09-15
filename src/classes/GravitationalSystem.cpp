#include "../../include/CosmicBody.hpp"
#include "../../include/GravitationalSystem.hpp"

GravitationalSystem::GravitationalSystem(sf::Vector2f center) : body1(30.f, 100000000000), body2(30.f, 1)
{
    this->center = center;
    counter = 0;

    body1.setFillColor(sf::Color(105, 143, 63));
    body2.setFillColor(sf::Color(10, 18, 42));
    setPositionOnA1DimensionalPlot(-50.f, body1);
    setPositionOnA1DimensionalPlot(50.f, body2);
    body2.setVelocity(sf::Vector2f(0.2, 0.1));

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

float GravitationalSystem::calcForce(float m1, float m2, float d)
{
    return (GRAVITY_CONSTANT * m1 * m2) / (d * d);
}

sf::Vector2f GravitationalSystem::calculateForce(float mass1, float mass2, sf::Vector2f d)
{

    float absDisplacement = std::sqrt(std::pow(d.x, 2) + std::pow(d.y, 2));
    float absForce = ((GRAVITY_CONSTANT * mass1 * mass2) / (d.x * d.x + d.y * d.y));
    sf::Vector2f force(absForce * (d.x / absDisplacement), absForce * (d.y / absDisplacement));
    return force;
}

sf::Vector2f GravitationalSystem::calculateRadiusVector(sf::Vector2f point1, sf::Vector2f point2)
{
    return point1 - point2;
}

void GravitationalSystem::update()
{
    if (counter > 10) // count 100 update loop iterations intead of using time class
    {

        deltaTime = clock.getElapsedTime();
        clock.restart();

        seconds += deltaTime.asSeconds();
        informationDisplayer.setTextField("Seconds", "Seconds:" + std::to_string(seconds));
        informationDisplayer.setTextField("positionBody1", "body1 position: x: " + InformationDisplayer::numberToString(body1.getPosition().x) + "  y:" + InformationDisplayer::numberToString(body1.getPosition().y));
        informationDisplayer.setTextField("positionBody2", "body2 position: x: " + InformationDisplayer::numberToString(body2.getPosition().x) + "  y:" + InformationDisplayer::numberToString(body2.getPosition().y));
        informationDisplayer.setTextField("forceBody1", "body1 experienced force: x: " + InformationDisplayer::numberToString(body1.getForce().x) + "  y:" + InformationDisplayer::numberToString(body1.getForce().y));
        informationDisplayer.setTextField("forceBody2", "body2 experienced force: x: " + InformationDisplayer::numberToString(body2.getForce().x) + "  y:" + InformationDisplayer::numberToString(body2.getForce().y));
        informationDisplayer.setTextField("velocityBody1", "body1 velocity: x: " + InformationDisplayer::numberToString(body1.getVelocity().x) + "  y:" + InformationDisplayer::numberToString(body1.getVelocity().y));
        informationDisplayer.setTextField("velocityBody2", "body2 velocity: x: " + InformationDisplayer::numberToString(body2.getVelocity().x) + "  y:" + InformationDisplayer::numberToString(body2.getVelocity().y));

        // draw bodies' names
        informationDisplayer.setTextField("body1", "body1", body1.getPosition());
        informationDisplayer.setTextField("body2", "body2", body2.getPosition());

        sf::Vector2f d = calculateRadiusVector(body1.getPosition(), body2.getPosition());
        sf::Vector2f force = calculateForce(body1.getMass(), body2.getMass(), d);
        body1.applyForce(-force);
        body2.applyForce(force);

        // call time dependent functions on the bodies to calculate it's characteristics
        // body1.functionOverTime(deltaTime.asMicroseconds());

        // body2.functionOverTime(deltaTime.asMicroseconds());
        body1.functionOverTime(1);
        body2.functionOverTime(1);

        counter = 0;
    }
    else
    {
        counter++;
    }
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
