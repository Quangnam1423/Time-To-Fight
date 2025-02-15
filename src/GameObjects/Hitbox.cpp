#include "Hitbox.h"

Hitbox::Hitbox(sf::Vector2f size) : sf::RectangleShape(size)
{
	this->setOrigin((sf::Vector2f)size / 2.f);
	this->setFillColor(sf::Color(0, 0, 0, 0));

	m_velocity = sf::Vector2f(0.f, 0.f);
	m_isAlive = true;
}

Hitbox::~Hitbox()
{
}

void Hitbox::init(sf::Vector2f velocity)
{
	m_velocity = velocity;
}

sf::Vector2f Hitbox::getVelocity()
{
	return m_velocity;
}

void Hitbox::setVelocity(sf::Vector2f velocity)
{
	m_velocity = velocity;
}

TAG Hitbox::getTag()
{
	return m_tag;
}

void Hitbox::setTag(TAG tag)
{
	m_tag = tag;
}

//DIRECTION Hitbox::getDirection()
//{
//	return DIRECTION();
//}
//
//void Hitbox::setDirection(DIRECTION direction)
//{
//	m_direction = direction;
//}

sf::Vector2f Hitbox::getHaftSize()
{
	return (sf::Vector2f)(this->getSize() / 2.f);
}
