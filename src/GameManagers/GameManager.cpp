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
	IGameState* gs = IGameState::createState(gameState);
	changeState(gs);
	return;
}

void GameManager::pushState(GAMESTATE gameState)
{
	IGameState* gs = IGameState::createState(gameState);
	if (!m_gameStateStack.empty())
	{
		m_gameStateStack.back()->pause();
	}
	m_nextState = gs;
	return;
}

void GameManager::popState()
{
	if (hasState())
	{
		m_gameStateStack.pop_back();
	}
	if (hasState())
	{
		m_activeState = m_gameStateStack.back();
	}
	return;
}

void GameManager::performStateChange()
{
	if (m_nextState != nullptr)
	{
		if (hasState())
		{
			m_gameStateStack.back()->exit();
		}
		m_gameStateStack.push_back(m_nextState);
		m_gameStateStack.back()->init();
		m_activeState = m_gameStateStack.back();
	}
	m_nextState = nullptr;
	return;
}

IGameState* GameManager::currentState()
{
	if (hasState())
	{
		return m_gameStateStack.back();
	}
	return nullptr;
}

IGameState* GameManager::nextState()
{
	return m_nextState;
}

bool GameManager::needToChangeState()
{
	return m_nextState != nullptr;
}

bool GameManager::hasState()
{
	return m_gameStateStack.size();
}