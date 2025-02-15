#ifndef HITBOX_H
#define HITBOX_H

#include <SFML/Graphics.hpp>

enum class TAG {
	PLAYER,
	MAP,

};

//enum class direction
//{
//	dnull,
//	right,
//	above,
//	below,
//	right,
//	left,
//	inside,
//	goin
//};

class Hitbox : public sf::RectangleShape
{
public:
	Hitbox(sf::Vector2f size);
	~Hitbox();

	void init(sf::Vector2f velocity);

	sf::Vector2f getVelocity();
	void setVelocity(sf::Vector2f velocity);

	TAG getTag();
	void setTag(TAG tag);

	//DIRECTION getDirection();
	//void setDirection(DIRECTION direction);

	sf::Vector2f getHaftSize();
private:
	sf::Vector2f m_velocity;
	bool m_isAlive;
	enum TAG m_tag;
};

#endif