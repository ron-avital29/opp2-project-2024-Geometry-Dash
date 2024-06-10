#pragma once

#include "Object.h"

class Static : public Object
{
public:
	Static(std::unique_ptr<b2World>& world, sf::Texture& texture, sf::Color color, sf::Vector2f position)
		: Object(world, texture, color, position) {};
	virtual void makeVirtural() = 0;
	virtual ~Static() =default;
};