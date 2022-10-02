#pragma once
#include "CosmicBody.hpp"

class BodyInformationDisplayer : public sf::Drawable, public sf::Transformable
{

public:
  BodyInformationDisplayer(const CosmicBody &body);
  BodyInformationDisplayer(const CosmicBody &body, std::string bodyName);

  void update();

private:
  virtual void draw(sf::RenderTarget &target, sf::RenderStates states) const;
  const CosmicBody &body;
  sf::Font font;
  sf::Text bodyName;
};