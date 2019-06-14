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
		clock_t m_elapsed_ticks;
		clock_t m_start_tick;
		clock_t m_end_tick;
		std::chrono::milliseconds m_elapsed_ms;
		std::chrono::milliseconds m_sleep_time_interval_ms;
		//long m_cycle_duration_test_ms;
		static std::wstring m_ElapsedTicksPerformance;

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

		static std::wstring GetElapsedTicksPerformance();
	};
}