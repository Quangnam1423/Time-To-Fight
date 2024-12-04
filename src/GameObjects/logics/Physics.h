#ifndef PHYSICS_H
#define PHYSICS_H

#include <SFML/Graphics.hpp>
#include <iostream>

class Physics
{
private:
    sf::Vector2f m_velocity;


    static float m_groundLevel;
    float m_timer;
    float m_deltaTime;

public:
    Physics(sf::Vector2i velocity);
    ~Physics();
};


#endif