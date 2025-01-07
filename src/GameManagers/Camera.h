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

#ifndef CAMERA_H
#define CAMERA_H

#include <SFML/Graphics.hpp>
#include <SFML/Graphics/View.hpp>

#define _ZOOM_LEVEL 45.0f
//#define 

class GameManager;
class Character;

class Camera
{
public:
    Camera(); // default contructor
    Camera(sf::Vector2f size, sf::Vector2f center);
    ~Camera();
    void init();
    void update(float deltaTime);
    void handleEvent(sf::Event& event);
    sf::View* getView();
    void setCharater(Character* character);
    void setGameManager(GameManager* gameManager);
    Character* getCharacter();
    GameManager* getGameManager();
    void setAspect(sf::Vector2u windowSize);

private:
    GameManager* m_gameManager;
    Character* m_character;
    sf::View* m_view;
    float m_durationTime;
    float m_elapsedTime;
    float m_aspect;

    sf::Vector2f m_cameraPosition;
    sf::Vector2f m_size;
    sf::Vector2f m_cameraDirection;
};

#endif  