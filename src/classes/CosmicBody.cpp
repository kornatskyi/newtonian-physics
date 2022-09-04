#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>
#include <SFML/Graphics/CircleShape.hpp>
#include <iostream>
#include <cmath>

#include "../../include/CosmicBody.hpp"

CosmicBody::CosmicBody(float radius, float mass)
{
    this->setRadius(radius);
    this->mass = mass;
}

void CosmicBody::setCenterPosition(sf::Vector2f newPosition)
{
    this->setPosition(sf::Vector2f(newPosition.x - this->getRadius(), newPosition.y - this->getRadius()));
}
sf::Vector2f CosmicBody::getCenterPosition()
{
    return sf::Vector2f(this->getPosition().x + this->getRadius(), this->getPosition().y + this->getRadius());
}

float CosmicBody::getMass()
{
    return this->mass;
}
sf::Vector2f CosmicBody::getVelocity()
{
    return this->velocity;
}
void CosmicBody::setVelocity(sf::Vector2f velocity)
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
