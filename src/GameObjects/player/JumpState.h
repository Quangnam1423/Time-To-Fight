#ifndef JUMPSTATE_H
#define JUMPSTATE_H

#include <SFML/Graphics.hpp>
#include "IPlayerState.h"
#include "PlayerState.h"

class Character;

class JumpState : public IPlayerState
{
    public:
        JumpState(const std::string* texturePath, 
                sf::Vector2i frameCount, 
                sf::Vector2i frameSize, 
                float frameTime
        );
        ~JumpState();
        sf::IntRect getCurrentFrame() override;
        void update(float deltaTime) override;
        void setStateAtTheEndFrame() override;

        void reset();
        void CaculateNextFrame();
        sf::Texture& getTexture();

    private:
        
        Character* m_character;

        enum State m_playerState;

        sf::Texture m_texture;

        sf::Vector2i m_frameCount;
        sf::Vector2i m_currentFrame;
        sf::Vector2f m_frameSize;
        sf::Vector2i m_textUV;
        sf::IntRect m_intRect;
        float m_timeFrame;
        bool m_modeStopAtTheEndFrame;
};


#endif