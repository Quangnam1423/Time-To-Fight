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


#ifndef BUTTONCONFIG_H
#define BUTTONCONFIG_H

//#define _RESOURCE_TEXTURE_MENU_BUTTON 
//"resource/menubuttons/largebuttons/coloredlargebuttons"

// scale point for drawable objects
#define _IDLE_SCALE sf::Vector2f(0.5f, 0.05)
#define _HOVER_SCALE sf::Vector2f(0.6f, 0.6f)
#define _ACTIVE_SCALE sf::Vector2f(0.4f, 0.4f)

// color for hover shape
#define _HOVERSHAPE_COLOR sf::Color(255, 0, 0, 100)

#define _REACT_TIME_BUTTON 2.0f

enum class BUTTON_STATE{
    IDLE,
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

#endif