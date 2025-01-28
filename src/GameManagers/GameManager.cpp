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

#include "GameManager.h"
#include "GAMESTATE/GameState.h"

GameManager::GameManager()
{
	m_activeState = nullptr;
	m_nextState = nullptr;
}

GameManager::~GameManager()
{
	while (!m_gameStateStack.empty())
	{
		delete m_gameStateStack.back();
		m_gameStateStack.pop_back();
	}

	if (m_activeState != nullptr)
		delete m_activeState;
	if (m_nextState != nullptr)
		delete m_nextState;
	
	m_activeState = nullptr;
	m_nextState = nullptr;
	return;
}

void GameManager::changeState(IGameState* gameState)
{
	m_nextState = gameState;
	return;
}

void GameManager::changeState(GAMESTATE gameState)
{
}

void GameManager::pushState(GAMESTATE gameState)
{

}

void GameManager::popState()
{
}

void GameManager::performStateChange()
{
}

IGameState* GameManager::currentState()
{
	return m_activeState;
}

IGameState* GameManager::nextState()
{
	return m_nextState;
}

bool GameManager::needToChangeState()
{
	return false;
}

bool GameManager::hasState()
{
	return m_gameStateStack.size();
}

void GameManager::changeState(GAMESTATE gameState)
{
}