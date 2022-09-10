#include "../../include/InformationDisplayer.hpp"

InformationDisplayer::InformationDisplayer()
{
    ///////////////////////////
    // Draw text
    //////////////////////////
    if (!font.loadFromFile("./assets/fonts/MesloLGS NF Regular.ttf"))
    {
        std::cout << "Font not found" << std::endl;
    }
}

void InformationDisplayer::setTextField(std::string name, std::string content)
{
    // Check if the element with this name already exists in dictionary
    if (this->fieldsToDraw.find(name) != this->fieldsToDraw.end())
    {
        this->fieldsToDraw[name].setString(content);
    }
    else
    {
        sf::Text newTextFiled;
        newTextFiled.setFont(font);
        newTextFiled.setCharacterSize(16);
        newTextFiled.setString(content);
        newTextFiled.setFillColor(sf::Color::Red);
        newTextFiled.setPosition(sf::Vector2f(20, 10));
        this->fieldsToDraw[name] = newTextFiled;
    }
}

void InformationDisplayer::deleteTextField(std::string name)
{
    fieldsToDraw.erase(name);
}

void InformationDisplayer::draw(sf::RenderTarget &target, sf::RenderStates states) const
{
    int index = 1;
    for (auto elemnt : fieldsToDraw)
    {
        sf::Vector2f position = elemnt.second.getPosition();
        elemnt.second.setPosition(sf::Vector2f(position.x, position.y * index));
        target.draw(elemnt.second, states);
        index++;
    }
}
