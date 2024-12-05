#ifndef SAMURAI_H
#define SAMURAI_H

#include <SFML/Graphics.hpp>
#include <unordered_map>

#include "Character.h"

// #include "../logics/Collision.h"
// #include "../logics/Physics.h"
//#include "PlayerSkill.h"

class Samurai : public Character
{
public:
    Samurai(sf::Vector2f position);
    ~Samurai();
    void handlingEvent(sf::Event& event) override;
    void init() override;
    void attack();
    void combo_1();
    void combo_2();
};


#endif