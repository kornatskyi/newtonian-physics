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

void InformationDisplayer::setTextField(std::string name, std::string content, sf::Vector2f position)
{
    // Check if the element with this name already exists in dictionary
    if (this->movbleFieldsToDraw.find(name) != this->movbleFieldsToDraw.end())
    {
        this->movbleFieldsToDraw[name].setPosition(sf::Vector2f(position.x + 5, position.y + 10));
        this->movbleFieldsToDraw[name].setString(content);
    }
    else
    {
        sf::Text newTextFiled;
        newTextFiled.setFont(font);
        newTextFiled.setCharacterSize(16);
        newTextFiled.setString(content);
        newTextFiled.setFillColor(sf::Color::Green);
        this->movbleFieldsToDraw[name].setPosition(position);
        this->movbleFieldsToDraw[name] = newTextFiled;
    }
}

void InformationDisplayer::deleteTextField(std::string name)
{
    fieldsToDraw.erase(name);
    movbleFieldsToDraw.erase(name);
}

void InformationDisplayer::draw(sf::RenderTarget &target, sf::RenderStates states) const
{
    int index = 1;
    for (auto elemnt : fieldsToDraw)
    {
        sf::Vector2f position = elemnt.second.getPosition();
        elemnt.second.setPosition(sf::Vector2f(position.x, (position.y + 5) * index));
        target.draw(elemnt.second, states);
        index++;
    }
    index = 1;
    for (auto elemnt : movbleFieldsToDraw)
    {
        target.draw(elemnt.second, states);
        index++;
    }
}

/// @brief Converts number to string
/// @param number
/// @return
std::string InformationDisplayer::numberToString(double number)
{
    std::stringstream stream;
    stream << std::fixed << std::setprecision(24) << number;
    std::string s = stream.str();
    return s;
}
std::string InformationDisplayer::numberToString(float number)
{
    return numberToString((double)number);
}
