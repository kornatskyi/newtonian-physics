#include "../../include/CosmicBody.hpp"
#include "../../include/GravitationalSystem.hpp"
#include "../../include/data/SolarSystemBodiesData.hpp"

const double SIZE_SCALE_FACTOR = -6.5;

const double TIME_INTERVAL = 0.00001;

GravitationalSystem::GravitationalSystem(sf::Vector2f center)
{
    CosmicBody
        sun(multiplyByTenToThePower(sunData.radius, -8), multiplyByTenToThePower(sunData.mass), center),
        mercury(multiplyByTenToThePower(mercuryData.radius, SIZE_SCALE_FACTOR),
                multiplyByTenToThePower(mercuryData.mass),
                sf::Vector2f(center.x, center.y - multiplyByTenToThePower(mercuryData.orbitalRadius))),
        venus(multiplyByTenToThePower(venusData.radius, SIZE_SCALE_FACTOR),
              multiplyByTenToThePower(venusData.mass),
              sf::Vector2f(center.x, center.y - multiplyByTenToThePower(venusData.orbitalRadius))),
        earth(multiplyByTenToThePower(earthData.radius, SIZE_SCALE_FACTOR),
              multiplyByTenToThePower(earthData.mass),
              sf::Vector2f(center.x, center.y - multiplyByTenToThePower(earthData.orbitalRadius))),
        mars(multiplyByTenToThePower(marsData.radius, SIZE_SCALE_FACTOR),
             multiplyByTenToThePower(marsData.mass),
             sf::Vector2f(center.x, center.y - multiplyByTenToThePower(marsData.orbitalRadius))),
        jupiter(multiplyByTenToThePower(jupiterData.radius, SIZE_SCALE_FACTOR),
                multiplyByTenToThePower(jupiterData.mass),
                sf::Vector2f(center.x, center.y - multiplyByTenToThePower(jupiterData.orbitalRadius))),
        saturn(multiplyByTenToThePower(saturnData.radius, SIZE_SCALE_FACTOR),
               multiplyByTenToThePower(saturnData.mass),
               sf::Vector2f(center.x, center.y - multiplyByTenToThePower(saturnData.orbitalRadius))),
        uranus(multiplyByTenToThePower(uranusData.radius, SIZE_SCALE_FACTOR),
               multiplyByTenToThePower(uranusData.mass),
               sf::Vector2f(center.x, center.y - multiplyByTenToThePower(uranusData.orbitalRadius))),
        neptun(multiplyByTenToThePower(neptunData.radius, SIZE_SCALE_FACTOR),
               multiplyByTenToThePower(neptunData.mass),
               sf::Vector2f(center.x, center.y - multiplyByTenToThePower(neptunData.orbitalRadius)));

    sun.setFillColor(sf::Color::Yellow);

    mercury.setVelocity(sf::Vector2f(orbitalSpeed(mercuryData.siderealPeriod, mercuryData.orbitalRadius), 0));
    mercury.setFillColor(sf::Color::Red);

    venus.setVelocity(sf::Vector2f(orbitalSpeed(venusData.siderealPeriod, venusData.orbitalRadius), 0));
    venus.setFillColor(sf::Color::Black);

    earth.setVelocity(sf::Vector2f(orbitalSpeed(earthData.siderealPeriod, earthData.orbitalRadius), 0));
    earth.setFillColor(sf::Color::Blue);

    mars.setVelocity(sf::Vector2f(orbitalSpeed(marsData.siderealPeriod, marsData.orbitalRadius), 0));
    mars.setFillColor(sf::Color::Red);

    jupiter.setVelocity(sf::Vector2f(orbitalSpeed(jupiterData.siderealPeriod, jupiterData.orbitalRadius), 0));
    jupiter.setFillColor(sf::Color::Red);

    saturn.setVelocity(sf::Vector2f(orbitalSpeed(saturnData.siderealPeriod, saturnData.orbitalRadius), 0));
    saturn.setFillColor(sf::Color::Red);

    uranus.setVelocity(sf::Vector2f(orbitalSpeed(uranusData.siderealPeriod, uranusData.orbitalRadius), 0));
    uranus.setFillColor(sf::Color::Red);

    neptun.setVelocity(sf::Vector2f(orbitalSpeed(neptunData.siderealPeriod, neptunData.orbitalRadius), 0));
    neptun.setFillColor(sf::Color::Red);

    this->center = center;
    counter = 0;

    secondConunt = 0.0f;
    seconds = 0.f;

    bodies = new std::vector<CosmicBody>();
    bodies->push_back(sun);
    bodies->push_back(mercury);
    bodies->push_back(venus);
    bodies->push_back(earth);
    bodies->push_back(mars);
    bodies->push_back(jupiter);
    bodies->push_back(saturn);
    bodies->push_back(uranus);
    bodies->push_back(neptun);
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
    return point2 - point1;
}

void GravitationalSystem::update()
{
    if (counter > 10) // count 100 update loop iterations intead of using time class
    {

        deltaTime = clock.getElapsedTime();
        clock.restart();

        seconds += deltaTime.asSeconds();
        informationDisplayer.setTextField("Seconds", "Seconds:" + std::to_string(seconds));

        // sf::Vector2f d = calculateRadiusVector(body1.getPosition(), body2.getPosition());
        // sf::Vector2f force = calculateForce(body1.getMass(), body2.getMass(), d);
        // body1.addForce(-force);
        // body2.addForce(force);

        for (long unsigned i = 0; i < bodies->size(); i++)
        {

            CosmicBody &currentBody = bodies->at(i);
            currentBody.resetForce();
            for (long unsigned j = 0; j < bodies->size(); j++)
            {
                CosmicBody &interactionBody = bodies->at(j);
                if (&currentBody != &interactionBody)
                {
                    sf::Vector2f d = calculateRadiusVector(currentBody.getCenterPosition(), interactionBody.getCenterPosition());
                    sf::Vector2f force = calculateForce(currentBody.getMass(), interactionBody.getMass(), d);
                    currentBody.addForce(force);
                }
            }
            currentBody.functionOverTime(TIME_INTERVAL);
        }

        // for (long unsigned int i = 0; i < bodies->size(); i++)
        // {
        //     for (long unsigned int j = 0; j < bodies->size(); j++)
        //     {
        //         if (&bodies->at(i) != &bodies->at(j))
        //         {
        //             sf::Vector2f d = calculateRadiusVector(bodies->at(i).getCenterPosition(), bodies->at(j).getCenterPosition());
        //             sf::Vector2f force = calculateForce(bodies->at(i).getMass(), bodies->at(j).getMass(), d);
        //             bodies->at(i).addForce(-force);
        //             bodies->at(j).addForce(force);
        //         }
        //         bodies->at(i).functionOverTime(0.00001);
        //         bodies->at(j).functionOverTime(0.00001);
        //     }
        // }

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
