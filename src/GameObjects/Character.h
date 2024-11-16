// Character.h
#ifndef CHARACTER_H
#define CHARACTER_H

#include <SFML/Graphics.hpp>
#include <string>
#include <map>

// path of action
const char* const_idlePath = "../resource/Samurai/idle.png";
const char* const_runPath = "../resource/Samurai/Run.png";
const char* const_jumpPath = "../resource/Samurai/Jump.png";
const char* const_walkPath = "../resource/Samurai/Walk.png";
const char* const_attackThirdPath = "../resource/Samurai/attack_3.png";
const char* const_attackSecondPath = "../resource/Samurai/attack_2.png";
const char* const_attackFirstPath = "../resource/Samurai/attack_1.png";
const char* const_hurtPath = "../resource/Samurai/Hurt.png";
const char* const_deadPath = "../resource/Samurai/dead.png";


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

class Action;

enum State{ 
    Idle , 
    Attacking_1 , 
    Attacking_2 , 
    Attacking_3 ,
    Running , 
    Walking , 
    Jumping , 
    Hurting , 
    Deading
};

class  Character
{
    public:
        
        Character(float x , float y);

        void update();
        void render(sf::RenderWindow& gl_window);
        void callbackEndingAnimation();

        void handlingEvent(sf::Event& event);

    private:
        sf::Sprite* m_sprite;
        sf::Clock m_animationClock;
        sf::Time m_deltaTime;
        int m_statusAction;
        enum State state;

        void updateAnimation();
        void setTextureForCurrentState();
        void setTextureForFirsttime(float x , float y);


        void attack_1(sf::Event& event);
        void attack_2(sf::Event& event);
        void attack_3(sf::Event& event);
        void hurt(sf::Event& event);
        void dead(sf::Event& event);
        void jump(sf::Event& event);
        void block(sf::Event& event);
        void walk(sf::Event& event);
        void run(sf::Event& event);
};

#endif