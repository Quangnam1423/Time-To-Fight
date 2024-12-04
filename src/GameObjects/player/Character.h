// Character.h
#ifndef CHARACTER_H
#define CHARACTER_H

#include <SFML/Graphics.hpp>
#include <string>
#include <unordered_map>

#include "IPlayerState.h"
#include "PlayerConfigState.h"


class Character : sf::Sprite
{
    public:
        
        Character();
        ~Character() = default;

        virtual void init();
        virtual void handlingEvent(sf::Event& event);
        
        void update(float deltaTime);
        void render(sf::RenderWindow& gl_window);
        void setState(State nextState);

    protected:
        sf::Sprite* m_sprite;
        sf::Clock m_animationClock;
        sf::Time m_deltaTime;
        IPlayerState * m_state;

        // get state for 
        std::unordered_map<State, IPlayerState* , EnumClassHash> m_stateMap;
};

#endif