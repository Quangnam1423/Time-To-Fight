#ifndef WALKSTATE_H
#define WALKSTATE_H

#include "IPlayerState.h"

class Character;

class WalkState : public IPlayerState
{
public:
    WalkState(Character* character, 
              const char* texturePath, 
              sf::Vector2i frameCount, 
              float frameTime
    );
    
    ~WalkState();

    void update(float deltaTime) override;
    void setStateAtTheEndFrame() override;
    void handlingEvent(sf::Event& event) override;
};

#endif