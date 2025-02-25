#ifndef HITBOX_H
#define HITBOX_H

#include <SFML/Graphics.hpp>
#include "GameDefinition.h"

class Hitbox : public sf::RectangleShape
{
public:
	Hitbox(sf::Vector2f size);
	~Hitbox();

	void init(sf::Vector2f velocity);

	sf::Vector2f getVelocity() const;
	void setVelocity(sf::Vector2f velocity);

	TAG getTag() const;
	void setTag(TAG tag);

	void setDirection(DIRECTION direction);
	DIRECTION getDirection() const;

	sf::Vector2f getHaftSize();
private:
	sf::Vector2f m_velocity;
	bool m_isAlive;
	enum TAG m_tag;
	enum DIRECTION m_direction;
};

#endif