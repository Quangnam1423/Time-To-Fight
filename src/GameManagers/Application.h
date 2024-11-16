#ifndef APPLICATION_H
#define APPLICATION_H

#include <SFML/Graphics.hpp>

class Application
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

};

#endif