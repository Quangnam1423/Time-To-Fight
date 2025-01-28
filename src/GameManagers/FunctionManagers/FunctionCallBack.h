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

class IGameState;

// button call back
void audioIconButtonCallBack();
void backButtonCallBack();
void continueButtonCallBack();
void controlsButtonCallBack();
void downIconButtonCallBack();
void exitButtonCallBack();
void homeIconButtonCallBack();
void infoIconButtonCallBack();
void loadButtonCallBack();
void menuButtonCallBack();
void musicButtonCallBack();
void newGameButtonCallBack();
void onOffButtonCallBack();
void optionsButtonCallBack();
void pauseIconButtonCallBack();
void playButtonCallBack();
void playIconButtonCallBack();
void questionmarkIconButtonCallBack();
void quitButtonCallBack();
void resumeIconButtonCallBack();
void returnIconButtonCallBack();
void settingButtonCallBack();
void settingIconButtonCallBack();
void startButtonCallBack();
void upIconButtonCallBack();
void vIconButtonCallBack();
void xIconButtonCallBack();

// macro function call back pointer
#define _AUDIO_ICON_CB &audioIconButtonCallBack
#define _BACK_CB &backButtonCallBack
#define _CONTINUE_CB &continueButtonCallBack
#define _CONTROL_CB &controlsButtonCallBack
#define _DOWN_ICON_CB &downIconButtonCallBack
#define _EXIT_CB &exitButtonCallBack
#define _HOME_ICON_CB &homeIconButtonCallBack
#define _INFO_ICON_CB &infoIconButtonCallBack
#define _LOAD_CB &loadButtonCallBack
#define _MENU_CB &menuButtonCallBack
#define _MUSIC_CB &musicButtonCallBack
#define _NEW_GAME_CB &newGameButtonCallBack
#define _ON_OFF_CB &onOffButtonCallBack
#define _OPTION_CB &optionsButtonCallBack
#define _PAUSE_ICON_CB &pauseIconButtonCallBack
#define _PLAY_CB &playButtonCallBack
#define _PLAY_ICON_CB &playIconButtonCallBack
#define _QUESTIONMARK_ICON_CB &questionmarkIconButtonCallBack
#define _QUIT_CB &quitButtonCallBack
#define _RESUME_ICON_CB &resumeIconButtonCallBack
#define _RETURN_ICON_CB &returnIconButtonCallBack
#define _SETTING_CB &settingButtonCallBack
#define _SETTING_ICON_CB &settingIconButtonCallBack
#define _START_CB &startButtonCallBack
#define _UP_ICON_CB &upIconButtonCallBack
#define _V_ICON_CB &vIconButtonCallBack
#define _X_ICON_CB &xIconButtonCallBack

#endif