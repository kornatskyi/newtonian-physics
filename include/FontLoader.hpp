#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>
#include <SFML/Graphics/CircleShape.hpp>
#include <iostream>

sf::Font loadFont()
{
  sf::Font font;
  if (!font.loadFromFile("./assets/fonts/MesloLGS NF Regular.ttf"))
  {
    throw std::runtime_error("Font file './assets/fonts/MesloLGS NF Regular.ttf' not found!");
  }
  return font;
}