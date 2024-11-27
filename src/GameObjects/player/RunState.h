#ifndef RUNSTATE_H
#define RUNSTATE_H

#include "IPlayerState.h"

class Character;

class RunState : public IPlayerState
{
public:
    RunState(Character* character, const std::string* texturePath, 
            sf::Vector2i frameCount, 
            float frameTime = 0.1f
    );
    ~RunState();

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