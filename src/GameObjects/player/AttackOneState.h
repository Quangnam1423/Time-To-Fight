#ifndef ATTACKONESTATE_H
#define ATTACKONESTATE_H

#include "IPlayerState.h"

class Character;

class AttackOneState : public IPlayerState
{
public:
    AttackOneState(Character* character, const char* texturePath, 
            sf::Vector2i frameCount, 
            float frameTime
    );
    ~AttackOneState();

    void update(float deltaTime) override;
    void setStateAtTheEndFrame() override;
    void handleEvent(sf::Event& event) override;

    using IPlayerState::CalculateFrameSize;
    using IPlayerState::CalculateNextFrame;
    using IPlayerState::getCurrentFrame;
    using IPlayerState::getTexture;
    using IPlayerState::reset;
    //using IPlayerState::update;
private:

};

#endif