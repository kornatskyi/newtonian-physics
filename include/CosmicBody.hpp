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
    CosmicBody(float radius, float mass);
    CosmicBody(float radius, float mass, sf::Vector2f position);

    float getMass();
    void setSpeed(float speed);
    float getSpeed();
    void setVelocity(sf::Vector2f velocity);
    sf::Vector2f getVelocity();
    void setAcceleration(sf::Vector2f acceleration);
    sf::Vector2f getAcceleration();
    void setCenterPosition(sf::Vector2f position);
    sf::Vector2f getCenterPosition();
    void applyForce(sf::Vector2f experiencedForce);
    sf::Vector2f getForce();
    void functionOverTime(float deltaTime);
    void calculatePosition(float deltaTime);
    void calculateVelocity(float deltaTime);
    void calculateAcceleration();

private:
    float mass;
    sf::Vector2f velocity;
    sf::Vector2f acceleration;
    sf::Vector2f experiencedForce; // experiencedForce aplyied to this body
};