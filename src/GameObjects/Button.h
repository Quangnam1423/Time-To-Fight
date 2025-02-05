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

#ifndef BUTTON_H
#define BUTTON_H

#include <SFML/Graphics.hpp>

#define _REACT_TIME_BUTTON 2.0f

// button size 
#define ButtonDefaultSize sf::Vector2f(0.3f, 0.3f)
#define ButtonHoverSize sf::Vector2f(0.31f, 0.31f)
#define ButtonActiveSize sf::Vector2f(0.28f, 0.28f)

// button color 
#define ButtonDefaultColor sf::Color::White
#define ButtonHoverColor sf::Color(200, 200, 255)
#define ButtonActiveColor sf::Color(100, 100, 255)

enum class BUTTON_STATE {
    DEFAULT,
    HOVER,
    ACTIVE
};

enum class BUTTON_TYPE
{
    AUDIO_ICON_BUTTON,
    BACK_BUTTON,
    CONTINUE_BUTTON,
    CONTROLS_BUTTON,
    DOWN_ICON_BUTTON,
    EXIT_BUTTON,
    HOME_ICON_BUTTON,
    INFO_ICON_BUTTON,
    LEFT_ICON_BUTTON,
    LOAD_BUTTON,
    MENU_BUTTON,
    MUSIC_ICON_BUTTON,
    NEW_GAME_BUTTON,
    ON_OFF_BUTTON,
    OPTIONS_BUTTON,
    PAUSE_ICON_BUTTON,
    PLAY_BUTTON,
    PLAY_ICON_BUTTON,
    QUESTIONMARK_ICON_BUTTON,
    QUIT_BUTTON,
    RESUME_BUTTON,
    RETURN_ICON_BUTTON,
    SETTINGS_BUTTON,
    SETTINGS_ICON_BUTTON,
    START_BUTTON,
    UP_ICON_BUTTON,
    V_ICON_BUTTON,
    X_ICON_BUTTON
};


class IGameState;

class Button
{
public:
    Button(sf::Texture* texture, 
            sf::Vector2f position, 
            BUTTON_TYPE type);
    ~Button();
    void init(sf::Texture* texture, sf::Vector2f position, BUTTON_TYPE type);
    void render(sf::RenderWindow& window);
    void update(float deltaTime, sf::RenderWindow& window);
    bool checkHover(sf::RenderWindow& window);
    bool checkIsClicked(sf::RenderWindow& window);
    void handleEvent(sf::Event& event);
    void setCallBack(void(*callbackfunction)());
private:
    void (*m_callbackFunction)();
    sf::Sprite* m_sprite;
    enum BUTTON_TYPE m_buttonType;
    enum BUTTON_STATE m_buttonState;
};

#endif
