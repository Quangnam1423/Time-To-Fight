#ifndef SAMURAI_H
#define SAMURAI_H

#include <SFML/Graphics.hpp>
#include <hash_map>

#include "Character.h"
#include "JumpState.h"

class Samurai : public Character
{
public:
    Samurai();
    ~Samurai();

private:
    std::hash_map<State , IPlayerState> m_state_map;
};


#endif