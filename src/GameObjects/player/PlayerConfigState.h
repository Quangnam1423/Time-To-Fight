#ifndef PLAYERCONFIGSTATE_H
#define PLAYERCONFIGSTATE_H

#include <iostream>


// path of action
const char* const_idlePath = "../resource/Samurai/idle.png";
const char* const_runPath = "../resource/Samurai/Run.png";
const char* const_jumpPath = "../resource/Samurai/Jump.png";
const char* const_walkPath = "../resource/Samurai/Walk.png";
const char* const_attack_1Path = "../resource/Samurai/attack_3.png";
const char* const_attack_2Path = "../resource/Samurai/attack_2.png";
const char* const_attack_3Path = "../resource/Samurai/attack_1.png";
const char* const_hurtPath = "../resource/Samurai/Hurt.png";
const char* const_deadPath = "../resource/Samurai/dead.png";


// number of action frame
const int const_idleFrame = 6;
const int const_runFrame = 8;
const int const_jumpFrame = 12;
const int const_walkPath = 8;
const int const_attack_3 = 3;
const int const_attack_2 = 4;
const int const_attack_1 = 6;
const int const_hurt = 2;
const int const_dead = 3;



enum State{ 
    IDLE  = 0, 
    ATTACK_1 = 1, 
    ATTACK_2 = 2, 
    ATTACK_3 = 3,
    RUN = 4, 
    WALK = 5, 
    JUMP = 6, 
    HURT = 7, 
    DEAD = 8
};

struct EnumClassHash{
    template<typename T>
    std::size_t operator() (T t) const{
        return static_cast<std::size_t>(t);
    }
};

#endif