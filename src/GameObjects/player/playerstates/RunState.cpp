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

#include "RunState.h"
#include "../Character.h"

RunState::RunState(Character* character, 
                    const char* texturePath, 
                    sf::Vector2i frameCount, 
                    float frameTime) : 
        IPlayerState(character, 
                    texturePath, 
                    frameCount, 
                    frameTime
                    )
{

}

RunState::~RunState()
{
    IPlayerState::~IPlayerState();
}


void RunState::update(float deltaTime)
{
    m_durationTime += deltaTime;
    if (m_durationTime >= m_timeFrame)
    {
        if (!checkEndFrame())
        {
            CalculateNextFrame();
        }
        else
        {
            reset();
        }
        resetDurationTime();
    }
}

void RunState::setStateAtTheEndFrame()
{
    m_character->setState(STATE::IDLE, m_durationTime);
    reset();
    resetDurationTime();
}

void RunState::handlingEvent(sf::Event &event)
{

}