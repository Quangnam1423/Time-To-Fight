// Character.h
#ifndef CHARACTER_H
#define CHARACTER_H

#include <SFML/Graphics.hpp>
#include <string>

//bool loadFromFile(const std::string& filePath);


// path of action
const std::string const_idlePath = "../resource/Samurai/idle.png";
const std::string const_runPath = "../resource/Samurai/Run.png";
const std::string const_jumpPath = "../resource/Samurai/Jump.png";
const std::string const_walkPath = "../resource/Samurai/Walk.png";
const std::string const_attackThirdPath = "../resource/Samurai/attack_3.png";
const std::string const_attackSecondPath = "../resource/Samurai/attack_2.png";
const std::string const_attackFirstPath = "../resource/Samurai/attack_1.png";
const std::string const_hurtPath = "../resource/Samurai/Hurt.png";
const std::string const_deadPath = "../resource/Samurai/dead.png";


// number of action frame
const int const_idleFrame = 6;
const int const_runFrame = 8;
const int const_jumpFrame = 12;
const int const_walkPath = 8;
const int const_attackThird = 3;
const int const_attackSecond = 4;
const int const_attackFirst = 6;
const int const_hurt = 2;
const int const_dead = 3;

class  Character
{
public:
    
    Character(float x , float y);

    void update();
    void render(sf::RenderWindow& gl_window);


    void handlingEvent(sf::Event& event);

private:
    sf::Sprite m_sprite;
    sf::Texture m_idleTexture;
    sf::Texture m_attackFirstTexture , m_attackSecondTexture , m_attackThirdTexture;
    sf::Texture m_jumpTexture;
    sf::Texture m_runTexture;
    sf::Texture m_walkTexture;
    sf::Texture m_hurtTexture;
    sf::Texture m_deadTexture;
    sf::Clock m_animationClock;
    int m_frameWidth;
    int m_frameHeight;
    int m_currentFrame;
    float m_frameDuration;
    sf::Time m_deltaTime;
    int m_statusAction;

    enum State{Idle , Attacking_1 , Attacking_2 , Attacking_3 ,Running , Walking , Jumping , Hurting , Deading} state;


    void updateAnimation();
    void setTextureForCurrentState();
    void setTextureForFirsttime(float x , float y);
    void loadTexture();
    void attack_1();
    void attack_2();
    void attack_3();
    void hurt();
    void dead();
    void jump();
    void block();
    void walk();
    void run();
};

#endif