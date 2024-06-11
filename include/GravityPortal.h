#include "Portal.h"

class GravityPortal : public Portal
{
public:
	GravityPortal(std::unique_ptr<b2World>& world, sf::Texture& texture, sf::Color color, sf::Vector2f position)
		: Portal(world, texture, color, position) {};
};