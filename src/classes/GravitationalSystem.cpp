#include "../../include/CosmicBody.hpp"
#include "../../include/GravitationalSystem.hpp"
#include "../../include/data/SolarSystemBodiesData.hpp"
#include "../../include/BodyInformationDisplayer.hpp"

const double SIZE_SCALE_FACTOR = -6.5;
const double SUN_SIZE_SCALE_FACTOR = -8;

const double TIME_INTERVAL = 0.00001;

GravitationalSystem::GravitationalSystem(sf::Vector2f center)
{
    CosmicBody *const sun = new CosmicBody(tenExp(sunData.radius, SUN_SIZE_SCALE_FACTOR),
                                           tenExp(sunData.mass),
                                           center);
    CosmicBody *const mercury = new CosmicBody(tenExp(mercuryData.radius, SIZE_SCALE_FACTOR),
                                               tenExp(mercuryData.mass),
                                               sf::Vector2f(center.x, center.y - tenExp(mercuryData.orbitalRadius)));
    CosmicBody *const venus = new CosmicBody(tenExp(venusData.radius, SIZE_SCALE_FACTOR),
                                             tenExp(venusData.mass),
                                             sf::Vector2f(center.x, center.y - tenExp(venusData.orbitalRadius)));
    CosmicBody *const earth = new CosmicBody(tenExp(earthData.radius, SIZE_SCALE_FACTOR),
                                             tenExp(earthData.mass),
                                             sf::Vector2f(center.x, center.y - tenExp(earthData.orbitalRadius)));
    CosmicBody *const mars = new CosmicBody(tenExp(marsData.radius, SIZE_SCALE_FACTOR),
                                            tenExp(marsData.mass),
                                            sf::Vector2f(center.x, center.y - tenExp(marsData.orbitalRadius)));
    CosmicBody *const jupiter = new CosmicBody(tenExp(jupiterData.radius, SIZE_SCALE_FACTOR),
                                               tenExp(jupiterData.mass),
                                               sf::Vector2f(center.x, center.y - tenExp(jupiterData.orbitalRadius)));
    CosmicBody *const saturn = new CosmicBody(tenExp(saturnData.radius, SIZE_SCALE_FACTOR),
                                              tenExp(saturnData.mass),
                                              sf::Vector2f(center.x, center.y - tenExp(saturnData.orbitalRadius)));
    CosmicBody *const uranus = new CosmicBody(tenExp(uranusData.radius, SIZE_SCALE_FACTOR),
                                              tenExp(uranusData.mass),
                                              sf::Vector2f(center.x, center.y - tenExp(uranusData.orbitalRadius)));
    CosmicBody *const neptun = new CosmicBody(tenExp(neptunData.radius, SIZE_SCALE_FACTOR),
                                              tenExp(neptunData.mass),
                                              sf::Vector2f(center.x, center.y - tenExp(neptunData.orbitalRadius)));

    sun->setFillColor(sf::Color::Yellow);

    mercury->setVelocity(sf::Vector2f(orbitalSpeed(mercuryData.siderealPeriod, mercuryData.orbitalRadius), 0));
    mercury->setFillColor(sf::Color::White);

    venus->setVelocity(sf::Vector2f(orbitalSpeed(venusData.siderealPeriod, venusData.orbitalRadius), 0));
    venus->setFillColor(sf::Color::White);

    earth->setVelocity(sf::Vector2f(orbitalSpeed(earthData.siderealPeriod, earthData.orbitalRadius), 0));
    earth->setFillColor(sf::Color::White);

    mars->setVelocity(sf::Vector2f(orbitalSpeed(marsData.siderealPeriod, marsData.orbitalRadius), 0));
    mars->setFillColor(sf::Color::White);

    jupiter->setVelocity(sf::Vector2f(orbitalSpeed(jupiterData.siderealPeriod, jupiterData.orbitalRadius), 0));
    jupiter->setFillColor(sf::Color::White);

    saturn->setVelocity(sf::Vector2f(orbitalSpeed(saturnData.siderealPeriod, saturnData.orbitalRadius), 0));
    saturn->setFillColor(sf::Color::White);

    uranus->setVelocity(sf::Vector2f(orbitalSpeed(uranusData.siderealPeriod, uranusData.orbitalRadius), 0));
    uranus->setFillColor(sf::Color::White);

    neptun->setVelocity(sf::Vector2f(orbitalSpeed(neptunData.siderealPeriod, neptunData.orbitalRadius), 0));
    neptun->setFillColor(sf::Color::White);

    // Create info displayers
    BodyInformationDisplayer *sunInfoDispl = new BodyInformationDisplayer((*sun), "Sun");
    bodyInfoDisplayers.push_back(sunInfoDispl);
    BodyInformationDisplayer *mercuryInfoDispl = new BodyInformationDisplayer((*mercury), "Mercury");
    bodyInfoDisplayers.push_back(mercuryInfoDispl);
    BodyInformationDisplayer *venusInfoDispl = new BodyInformationDisplayer((*venus), "Venus");
    bodyInfoDisplayers.push_back(venusInfoDispl);
    BodyInformationDisplayer *earthInfoDispl = new BodyInformationDisplayer((*earth), "Earth");
    bodyInfoDisplayers.push_back(earthInfoDispl);
    BodyInformationDisplayer *marsInfoDispl = new BodyInformationDisplayer((*mars), "Mars");
    bodyInfoDisplayers.push_back(marsInfoDispl);
    BodyInformationDisplayer *jupiterInfoDispl = new BodyInformationDisplayer((*jupiter), "Jupiter");
    bodyInfoDisplayers.push_back(jupiterInfoDispl);
    BodyInformationDisplayer *saturnInfoDispl = new BodyInformationDisplayer((*saturn), "Saturn");
    bodyInfoDisplayers.push_back(saturnInfoDispl);
    BodyInformationDisplayer *uranusInfoDispl = new BodyInformationDisplayer((*uranus), "Uranus");
    bodyInfoDisplayers.push_back(uranusInfoDispl);
    BodyInformationDisplayer *neptunInfoDispl = new BodyInformationDisplayer((*neptun), "Neptun");
    bodyInfoDisplayers.push_back(neptunInfoDispl);

    this->center = center;
    counter = 0;

    secondConunt = 0.0f;
    seconds = 0.f;

    bodies = new std::vector<CosmicBody *>();
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
    if (counter > 100) // count 100 update loop iterations intead of using time class
    {

        deltaTime = clock.getElapsedTime();
        clock.restart();

        seconds += deltaTime.asSeconds();
        informationDisplayer.setTextField("Seconds", "Seconds:" + std::to_string(seconds));

        for (long unsigned i = 0; i < bodies->size(); i++)
        {
            CosmicBody &currentBody = *bodies->at(i);
            currentBody.resetForce();
            for (long unsigned j = 0; j < bodies->size(); j++)
            {
                CosmicBody &interactionBody = *bodies->at(j);
                if (&currentBody != &interactionBody)
                {
                    sf::Vector2f d = calculateRadiusVector(currentBody.getCenterPosition(), interactionBody.getCenterPosition());
                    sf::Vector2f force = calculateForce(currentBody.getMass(), interactionBody.getMass(), d);
                    currentBody.addForce(force);
                }
            }
            currentBody.functionOverTime(TIME_INTERVAL);
        }

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
    // Draw all information displayers
    target.draw(informationDisplayer, states);
    for (auto displ : bodyInfoDisplayers)
    {
        displ->update();
        target.draw(*displ, states);
    }

    // Draw all bodies
    for (long unsigned int i = 0; i < bodies->size(); i++)
    {
        target.draw(*bodies->at(i), states);
    }
}

void GravitationalSystem::setCenter(sf::Vector2f center)
{
    this->center = center;
}
