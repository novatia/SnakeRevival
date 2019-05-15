#include "pch.h"

#include "GameMode.h"
#include <memory>

using namespace std;

GameMode::GameMode()
{
}


GameMode* GameMode::GetInstance()
{
	if (instance == nullptr) 
	{
		instance = new unique_ptr <GameMode>( new GameMode() );
	}

	return instance->get();
}

GameMode::~GameMode()
{
	instance->release();
}
