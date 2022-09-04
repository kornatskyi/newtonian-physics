#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>
#include <SFML/Graphics/CircleShape.hpp>
#include <iostream>
#include <cmath>

#include "../../include/CosmicBody.hpp"

CosmicBody::CosmicBody(float radius, sf::Vector2f position)
{
    this->setRadius(radius);
    this->position = position;
}
// CosmicBody::CosmicBody(float radius, float mass, float speed)
// {
//     this->setRadius(radius);
//     this->mass = mass;
//     this->speed = speed;
// }

void CosmicBody::setCenterPosition(sf::Vector2f position)
{
    this->position = position;
}
float CosmicBody::getMass()
{
    return this->mass;
}
void CosmicBody::setSpeed(float speed)
{
    this->speed = speed;
}
float CosmicBody::getSpeed()
{
    return this->speed;
}
sf::Vector2f CosmicBody::getVelocity()
{
    return this->velocity;
}
void CosmicBody::setVelocity()
{
    this->velocity = velocity;
}
sf::Vector2f CosmicBody::getAcceleration()
{
    return this->acceleration;
}
void CosmicBody::setAcceleration(sf::Vector2f acceleration)
{
    this->acceleration = acceleration;
}
