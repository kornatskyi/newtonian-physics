#include "../../include/CosmicBody.hpp"
#include "../../include/GravitationalSystem.hpp"

const double SUN_RADIUS_m = 695508000;
const double SUN_MASS_kg = 1989100000 * pow(10, 21);
const double EARTH_RADIUS_m = 6371000;
const double EARTH_MASS_kg = 5972.4 * pow(10, 21);
const double DISTANCE_BETWEEN_EARTH_AND_SUN_m = 149600000000;
const double EARTH_ORBITAL_SPEED_m_per_s = 29722;

GravitationalSystem::GravitationalSystem(sf::Vector2f center)
{
    std::cout << (SUN_RADIUS_m * pow(10, -9)) << std::endl;

    std::cout << SUN_MASS_kg << std::endl;
    // CosmicBody sun(10.f, 29.f, center), earth((float)(EARTH_RADIUS_m * pow(10, -9)), (float)EARTH_MASS_kg * pow(10, -9), sf::Vector2f(center.x, center.y - DISTANCE_BETWEEN_EARTH_AND_SUN_m * pow(10, -9)));
    CosmicBody sun(30, (float)(SUN_MASS_kg * pow(10, -9)), center), earth((float)(EARTH_RADIUS_m * pow(10, -6)), (float)(EARTH_MASS_kg * pow(10, -9)), sf::Vector2f(center.x, center.y - DISTANCE_BETWEEN_EARTH_AND_SUN_m * pow(10, -9)));
    earth.setVelocity(sf::Vector2f(EARTH_ORBITAL_SPEED_m_per_s, 0));
    this->center = center;
    counter = 0;

    secondConunt = 0.0f;
    seconds = 0.f;

    bodies = new std::vector<CosmicBody>();
    bodies->push_back(sun);
    bodies->push_back(earth);

    // bodies->push_back(CosmicBody(20.f, 115125.f));
    // bodies->at(0).setCenterPosition(sf::Vector2f(500.f, 500.f));
    // bodies->push_back(CosmicBody(100.f, 11902598189758.f));
    // bodies->at(1).setCenterPosition(sf::Vector2f(700.f, 150.f));
    // bodies->push_back(CosmicBody(50.f, 12978410.f));
    // bodies->at(2).setCenterPosition(sf::Vector2f(300.f, 550.f));
}

GravitationalSystem::~GravitationalSystem()
{
    std::cout << "Destructor executed" << std::endl;
    delete bodies;
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
    if (counter > 100) // count 100 update loop iterations intead of using time class
    {

        deltaTime = clock.getElapsedTime();
        clock.restart();

        seconds += deltaTime.asSeconds();
        informationDisplayer.setTextField("Seconds", "Seconds:" + std::to_string(seconds));

        // sf::Vector2f d = calculateRadiusVector(body1.getPosition(), body2.getPosition());
        // sf::Vector2f force = calculateForce(body1.getMass(), body2.getMass(), d);
        // body1.applyForce(-force);
        // body2.applyForce(force);

        for (long unsigned int i = 0; i < bodies->size(); i++)
        {
            for (long unsigned int j = 0; j < bodies->size(); j++)
            {
                if (&bodies->at(i) != &bodies->at(j))
                {
                    sf::Vector2f d = calculateRadiusVector(bodies->at(i).getCenterPosition(), bodies->at(j).getCenterPosition());
                    sf::Vector2f force = calculateForce(bodies->at(i).getMass(), bodies->at(j).getMass(), d);
                    bodies->at(i).applyForce(-force);
                    bodies->at(j).applyForce(force);
                }
                bodies->at(i).functionOverTime(0.00001);
                bodies->at(j).functionOverTime(0.00001);
            }
        }

        // call time dependent functions on the bodies to calculate it's characteristics
        // body1.functionOverTime(deltaTime.asMicroseconds());

        // body2.functionOverTime(deltaTime.asMicroseconds());
        // body1.functionOverTime(1);
        // body2.functionOverTime(1);

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
    target.draw(informationDisplayer, states);

    for (long unsigned int i = 0; i < bodies->size(); i++)
    {
        target.draw(bodies->at(i), states);
    }

    // Draw a center
    // sf::CircleShape point(2.f);
    // point.setPosition(sf::Vector2f(center.x - 1, center.y - 1));
    // point.setFillColor(sf::Color::Black);
    // target.draw(point);
    // // Draw an axis
    // sf::RectangleShape axis(sf::Vector2f(1500.f, 2));
    // axis.setPosition(sf::Vector2f(center.x - 750.f, center.y - 1));
    // axis.setFillColor(sf::Color::Black);

    // target.draw(axis);
}

void GravitationalSystem::setCenter(sf::Vector2f center)
{
    this->center = center;
}
