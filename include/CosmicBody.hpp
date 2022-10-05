#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>
#include <SFML/Graphics/CircleShape.hpp>
#include <iostream>
#include <cmath>

class CosmicBody : public sf::CircleShape
{
public:
    // CosmicBody();
    CosmicBody(float radius, float mass);
    CosmicBody(float radius, float mass, sf::Vector2f position);

    float getMass() const;
    sf::Vector2f getVelocity() const;
    float getSpeed() const;
    sf::Vector2f getAcceleration() const;
    sf::Vector2f getCenterPosition() const;
    sf::Vector2f getForce() const;

    void setSpeed(float speed);
    void setVelocity(sf::Vector2f velocity);
    void setAcceleration(sf::Vector2f acceleration);
    void setCenterPosition(sf::Vector2f position);
    void addForce(sf::Vector2f experiencedForce);
    void resetForce();
    void functionOverTime(float deltaTime);
    void calculatePosition(float deltaTime);
    void calculateVelocity(float deltaTime);
    void calculateAcceleration();

private:
    const float mass;
    sf::Vector2f velocity;
    sf::Vector2f acceleration;
    sf::Vector2f experiencedForce; // experiencedForce aplyied to this body
};