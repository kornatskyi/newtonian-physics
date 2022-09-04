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
    CosmicBody(float radius);
    CosmicBody(float radius = 0, float mass = 0, float velocity = 0);
    void setCenterPosition(sf::Vector2f position);
    float getMass();
    void setSpeed(float velocity);
    float getSpeed();

private:
    float mass;
    float speed;
};