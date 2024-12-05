#ifndef IDLESTATE_H
#define IDLESTATE_H


#include "IPlayerState.h"

class Character;

class IdleState : public IPlayerState
{
public:
    IdleState(Character* character, const char* texturePath,
                sf::Vector2i frameCount,
                float frameTime
    );
    ~IdleState();

    void update(float deltaTime) override;
    void setStateAtTheEndFrame() override;
    void handlingEvent(sf::Event& event) override;

    using IPlayerState::CalculateFrameSize;
    using IPlayerState::CalculateNextFrame;
    using IPlayerState::getCurrentFrame;
    using IPlayerState::getTexture;
    using IPlayerState::reset;
    //using IPlayerState::update;
private:
    
};

#endif