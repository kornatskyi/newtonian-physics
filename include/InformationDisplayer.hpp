#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>
#include <SFML/Graphics/CircleShape.hpp>
#include <iostream>
#include <sstream>
#include <iomanip>

class InformationDisplayer : public sf::Drawable, public sf::Transformable
{
public:
    InformationDisplayer();
    void setTextField(std::string name, std::string content);
    void setTextField(std::string name, std::string content, sf::Vector2f position);

    void deleteTextField(std::string name);
    static std::string numberToString(double number);
    static std::string numberToString(float number);

private:
    virtual void draw(sf::RenderTarget &target, sf::RenderStates states) const;

    // std::vector<sf::Text> fieldsToDraw;
    std::map<std::string, sf::Text> fieldsToDraw;
    std::map<std::string, sf::Text> movbleFieldsToDraw;
    sf::Font font;
};