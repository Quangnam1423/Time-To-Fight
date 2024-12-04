#ifndef ATTACKTHREESTATE_H
#define ATTACKTHREESTATE_H

#include "IPlayerState.h"

class Character;

class AttackThreeState : public IPlayerState
{
public:
    AttackThreeState(Character* character, const char* texturePath, 
            sf::Vector2i frameCount, 
            float frameTime
    );
    ~AttackThreeState();

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