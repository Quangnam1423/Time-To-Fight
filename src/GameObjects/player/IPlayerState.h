#ifndef IPLAYERSTATE_H
#define IPLAYERSTATE_H

#include <SFML/Graphics.hpp>
#include "PlayerConfigState.h"

class Character;

class IPlayerState
{
public:
    //IPlayerState(const std::string& animationPath , sf::Vector2i frameCount , float timeFrame);
    IPlayerState(Character* character, const char* texturePath, 
                sf::Vector2i frameCount, float timeFrame
        );


    virtual ~IPlayerState() = default;
    virtual void update(float deltaTime);
    virtual void setStateAtTheEndFrame();
    virtual void handlingEvent(sf::Event& event);

    sf::IntRect getCurrentFrame();
    void reset();
    void CalculateNextFrame();
    void CalculateFrameSize();
    sf::Texture& getTexture();

protected:
    Character* m_character;

    enum STATE m_playerState;

    sf::Texture m_texture;

    sf::Vector2i m_frameCount;
    sf::Vector2i m_currentFrame;
    sf::Vector2f m_frameSize;
    sf::Vector2i m_textUV;
    sf::IntRect m_intRect;
    float m_timeFrame;
    float m_durationTime;
    bool m_modeStopAtTheEndFrame;   
};


#endif