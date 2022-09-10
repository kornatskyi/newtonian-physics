#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>
#include <SFML/Graphics/CircleShape.hpp>
#include <iostream>
#include <cmath>

#include "CosmicBody.hpp"
#include "InformationDisplayer.hpp"

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

    ////////////////////////////////////////////////////////////
    /// @brief Sets possition in respect to the one dimensional axis. Relativly to its center (usualy it's the midle of the screen)
    /// @param coordinate is the number on the axis where position of a body will be set
    /// @param body reference to the body which position need to be set on the axis
    ////////////////////////////////////////////////////////////
    void setPositionOnA1DimensionalPlot(float coordinate, CosmicBody &body);

    float getPositionOnA1DimensionalPlot(CosmicBody &body);
    float deltaDisplacement(float speed, float time);

    CosmicBody body1;
    CosmicBody body2;
    sf::Vector2f center;
    const float GRAVITY_CONSTANT = 0.00000000006674f;
    sf::Time deltaTime;
    sf::Clock clock;
    sf::Text planetSpeedText;
    sf::Text planetAccselerationText;
    float secondConunt;
    float seconds;
    ::InformationDisplayer informationDisplayer;
};