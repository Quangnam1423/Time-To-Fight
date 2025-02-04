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

#ifndef IGAMESTATE_H
#define IGAMESTATE_H    

#include <SFML/Graphics.hpp>
#include <unordered_map>
#include <vector>

enum class GAMESTATE
{
    INVALID,
    MENU_STATE,
    INTRODUCE_STATE,
    PLAYIN_STATE,
    PAUSE_STATE,
    END_STATE,
    LOADING_STATE,
    CREDIT_STATE,
    SETTINGS_STATE,
    TUTORIAL_STATE
};

class Button;

class IGameState
{
public:
    virtual ~IGameState() = default;

    virtual void init() = 0;
    virtual void cleanup() = 0;

    // handle state loop

    virtual void handleEvent(sf::Event &event) = 0;
    virtual void update(float deltaTime) = 0;
    virtual void render(sf::RenderWindow& window) = 0;

    // manage states   
    virtual void pause() = 0;
    virtual void resume() = 0;
    virtual void exit() = 0;

    // check state if complete
    virtual bool isFinished() const = 0;
    static IGameState* createState(GAMESTATE newGameState);
};

#endif