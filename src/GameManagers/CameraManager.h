#ifndef CAMERAMANAGER_H
#define CAMERAMANAGER_H

#include <SFML/Graphics.hpp>
#include "../Singleton.h"

#define CAMERA Camera::getInstance()

class CameraManager : public Singleton<CameraManager>
{
friend class Singleton<CameraManager>;
public:
	CameraManager();
	~CameraManager();
private:
	sf::Vector2f m_SceneSize;
	sf::View m_view;
};

#endif