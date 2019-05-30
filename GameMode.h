#pragma once
#include <memory>

#include "MainMenu.h"
#include "GameOver.h"
#include "Level1.h"
#include "Page.h"

/* GAME MODE IS SINGLETON!!!!*/
namespace SnakeRevival {
	class GameMode
	{
	private:
		GameMode();
		static GameMode* instance;

		//Current scores
		//current lenght
		//speed
		//time elapsed

	public:
		MainMenu m_Menu;
		GameOver m_GameOver;
		Level1 m_Level1;
		composite::Page *m_CurrentView;

		static GameMode* GetInstance();
		~GameMode();
		std::wstring GetCurrentView();
		//update methods if needed

	};
}