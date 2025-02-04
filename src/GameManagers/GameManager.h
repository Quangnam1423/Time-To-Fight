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

#ifndef GAMEMANAGER_H
#define GAMEMANAGER_H

#include <SFML/Graphics.hpp>
#include <unordered_map>

#include "../Singleton.h"
#include "GAMESTATE/GameState.h"

#define _GM GameManager::getInstance()

class IGameState;

class GameManager : public Singleton<GameManager>
{
friend class Singleton<GameManager>;
public:
    GameManager();
    ~GameManager();

    void changeState(IGameState* gameState);
    void changeState(enum GAMESTATE gameState);
    void pushState(GAMESTATE gameState);
    void popState();
    void performStateChange();
    IGameState* currentState();
    IGameState* nextState();
    bool needToChangeState();
    bool hasState();
private:
    std::list<IGameState*> m_gameStateStack;
    IGameState* m_activeState;
    IGameState* m_nextState;
};

#endif