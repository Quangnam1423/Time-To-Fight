#ifndef ATTACKTWOSTATE_H
#define ATTACKTWOSTATE_H

#include "IPlayerState.h"

class Character;

class AttackTwoState : public IPlayerState
{
public:
    AttackTwoState(Character* character, const char* texturePath, 
            sf::Vector2i frameCount, 
            float frameTime
    );
    ~AttackTwoState();

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