#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>
#include <SFML/Graphics/CircleShape.hpp>
#include <iostream>
#include <cmath>

#include "../include/CosmicBody.hpp"

class GravitationalSystem : public sf::Drawable, public sf::Transformable
{

public:
    GravitationalSystem(sf::Vector2f center);

    void update();

    void setCenter(sf::Vector2f center);

private:
    float distnceBetweenTwoPoints(sf::Vector2f point1, sf::Vector2f point2);
    float calcForce(float m1, float m2, float r);
    virtual void draw(sf::RenderTarget &target, sf::RenderStates states) const;
    void setPositionOnA1DementionalPlot(float coordinate, CosmicBody &body);

    CosmicBody body1;
    CosmicBody body2;
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