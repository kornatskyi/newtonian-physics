#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>
#include <SFML/Graphics/CircleShape.hpp>
#include <iostream>

class InformationDisplayer : public sf::Drawable, public sf::Transformable
{
public:
    InformationDisplayer();
    void setTextField(std::string name, std::string content);
    void deleteTextField(std::string name);

private:
    virtual void draw(sf::RenderTarget &target, sf::RenderStates states) const;

    // std::vector<sf::Text> fieldsToDraw;
    std::map<std::string, sf::Text> fieldsToDraw;
    sf::Font font;
};