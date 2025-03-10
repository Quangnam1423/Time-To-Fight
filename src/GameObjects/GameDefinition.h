/*
MIT License

Copyright (c) 2024 Quangnam1423

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all
copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
SOFTWARE.
*/

#ifndef GAMEDEFINITION_H
#define GAMEDEFINITION_H

#include <SFML/Graphics.hpp>

enum class TAG {
    PLAYER,
    MAP,
    NULLOB
};

enum class DIRECTION
{
    RIGHT,
    LEFT,
    UP,
    DOWN,
    DNULL
};

enum PLAYER_STATE {
    NULLST = -1,
    IDLE = 0,
    ATTACK_1 = 1,
    ATTACK_2 = 2,
    ATTACK_3 = 3,
    RUN = 4,
    WALK = 5,
    JUMP = 6,
    HURT = 7,
    DEAD = 8,
    SHIELD = 9
};

enum PLAYER_DIRECTION
{
    LEFT_DIRECTION,
    RIGHT_DIRECTION,
    SHIELD_DIRECTION,
    JUMP_DIRECTION
};

struct TileInformation {
    sf::Vector2i box;
    DIRECTION direction;
};

struct EnumClassHash {
    template<typename T>
    std::size_t operator() (T t) const {
        return static_cast<std::size_t>(t);
    }
};

#endif