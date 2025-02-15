#include "GameState.h"

IGameState* createState(enum GAMESTATE newGameState)
{
    if (newGameState == GAMESTATE::MENU_STATE)
    {
        return new MenuGameState();
    }
    else if (newGameState == GAMESTATE::PLAYIN_STATE)
    {
        return new PlayInState();
    }
    else if (newGameState == GAMESTATE::SETTINGS_STATE)
    {
        return new SettingState();
    }
    else if (newGameState == GAMESTATE::INFORMATION_STATE)
    {
        return new InformationState();
    }
    else if (newGameState == GAMESTATE::INTRODUCE_STATE)
    {
        return new IntroState();
    }
    else if (newGameState == GAMESTATE::GAMEON_STATE)
    {
        return new GameOnState();
    }
    else
        return nullptr;
}