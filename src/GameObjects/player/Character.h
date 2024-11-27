// Character.h
#ifndef CHARACTER_H
#define CHARACTER_H

#include <SFML/Graphics.hpp>
#include <string>
#include <map>
#include <unordered_map>

#include "IPlayerState.h"
#include "PlayerConfigState.h"


class Character : sf::Sprite
{
    public:
        
        Character(float x , float y);
        ~Character();

        void update();
        void render(sf::RenderWindow& gl_window);
        void callbackEndingAnimation();

        void handlingEvent(sf::Event& event);
        void setState(State nextState);

    private:
        sf::Sprite* m_sprite;
        sf::Clock m_animationClock;
        sf::Time m_deltaTime;
        IPlayerState * m_state;

        // get state for 
        std::unordered_map<State, IPlayerState* , EnumClassHash> m_stateMap;
};

#endif