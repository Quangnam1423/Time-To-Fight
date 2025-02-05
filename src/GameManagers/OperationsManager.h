#ifndef OPERATOR_MANAGER_H
#define OPERATOR_MANAGER_H

#include <SFML/Graphics.hpp>
#include "../Singleton.h"

#define _OPERATOR OperationsManager::getInstance()

class OperationsManager : public Singleton<OperationsManager>
{
friend class Singleton<OperationsManager>;

public:
	OperationsManager();
	~OperationsManager();

	void createNewGame();
	void readFile();
	void saveFile();
	void continueGame();
};

#endif