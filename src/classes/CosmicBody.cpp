#include "../../include/CosmicBody.hpp"

CosmicBody::CosmicBody(float radius) : sf::CircleShape(radius)
{
    this->mass = mass;
}

CosmicBody::CosmicBody(float radius, float mass, float spedd)
{
    this->setRadius(radius);
    this->mass = mass;
    this->speed = spedd;
}

void CosmicBody::setCenterPosition(sf::Vector2f position)
{
    float radius = this->getRadius();
    this->setPosition(position.x - radius, position.y - radius);
}

float CosmicBody::getMass()
{
    return mass;
}

void CosmicBody::setSpeed(float spedd)
{
    this->speed = spedd;
}

float CosmicBody::getSpeed()
{
    return speed;
}