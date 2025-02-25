#ifndef PHYSIC_MANAGER_H
#define PHYSIC_MANAGER_H

#include <SFML/Graphics.hpp>
#include <list>

#define _GRA 1000.f

class Hitbox;
class Character;

class PhysicManager
{
public:
	PhysicManager();
	~PhysicManager();
	void setGravity(float gravity);
	float getGravity() const;
	void setMapCollider(std::list<Hitbox*>& mapCollider);
	void setCharacter(Character* character);
	bool checkCollision();
	void gravityPerform(float deltaTime);
	void handleCollision();
private:
	float m_gravity;
	Character* m_character;
	std::list<Hitbox*> m_mapCollider;
};

#endif