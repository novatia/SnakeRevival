#pragma once
#include "Display.h"
#include "IEntity.h"
#include "Page.h"
#include "MainMenu.h"
#include "GameOver.h"
#include "Level1.h"
#include "Page.h"

namespace SnakeRevival {
	class SnakeRevivalGameLoop
	{

	private:
		static SnakeRevivalGameLoop* m_Instance;
		SnakeRevivalGameLoop();

		//Gameplay params
		
		int m_Scores;

		Display*  m_GameView;

		bool f_Pause;
		
		std::wstring m_UpdatedDisplay;

		//std::list<IEntity> m_GameEntities;

	public:
		float m_TimeElapsed;
		composite::MainMenu m_Menu;
		composite::GameOver m_GameOver;
		composite::Level1 m_Level1;

		//current view
		composite::Page *m_CurrentView;

		static SnakeRevivalGameLoop *GetInstance();
		~SnakeRevivalGameLoop();
		void Start();
		void Render();
		void Update();
		void Input();
		void GameLoop(clock_t ticks_per_frame);
	};
}