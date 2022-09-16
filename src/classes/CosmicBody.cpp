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

CosmicBody::CosmicBody(float radius, float mass, sf::Vector2f position)
{
    this->setRadius(radius);
    this->mass = mass;
    setCenterPosition(position);
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

void CosmicBody::applyForce(sf::Vector2f experiencedForce)
{
    this->experiencedForce = experiencedForce;
    calculateAcceleration();
}

sf::Vector2f CosmicBody::getForce()
{
    return experiencedForce;
}

void CosmicBody::functionOverTime(float deltaTime)
{
    calculatePosition(deltaTime);
    calculateVelocity(deltaTime);
}

void CosmicBody::calculatePosition(float deltaTime)
{
    sf::Vector2f currentPosition = getPosition();
    float xDisplacement = (velocity.x * deltaTime);
    float yDisplacement = (velocity.y * deltaTime);

    sf::Vector2f newPosition = sf::Vector2f(xDisplacement + currentPosition.x, yDisplacement + currentPosition.y);

    setPosition(newPosition);
}

void CosmicBody::calculateVelocity(float deltaTime)
{

    float deltaVx = (acceleration.x * deltaTime);
    float deltaVy = (acceleration.y * deltaTime);
    float Vx = deltaVx + velocity.x;
    float Vy = deltaVy + velocity.y;

    sf::Vector2f newVelocity = sf::Vector2f(Vx, Vy);
    setVelocity(newVelocity);
}
void CosmicBody::calculateAcceleration()
{
    setAcceleration(sf::Vector2f(experiencedForce.x / mass, experiencedForce.y / mass));
}