#include "PhysicManager.h"

#include "../Hitbox.h"
#include "../player/Samurai.h"

PhysicManager::PhysicManager()
{
    m_character = nullptr;
    m_gravity = 0.f;
}

PhysicManager::~PhysicManager()
{
    if (m_character != nullptr)
        m_character = nullptr;
    for (Hitbox* hitbox : m_mapCollider)
    {
        hitbox = nullptr;
    }
    m_mapCollider.clear();
}

void PhysicManager::setGravity(float gravity)
{
    m_gravity = gravity;
}

float PhysicManager::getGravity() const
{
    return m_gravity;
}

void PhysicManager::setMapCollider(std::list<Hitbox*>& mapCollider)
{
    m_mapCollider = mapCollider;
}

void PhysicManager::setCharacter(Character* character)
{
    m_character = character;
}

bool PhysicManager::checkCollision()
{
    Hitbox* playerHitbox = m_character->getHitbox();
    for (Hitbox* mapHitbox : m_mapCollider)
    {
        if (playerHitbox->getGlobalBounds().intersects(mapHitbox->getGlobalBounds()))
        {
            return true;
        }
    }
    return false;
}
