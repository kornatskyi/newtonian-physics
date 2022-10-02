#include "../../include/BodyInformationDisplayer.hpp"
#include "../../include/CosmicBody.hpp"
#include "../../include/FontLoader.hpp"

BodyInformationDisplayer::BodyInformationDisplayer(const CosmicBody &body_, std::string bodyName) : body(body_)
{
  ///////////////////////////
  // Draw text
  //////////////////////////
  if (!font.loadFromFile("./assets/fonts/MesloLGS NF Regular.ttf"))
  {
    std::cout << "Font not found" << std::endl;
  }
  this->bodyName.setFont(font);
  this->bodyName.setCharacterSize(16);
  this->bodyName.setString(bodyName);
  this->bodyName.setFillColor(sf::Color::Red);
  sf::Vector2f pos(40, 40);
  // this->bodyName.setPosition(body.getPosition());
  this->bodyName.setPosition(pos);
}

void BodyInformationDisplayer::update()
{
  sf::Vector2f pos = body.getCenterPosition();
  bodyName.setPosition(pos);
}

void BodyInformationDisplayer::draw(sf::RenderTarget &target, sf::RenderStates states) const
{
  target.draw(bodyName, states);
}
