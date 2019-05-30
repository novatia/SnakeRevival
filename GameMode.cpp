#include "pch.h"

#include "GameMode.h"
#include <memory>

using namespace std;
using namespace SnakeRevival;

GameMode* GameMode::instance;

/**
 * A singleton class used to manage unique game objects
 */
GameMode::GameMode()
{
	m_CurrentView = &m_Menu;
	//m_CurrentView = &m_GameOver;
	//m_CurrentView = &m_Level1;
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

wstring GameMode::GetCurrentView()
{
	if (m_CurrentView==NULL)
		return L"null view";

	return m_CurrentView->GetView();
}
