#pragma once
#include "GameMode.h"
#include "MainMenu.h"
#include "Display.h"
#include "Commands.h"

namespace SnakeRevival {
	class SnakeRevivalGameLoop
	{

	private:
		std::list<IEntity> m_GameEntities;
		GameMode* m_GameMode;
		Display*  m_GameView;
		bool f_GameOver;
		bool f_Pause;
		std::wstring m_UpdatedDisplay;

		commands::MoveRightCommand* m_RightCommand;
		commands::MoveLeftCommand* m_LeftCommand;
		commands::MoveUpCommand* m_UpCommand;
		commands::MoveDownCommand* m_DownCommand;

	public:
		SnakeRevivalGameLoop();
		~SnakeRevivalGameLoop();
		void Start();
		void Render();
		void Update();
		void Input();
		void GameLoop(clock_t ticks_per_frame);
	};
}