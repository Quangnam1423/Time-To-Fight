#ifndef APPLICATION_H
#define APPLICATION_H

#include <SFML/Graphics.hpp>

#include "Singleton.h"

class Application : public Singleton
{
    public:
        void run();
        Application();
        ~Application();
    private:
        void init();
        void update();
        void render();
    private:
        sf::RenderWindow* m_window;
        sf::Clock m_clock;

};

#endif