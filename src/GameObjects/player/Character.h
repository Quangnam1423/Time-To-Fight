/*
MIT License

Copyright (c) 2024 Quangnam1423

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all
copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
SOFTWARE.
*/

// Character.h
#ifndef CHARACTER_H
#define CHARACTER_H

#include <SFML/Graphics.hpp>
#include <string>
#include <unordered_map>

#include "playerstates/IPlayerState.h"
#include "playerstates/PlayerConfigState.h"

class Hitbox;


class Character : sf::Sprite
{
public:
    
    Character(sf::Vector2f position);
    ~Character();

    virtual void init();
    virtual void handleEvent(sf::Event& event);
    
    void update(float deltaTime);
    void render(sf::RenderWindow& gl_window);
    void setState(STATE nextState,  float durationTime);

    void movement(float deltaTime, PLAYER_DIRECTION direction);
    void jump(float deltaTime, PLAYER_DIRECTION direction);
    void shield(float deltaTime, PLAYER_DIRECTION direction);
    void setHitbox(Hitbox* hitbox);
    Hitbox* getHitbox();
    sf::Vector2f getPosition();
    sf::Vector2f getSize();
protected:

    //
    sf::Sprite* m_sprite;
    sf::Clock m_animationClock;
    sf::Time m_deltaTime;
    Hitbox* m_hitbox;
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