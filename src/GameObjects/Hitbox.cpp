#include "Hitbox.h"

Hitbox::Hitbox(sf::Vector2f size) : sf::RectangleShape(size)
{
	this->setOrigin((sf::Vector2f)size / 2.f);
	this->setFillColor(sf::Color(0, 0, 0, 0));

	m_velocity = sf::Vector2f(0.f, 0.f);
	m_isAlive = true;
	m_tag = TAG::NULLOB;
}

Hitbox::~Hitbox()
{
}

void Hitbox::init(sf::Vector2f velocity)
{
	m_velocity = velocity;
}

sf::Vector2f Hitbox::getVelocity() const
{
	return m_velocity;
}

void Hitbox::setVelocity(sf::Vector2f velocity)
{
	m_velocity = velocity;
}

TAG Hitbox::getTag() const
{
	return m_tag;
}

void Hitbox::setTag(TAG tag)
{
	m_tag = tag;
}

sf::Vector2f Hitbox::getHaftSize()
{
	return (sf::Vector2f)(this->getSize() / 2.f);
}