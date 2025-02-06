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
#include "../ResourceManager.h"
#include "../../GameObjects/Button.h"
#include "../WindowManager.h"
#include "../GameManager.h"
#include "../../Application.h"
#include <iostream>

MenuGameState::MenuGameState()
{
}

MenuGameState::~MenuGameState()
{
    cleanup();
    return;
}

void MenuGameState::init()
{
    //PLAY BUTTON.......................................................................
    Button* playButton = new Button(DATA->getTexture("Buttons/Play Button"),
                                    sf::Vector2f(400.0f, 150.0f),
                                    BUTTON_TYPE::PLAY_BUTTON);
    playButton->setCallBack(
        [](){
            std::cout << "play button callback" << std::endl;
            _GM->changeState(GAMESTATE::PLAYIN_STATE);
        }
    );
    m_buttons.push_back(playButton);

    //SETTING BUTTON............................................................................
    Button* settingButton = new Button(DATA->getTexture("Buttons/Settings Button"),
                                       sf::Vector2f(400.0f, 250.0f),
                                       BUTTON_TYPE::SETTINGS_BUTTON);
    settingButton->setCallBack(
        []() {
            std::cout << "setting button callback" << std::endl;
        }
    );
    m_buttons.push_back(settingButton);

    //OPTIONS BUTTON..........................................................................
    Button* optionButton = new Button(DATA->getTexture("Buttons/Options Button"),
        sf::Vector2f(400.0f, 350.0f),
        BUTTON_TYPE::OPTIONS_BUTTON);
    optionButton->setCallBack(
        []() {
            std::cout << "option button callback" << std::endl;
        }
    );
    m_buttons.push_back(optionButton);

    //QUIT BUTTON............................................................................
    Button* quitButton = new Button(DATA->getTexture("Buttons/Quit Button"),
                                    sf::Vector2f(400.0f, 450.0f),
                                    BUTTON_TYPE::QUIT_BUTTON);
    quitButton->setCallBack(
        []() {
            _MAIN_WINDOW->close();
        }
    );
    m_buttons.push_back(quitButton);

    //INTRODUCE BUTTON...............................................................................
    Button* introButton = new Button(DATA->getTexture("Buttons/Questionmark Icon Button"),
                                    sf::Vector2f(750.0f, 550.0f),
                                    BUTTON_TYPE::QUESTIONMARK_ICON_BUTTON);
    introButton->setCallBack(
        []() {
            std::cout << "intro button" << std::endl;
            system("start https://github.com/Quangnam1423");
            _GM->changeState(GAMESTATE::INFORMATION_STATE);
        }
    );
    m_buttons.push_back(introButton);

    // BACKGROUND................................................................................
    m_background = new sf::Sprite(*DATA->getTexture("Main BackGround"));
    m_background->setScale(sf::Vector2f(1.4f, 1.4f));
    m_background->setOrigin((sf::Vector2f)m_background->getTexture()->getSize() / 2.0f);
    m_background->setPosition(400, 300);
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
    for (Button* button : m_buttons)
    {
        button->handleEvent(event);
    }
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
