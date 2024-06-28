#pragma once

#include "GameObj/MovablesObj/Enemy.h"
#include <SFML/Graphics.hpp>//maybe go
#include "Animations/Animation.h"

class Robot : public Enemy
{
public:
	Robot(std::unique_ptr<b2World>& world, sf::Color color, sf::Vector2f pos);
	virtual void move(sf::Time time);
	virtual ~Robot() = default;
	void setDir();
	void setKilled(bool state);

private:
	static bool m_registeritRobot;
	bool m_gotKilled = false;
	TexturesManger& m_resources = TexturesManger::instance();
	Direction m_dir = Direction::Left;
	Animation m_animation;
	sf::Clock m_aiTime;
	int m_way;
};