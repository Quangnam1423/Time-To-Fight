#ifndef SAMURAI_H
#define SAMURAI_H

#include <SFML/Graphics.hpp>
#include <hash_map>
#include <unordered_map>

#include "Character.h"
#include "JumpState.h"

#include "../logics/Collision.h"
#include "../logics/Physics.h"

class Samurai : public Character
{
public:
    Samurai(sf::Vector2f position);
    ~Samurai();
    void handlingEvent(sf::Event& event) override;
    void init() override;
private:
    sf::Vector2f m_position;
    bool m_onLeft;
    bool m_onRight;
    bool m_deadMode;

    //core attributes
    float m_healthPoint;
    float m_manaPoint;
    float m_strength;
    float m_dexterity;
    float m_agility;
    float m_constitution;


    // combat stats
    float m_movementSpped;
    float m_healing;
    float m_physicalDamage;
    float m_magicDamage;
    float m_armor;
    float m_magicResistance;
    float m_evasion;
    float m_block;

    //recovery and Resource
    float m_healthRegen;
    float m_manaRegen;
    float m_energyRegen;
};


#endif