#ifndef JUMPSTATE_H
#define JUMPSTATE_H

#include <SFML/Graphics.hpp>
#include "IPlayerState.h"

class Character;

class JumpState : public IPlayerState
{
public:
    JumpState(Character* character, const char* texturePath, 
            sf::Vector2i frameCount, 
            float frameTime
    );
    ~JumpState();

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