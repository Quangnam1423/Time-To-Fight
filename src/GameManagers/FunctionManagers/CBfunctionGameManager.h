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

#ifndef FUNCTIONCALLBACK_H
#define FUNCTIONCALLBACK_H

#include <SFML/Graphics.hpp>
#include <iostream>
#include <cstring>
#include <cmath>

#include "../gamebuttons/Button.h"
#include "../GameManager.h"
#include "../../GameObjects/player/Character.h"
#include "../../GameObjects/Hitbox.h"
#include "../../GameObjects/spectaculars/Floor.h"



void callBackMenuButton(sf::RenderWindow* window, Button* menuButton, GameManager* gameManager);
void callBackIntroduceButton(sf::RenderWindow* window, Button* introduceButton, GameManager* gameManager);
void callBackPlayinButton(sf::RenderWindow* window, Button* playButton, GameManager* gameManager);
void callBackPauseButton(sf::RenderWindow* window, Button* pauseButton, GameManager* gameManager);
void callBackNextButton(sf::RenderWindow* window, Button* nextButton, GameManager* gameManager);
void callBackContinueButton(sf::RenderWindow* window, Button* continueButton, GameManager* gameManager);
void callBackSettingButton(sf::RenderWindow* window, Button* settingutton, GameManager* gameManager);
bool callBackNewGameButton(sf::RenderWindow* window, Button* newGameButton, GameManager* gameManager);
void callBackQuitButton(sf::RenderWindow* window, Button* quitButton, GameManager* gameManager);
void callBackResumeButton(sf::RenderWindow* window, Button* resumeButton, GameManager* gameManager);
void callBackOptionButton(sf::RenderWindow* window, Button* optionButton, GameManager* gameManger);
void callBackStartButton(sf::RenderWindow* window, Button* startButton, GameManager* gameManager);


#endif