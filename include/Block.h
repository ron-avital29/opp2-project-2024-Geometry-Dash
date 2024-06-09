#pragma once

#include "Static.h"

class Block : public Static
{
public:
	Block(std::unique_ptr<b2World>& world, sf::Texture& texture, sf::Color color, sf::Vector2f position)
		: Static(world, texture, color, position) {};

	~Block() override {}

	//virtual void stam() {}

private:
	
};