#include <SFML/Graphics.hpp>
#include <iostream>

#include "GameManagers/Application.h"

int main()
{
    Application* app = Application::getInstance();
    app->run();
}
