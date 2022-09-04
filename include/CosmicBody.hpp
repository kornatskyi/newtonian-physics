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
    CosmicBody(float radius, sf::Vector2f position);
    // CosmicBody(float radius, float mass, float speed);
    void setCenterPosition(sf::Vector2f position);
    float getMass();
    void setSpeed(float speed);
    float getSpeed();
    sf::Vector2f getVelocity();
    void setVelocity();
    sf::Vector2f getAcceleration();
    void setAcceleration(sf::Vector2f acceleration);

private:
    float mass;
    float speed;
    sf::Vector2f velocity;
    sf::Vector2f acceleration;
    sf::Vector2f position;
};