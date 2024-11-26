// Character.h
#ifndef CHARACTER_H
#define CHARACTER_H

#include <SFML/Graphics.hpp>
#include <string>
#include <map>

#include "IPlayerState.h"
#include "PlayerState.h"


class Character : sf::Sprite
{
    public:
        
        Character(float x , float y);

        void update();
        void render(sf::RenderWindow& gl_window);
        void callbackEndingAnimation();

        void handlingEvent(sf::Event& event);
        void setState(State nextState);

    private:
        sf::Sprite* m_sprite;
        sf::Clock m_animationClock;
        sf::Time m_deltaTime;
        int m_statusAction;
        State m_state;
};

#endif