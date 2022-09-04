#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>
#include <SFML/Graphics/CircleShape.hpp>
#include <iostream>
#include <cmath>

#include "../include/CosmicBody.hpp"

class SolarSystem : public sf::Drawable, public sf::Transformable
{

public:
    SolarSystem();

    void update();

private:
    float distnceBetweenTwoPoints(sf::Vector2f point1, sf::Vector2f point2);
    float calcForce(float m1, float m2, float r);
    virtual void draw(sf::RenderTarget &target, sf::RenderStates states) const;

    CosmicBody sun;
    CosmicBody planet;
    sf::Vector2f center;
    const float GRAVITY_CONSTANT = 0.00000000006674f;
    sf::Time deltaTime;
    sf::Clock clock;
    sf::Font font;
    sf::Text planetSpeedText;
    sf::Text planetAccselerationText;
    float secondConunt;
    int seconds;
};