#include "GameOnState.h"
#include "../GameManager.h"
#include "../WindowManager.h"
#include "../ResourceManager.h"
#include "../../GameObjects/GameMap/Map1.h"
#include "../../GameObjects/GameMap/MapBase.h"

GameOnState::GameOnState()
{
	m_map = nullptr;
}

GameOnState::~GameOnState()
{
	cleanup();
}

void GameOnState::init()
{
	m_map = new Map1();
	m_map->init();
}

void GameOnState::cleanup()
{
	if (m_map != nullptr)
		delete m_map;
	m_map = nullptr;
}

void GameOnState::handleEvent(sf::Event& event)
{
	m_map->handleEvent(event);
	if (event.type == sf::Event::KeyPressed)
	{
		if (event.key.code == sf::Keyboard::Escape)
		{
			_GM->popState();
		}
	}
}

void GameOnState::update(float deltaTime)
{
	m_map->update(deltaTime);
}

void GameOnState::render(sf::RenderWindow& window)
{
	m_map->render(window);
}

void GameOnState::pause()
{
}

void GameOnState::resume()
{
}

void GameOnState::exit()
{
}

bool GameOnState::isFinished() const
{
	return false;
}
