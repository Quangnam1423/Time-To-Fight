#ifndef APPLICATION_H
#define APPLICATION_H

#include <SFML/Graphics.hpp>

#include "ApplicationConfig.h"
#include "../GameObjects/player/Character.h"

#include "Singleton.h"

class Application : public Singleton
{
    public:
        
        Application();
        ~Application();
        void run();
    private:
        void init();
        void update();
        void render();
    private:
        sf::RenderWindow* m_window;
        Character* m_character;
        sf::Clock m_clock;

        float m_timer;

};

#endif