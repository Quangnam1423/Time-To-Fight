#ifndef WALKSTATE_H
#define WALKSTATE_H

#include "IPlayerState.h"

class Character;

class WalkState : public IPlayerState
{
public:
    WalkState(Character* character, const char* texturePath, 
            sf::Vector2i frameCount, 
            float frameTime
    );
    ~WalkState();

    void update(float deltaTime) override;
    void setStateAtTheEndFrame() override;
    void handleEvent(sf::Event& event) override;

    using IPlayerState::CalculateFrameSize;
    using IPlayerState::CalculateNextFrame;
    using IPlayerState::getCurrentFrame;
    using IPlayerState::getTexture;
    using IPlayerState::reset;
private:

};

#endif