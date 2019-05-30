#include "pch.h"

#include "GameMode.h"
#include <memory>

using namespace std;
using namespace gamestructure;

GameMode* GameMode::instance;

/**
 * A singleton class used to manage unique game objects
 */
GameMode::GameMode()
{
}

 GameMode* GameMode::GetInstance()
{
	if (instance == nullptr) 
	{
		instance = new GameMode();
	}

	return instance;
}

GameMode::~GameMode()
{
	delete instance;
}
