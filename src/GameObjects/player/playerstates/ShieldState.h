#ifndef SHIELDSTATE_H
#define SHIELDSTATE_H

#include "IPlayerState.h"

class Character;

class ShieldState : public IPlayerState
{
public:
    ShieldState(Character* character, const char* texturePath, 
            sf::Vector2i frameCount, 
            float frameTime
    );
    ~ShieldState();

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