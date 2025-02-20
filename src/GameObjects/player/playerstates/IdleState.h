#ifndef IDLESTATE_H
#define IDLESTATE_H


#include "IPlayerState.h"

class Character;

class IdleState : public IPlayerState
{
public:
    IdleState(Character* character, 
                const char* texturePath,
                sf::Vector2i frameCount,
                float frameTime
    );
    
    ~IdleState();

    void update(float deltaTime) override;
    void setStateAtTheEndFrame() override;
    void handleEvent(sf::Event& event) override;
};

#endif