#ifndef PLAYERSKILL_H
#define PLAYERSKILL_H

#include <SFML/Graphics.hpp>
#include <iostream>
#include <string>
#include <thread>

class PlayerSkill
{
private:
    std::string m_name;
    float m_damage;
    float m_manaCost;
    float m_countDownTime;
    float currentCoolDown;
    bool isReady;
public:
    //constructor
    PlayerSkill();
    //destructor
    ~PlayerSkill();

    void update(float deltaTime);
    bool useSkill();
};


#endif