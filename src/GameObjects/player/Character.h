// Character.h
#ifndef CHARACTER_H
#define CHARACTER_H

#include <SFML/Graphics.hpp>
#include <string>
#include <unordered_map>

#include "playerstates/IPlayerState.h"
#include "playerstates/PlayerConfigState.h"


class Character : sf::Sprite
{
public:
    
    Character(sf::Vector2f position);
    ~Character();

    virtual void init();
    virtual void handlingEvent(sf::Event& event);
    
    void update(float deltaTime);
    void render(sf::RenderWindow& gl_window);
    void setState(STATE nextState,  float durationTime);

    void movement(float deltaTime, DIRECTION direction);
    void jump(float deltaTime, DIRECTION direction);
    void shield(float deltaTime, DIRECTION direction);

protected:

    //
    sf::Sprite* m_sprite;
    sf::Clock m_animationClock;
    sf::Time m_deltaTime;
    IPlayerState * m_state;
    sf::Vector2f m_position;

    // get state for 
    std::unordered_map<STATE, IPlayerState* , EnumClassHash> m_stateMap;

    float m_elapsedTime;
    float m_durationTime;

    // character attribute
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
    float m_movementSpeed;
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