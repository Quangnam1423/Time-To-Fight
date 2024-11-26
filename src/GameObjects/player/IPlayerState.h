#ifndef IPLAYERSTATE_H
#define IPLAYERSTATE_H

#include <SFML/Graphics.hpp>
#include "PlayerState.h"

class IPlayerState
{
public:
    //IPlayerState(const std::string& animationPath , sf::Vector2i frameCount , float timeFrame);
    virtual ~IPlayerState() = default;
    virtual void update(float deltaTime);
    virtual sf::IntRect getCurrentFrame();
    virtual void setStateAtTheEndFrame();
    virtual void handleEvent(sf::Event& event);
};


#endif