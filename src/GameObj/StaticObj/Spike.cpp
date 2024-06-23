#include "GameObj/StaticObj/Spike.h"

bool Spike::m_registerit = FactoryFixed::registeritFixed(ObjectTypes::SPIKE_T, 
	[](std::unique_ptr<b2World>& world, sf::Color color, sf::Vector2f position) -> std::unique_ptr<Static>
	{
		return std::make_unique<Spike>(world, color, position);

	});

bool Spike::m_registerit_down = FactoryFixed::registeritFixed(ObjectTypes::SPIKE_T,
	[](std::unique_ptr<b2World>& world, sf::Color color, sf::Vector2f position) -> std::unique_ptr<Static>
	{
		return std::make_unique<Spike>(world, color, position);

	});

bool Spike::m_registerit_long = FactoryFixed::registeritFixed(ObjectTypes::SPIKE_T,
	[](std::unique_ptr<b2World>& world, sf::Color color, sf::Vector2f position) -> std::unique_ptr<Static>
	{
		return std::make_unique<Spike>(world, color, position);

	});

Spike::Spike(std::unique_ptr<b2World>& world, sf::Color color, sf::Vector2f position)
	: Static(world, color, position, b2_staticBody)
{
	if (color == SPIKE_C)
	{
		setTexture(2);
	}
	else if (color == DOWN_SPIKE_C)
	{
	
		setTexture(7);
	}
	else if (color == AIR_SPIKE_C)
	{
		setTexture(8);
		setSize(2 * 60, 2 * 60);
		setFillColor(sf::Color(102, 0, 200, 180));
	}
	else if (color == LONG_SPIKE_C)
	{
		setTexture(15);
		setSize(8*60, 60);
	}
	else if (color == DOWN_LONG_SPIKE_C)
	{
		setTexture(16);
		setSize(8 * 60, 60);
	}
}