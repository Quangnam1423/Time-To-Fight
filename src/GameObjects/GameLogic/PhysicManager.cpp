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

void PhysicManager::gravityPerform(float deltaTime)
{
    sf::Vector2f velocity = m_character->getVelocity();
    m_character->setVelocity({ velocity.x,velocity.y  + _GRA * deltaTime});
}

void PhysicManager::handleCollision()
{
    Hitbox* playerHitbox = m_character->getHitbox();
    for (Hitbox* box : m_mapCollider)
    {
        if (box->getGlobalBounds().intersects(playerHitbox->getGlobalBounds()))
        {
            sf::Vector2f playerPosition = playerHitbox->getPosition();
            sf::Vector2f boxPosition = box->getPosition();

            float distanceY = playerPosition.y - boxPosition.y;
            float distanceX = playerPosition.x - boxPosition.x;

            float correctX = playerHitbox->getHaftSize().x + box->getHaftSize().x;
            float correctY = playerHitbox->getHaftSize().y + box->getHaftSize().y;

            float intersectX = correctX - abs(distanceX);
            float intersextY = correctY - abs(distanceY);

            float push = std::min(intersectX, intersextY);

            if (push == intersectX)
            {
                if (distanceX > 0)
                {
                    m_character->move(push, 0.f);
                }
                else
                {
                    m_character->move(-push, 0.f);
                }
                m_character->setVelocity({ 0.f, m_character->getVelocity().y});
            }
            else
            {
                if (distanceY > 0)
                {
                    m_character->move(0.f, push);
                }
                else
                {
                    m_character->move(0.f, -push);
                    m_character->isOnPlatform(true);
                }
                m_character->setVelocity({ m_character->getVelocity().x, 0.f });
            }
        }
    }
}
