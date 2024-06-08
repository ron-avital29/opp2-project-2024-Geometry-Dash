#include "Object.h"
#include <iostream>

Object::Object()
{
	m_shape.setSize(sf::Vector2f(60, 60));
}

Object::Object(std::unique_ptr<b2World>& world, sf::Texture& texture, sf::Color color, sf::Vector2f position)
	:  m_color(color), m_position(position)
{
	m_shape.setSize(sf::Vector2f(60, 60));
	m_shape.setTexture(&texture);
	m_shape.setPosition(position);

	initBox(world);
}

void Object::initBox(std::unique_ptr<b2World>& world)
{
	m_bodyDef.type = b2_dynamicBody;
	m_bodyDef.position.Set(m_shape.getPosition().x, m_shape.getPosition().y);
	m_box = world->CreateBody(&m_bodyDef);

	m_boxShape.SetAsBox(1.0f, 1.0f);
	m_fixtureDef.shape = &m_boxShape;
	m_fixtureDef.density = 1.0f;
	m_fixtureDef.friction = 0.5f;
	m_box->CreateFixture(&m_fixtureDef);

	m_boxPos = m_box->GetPosition();
	m_angle = m_box->GetAngle();
}
sf::Vector2f Object::getPosition() const
{
	return m_shape.getPosition();
}

sf::Color Object::getColor() const
{
	return m_color;
}

void Object::setPosition(sf::Vector2f position)
{
	m_shape.setPosition(position);
	m_position = position;

	m_bodyDef.position.Set(m_position.x, m_position.y);
}

void Object::setColor(sf::Color color)
{
	m_color = color;
}

void Object::setTexture(sf::Texture& texture)
{
	m_shape.setTexture(&texture);
}

void Object::setSize(int x, int y)
{
	m_shape.setSize(sf::Vector2f(x, y));
}

void Object::draw(sf::RenderWindow& window)
{
	window.draw(m_shape);
}

void Object::updatePos(sf::Time time)
{
	m_boxPos = m_box->GetPosition();
	m_angle = m_box->GetAngle();
	m_shape.setPosition(m_boxPos.x, m_boxPos.y);
	m_shape.setRotation(m_angle);

	float constantVelocityX = 950.0f;
	m_box->SetTransform(m_box->GetPosition() + b2Vec2(constantVelocityX * time.asSeconds(), 0.0f), m_box->GetAngle());
	m_shape.setPosition(m_box->GetPosition().x, m_box->GetPosition().y);
}