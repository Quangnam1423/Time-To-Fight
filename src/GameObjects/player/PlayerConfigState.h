#ifndef PLAYERCONFIGSTATE_H
#define PLAYERCONFIGSTATE_H

#include <iostream>


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