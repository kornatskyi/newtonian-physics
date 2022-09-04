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
    float getMass();
    void setSpeed(float speed);
    float getSpeed();
    sf::Vector2f getVelocity();
    void setVelocity(sf::Vector2f velocity);
    sf::Vector2f getAcceleration();
    void setAcceleration(sf::Vector2f acceleration);
    void setCenterPosition(sf::Vector2f position);
    sf::Vector2f getCenterPosition();

private:
    float mass;
    sf::Vector2f velocity;
    sf::Vector2f acceleration;
};