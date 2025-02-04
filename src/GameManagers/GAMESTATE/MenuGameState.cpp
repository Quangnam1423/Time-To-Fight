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

#include "MenuGameState.h"
#include "../Resource.h"
#include "../../GameObjects/Button.h"
#include "../FunctionManagers/FunctionCallBack.h"
#include "../WindowManager.h"
#include <iostream>

MenuGameState::MenuGameState()
{
    init();
}

MenuGameState::~MenuGameState()
{
    cleanup();
    return;
}

void MenuGameState::init()
{
    std::cout << "Menu" << std::endl;
    Button* playButton = new Button(_RM->getTexture("Play", TEXTURE_TYPE::BUTTON),
                                    sf::Vector2f(100.0f, 10.0f),
                                    BUTTON_TYPE::PLAY_BUTTON);
    playButton->setCallBack([]()
        {
            std::cout << "set call back function for playButton" << std::endl;
        });
    m_buttons.push_back(playButton);
/*
    Button* settingsButton = new Button(this,
                _RM->getTexture("Settings", TEXTURE_TYPE::BUTTON),
                _SETTING_CB,
                sf::Vector2f(100.0f, 110.0f),
                "Settings Button",
                BUTTON_TYPE::SETTINGS_BUTTON
           );
    m_buttons.push_back(settingsButton);

    Button* optionButton = new Button(this,
                _RM->getTexture("Option", TEXTURE_TYPE::BUTTON),
                _OPTION_CB,
                sf::Vector2f(100.0f, 210.0f),
                "Opstion Button",
                BUTTON_TYPE::OPTIONS_BUTTON
          );
    m_buttons.push_back(optionButton);

    Button* exitButton = new Button(this, 
                _RM->getTexture("Exit", TEXTURE_TYPE::BUTTON),
                _EXIT_CB,
                sf::Vector2f(100.0f, 310.0f),
                "Exit Button",
                BUTTON_TYPE::EXIT_BUTTON
          );
    m_buttons.push_back(exitButton);

    Button* audioIconButton = new Button(this,
                _RM->getTexture("Audio Icon", TEXTURE_TYPE::BUTTON),
                _AUDIO_ICON_CB,
                sf::Vector2f(500.0f, 100.0f),
                "Audio Icon Button",
                BUTTON_TYPE::AUDIO_ICON_BUTTON
            );
    m_buttons.push_back(audioIconButton);

    Button* infoIconButton = new Button(this, 
                _RM->getTexture("Info Icon", TEXTURE_TYPE::BUTTON),
                _INFO_ICON_CB,
                sf::Vector2f(500.0f, 200.0f),
                "Info Icon Button",
                BUTTON_TYPE::INFO_ICON_BUTTON
        );
    m_buttons.push_back(infoIconButton);
*/
    // load background 
    m_background = new sf::Sprite(*_RM->getTexture("Main BackGround", TEXTURE_TYPE::ENVIROMENT));
    m_background->setScale(sf::Vector2f(2.0f, 2.0f));
    m_background->setOrigin((sf::Vector2f)m_background->getTexture()->getSize() / 2.0f);
    return;
}

void MenuGameState::cleanup()
{
    for (Button* button : m_buttons)
    {
        if (button != nullptr)
        {
            delete button;
        }
    }
    if (m_background != nullptr)
        delete m_background;
    m_buttons.clear();
    return;
}

void MenuGameState::handleEvent(sf::Event &event)
{
    std::cout << "handle event of menu GameState" << std::endl;
    return;
}

void MenuGameState::update(float deltaTime)
{
    for (Button* button : m_buttons)
    {
        button->update(deltaTime, *_MAIN_WINDOW->getWindow());
    }
    return;
}

void MenuGameState::render(sf::RenderWindow &window)
{
    // check if m_background not nullptr
    if (m_background)
        window.draw(*m_background);
    for (Button* button : m_buttons)
    {
        button->render(window);
    }
    return;
}

void MenuGameState::pause()
{
    std::cout << "Menu paused" << std::endl;

    return;
}

void MenuGameState::resume()
{
    std::cout << "Menu resume" << std::endl;
    return;
}

void MenuGameState::exit()
{
}

bool MenuGameState::isFinished() const
{
    // check if State is Finished or not ?
    return false;
}
