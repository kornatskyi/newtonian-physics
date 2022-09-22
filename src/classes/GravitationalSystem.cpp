#include "../../include/CosmicBody.hpp"
#include "../../include/GravitationalSystem.hpp"

double yearsToSeconds(double years)
{
    return years * 365.25 * 24 * 60 * 60;
}

const double SUN_RADIUS_m = 695508000;
const double SUN_MASS_kg = 1989100000.0 * pow(10, 21);

const double MERCURY_RADIUS_m = 2439400;
const double MERCURY_MASS_kg = 330.11 * pow(10, 21);
const double MERCURY_SIDEREAL_PERIOD_s = yearsToSeconds(0.240846);
const double MERCURY_ORBITAL_RADIUS_m = 57900000000;

const double VENUS_RADIUS_m = 6052000;
const double VENUS_MASS_kg = 4867.5 * pow(10, 21);
const double VENUS_SIDEREAL_PERIOD_s = yearsToSeconds(0.615);
const double VENUS_ORBITAL_RADIUS_m = 108200000000;

const double EARTH_RADIUS_m = 6371000;
const double EARTH_MASS_kg = 5972.4 * pow(10, 21);
const double EARTH_SIDEREAL_PERIOD_s = yearsToSeconds(1);
const double EARTH_ORBITAL_RADIUS_m = 149600000000;

const double MARS_RADIUS_m = 3389500;
const double MARS_MASS_kg = 641.71 * pow(10, 21);
const double MARS_SIDEREAL_PERIOD_s = yearsToSeconds(1.881);
const double MARS_ORBITAL_RADIUS_m = 227900000000;

const double JUPITER_RADIUS_m = 69911000;
const double JUPITER_MASS_kg = 1898187 * pow(10, 21);
const double JUPITER_SIDEREAL_PERIOD_s = yearsToSeconds(11.86);
const double JUPITER_ORBITAL_RADIUS_m = 778600000000;

const double SATURN_RADIUS_m = 58232000;
const double SATURN_MASS_kg = 568317 * pow(10, 21);
const double SATURN_SIDEREAL_PERIOD_s = yearsToSeconds(29.46);
const double SATURN_ORBITAL_RADIUS_m = 1433500000000;

const double URANUS_RADIUS_m = 25362000;
const double URANUS_MASS_kg = 86813 * pow(10, 21);
const double URANUS_SIDEREAL_PERIOD_s = yearsToSeconds(84.01);
const double URANUS_ORBITAL_RADIUS_m = 2872500000000;

const double NEPTUN_RADIUS_m = 24622000;
const double NEPTUN_MASS_kg = 102413 * pow(10, 21);
const double NEPTUN_SIDEREAL_PERIOD_s = yearsToSeconds(164.8);
const double NEPTUN_ORBITAL_RADIUS_m = 4495100000000;

// Mutiply a number by ten to the power. By default power is -9
double multiplyByTenToThePower(double number, double power = -9)
{
    return number * pow(10, power);
}

double orbitalSpeed(double period, double orbitRadius)
{
    return (orbitRadius * 2 * 3.14) / period;
}

const double SIZE_SCALE_FACTOR = -6.5;

const double TIME_INTERVAL = 0.00001;

GravitationalSystem::GravitationalSystem(sf::Vector2f center)
{
    CosmicBody
        sun(multiplyByTenToThePower(SUN_RADIUS_m, SIZE_SCALE_FACTOR), multiplyByTenToThePower(SUN_MASS_kg), center),
        mercury(multiplyByTenToThePower(MERCURY_RADIUS_m, SIZE_SCALE_FACTOR),
                multiplyByTenToThePower(MERCURY_MASS_kg),
                sf::Vector2f(center.x, center.y - multiplyByTenToThePower(MERCURY_ORBITAL_RADIUS_m))),
        venus(multiplyByTenToThePower(VENUS_RADIUS_m, SIZE_SCALE_FACTOR),
              multiplyByTenToThePower(VENUS_MASS_kg),
              sf::Vector2f(center.x, center.y - multiplyByTenToThePower(VENUS_ORBITAL_RADIUS_m))),
        earth(multiplyByTenToThePower(EARTH_RADIUS_m, SIZE_SCALE_FACTOR),
              multiplyByTenToThePower(EARTH_MASS_kg),
              sf::Vector2f(center.x, center.y - multiplyByTenToThePower(EARTH_ORBITAL_RADIUS_m))),
        mars(multiplyByTenToThePower(MARS_RADIUS_m, SIZE_SCALE_FACTOR),
             multiplyByTenToThePower(MARS_MASS_kg),
             sf::Vector2f(center.x, center.y - multiplyByTenToThePower(MARS_ORBITAL_RADIUS_m))),
        jupiter(multiplyByTenToThePower(JUPITER_RADIUS_m, SIZE_SCALE_FACTOR),
                multiplyByTenToThePower(JUPITER_MASS_kg),
                sf::Vector2f(center.x, center.y - multiplyByTenToThePower(JUPITER_ORBITAL_RADIUS_m))),
        saturn(multiplyByTenToThePower(SATURN_RADIUS_m, SIZE_SCALE_FACTOR),
               multiplyByTenToThePower(SATURN_MASS_kg),
               sf::Vector2f(center.x, center.y - multiplyByTenToThePower(SATURN_ORBITAL_RADIUS_m))),
        uranus(multiplyByTenToThePower(URANUS_RADIUS_m, SIZE_SCALE_FACTOR),
               multiplyByTenToThePower(URANUS_MASS_kg),
               sf::Vector2f(center.x, center.y - multiplyByTenToThePower(URANUS_ORBITAL_RADIUS_m))),
        neptun(multiplyByTenToThePower(NEPTUN_RADIUS_m, SIZE_SCALE_FACTOR),
               multiplyByTenToThePower(NEPTUN_MASS_kg),
               sf::Vector2f(center.x, center.y - multiplyByTenToThePower(NEPTUN_ORBITAL_RADIUS_m)));

    sun.setFillColor(sf::Color::Yellow);

    mercury.setVelocity(sf::Vector2f(orbitalSpeed(MERCURY_SIDEREAL_PERIOD_s, MERCURY_ORBITAL_RADIUS_m), 0));
    mercury.setFillColor(sf::Color::Red);

    venus.setVelocity(sf::Vector2f(-orbitalSpeed(VENUS_SIDEREAL_PERIOD_s, VENUS_ORBITAL_RADIUS_m), 0));
    venus.setFillColor(sf::Color::Black);

    earth.setVelocity(sf::Vector2f(orbitalSpeed(EARTH_SIDEREAL_PERIOD_s, EARTH_ORBITAL_RADIUS_m), 0));
    earth.setFillColor(sf::Color::Blue);

    mars.setVelocity(sf::Vector2f(-orbitalSpeed(MARS_SIDEREAL_PERIOD_s, MARS_ORBITAL_RADIUS_m), 0));
    mars.setFillColor(sf::Color::Red);

    jupiter.setVelocity(sf::Vector2f(orbitalSpeed(JUPITER_SIDEREAL_PERIOD_s, JUPITER_ORBITAL_RADIUS_m), 0));
    jupiter.setFillColor(sf::Color::Red);

    saturn.setVelocity(sf::Vector2f(-orbitalSpeed(SATURN_SIDEREAL_PERIOD_s, SATURN_ORBITAL_RADIUS_m), 0));
    saturn.setFillColor(sf::Color::Red);

    uranus.setVelocity(sf::Vector2f(orbitalSpeed(URANUS_SIDEREAL_PERIOD_s, URANUS_ORBITAL_RADIUS_m), 0));
    uranus.setFillColor(sf::Color::Red);

    neptun.setVelocity(sf::Vector2f(-orbitalSpeed(NEPTUN_SIDEREAL_PERIOD_s, NEPTUN_ORBITAL_RADIUS_m), 0));
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
