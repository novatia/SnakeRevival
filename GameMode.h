#pragma once
#include <memory>
#include "MainMenu.h"
#include "GameOver.h"
#include "Level1.h"

namespace gamestructure {
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
		MainMenu menu;
		GameOver gameover;
		Level1 level1;

		static GameMode* GetInstance();
		~GameMode();
		//update methods if needed

	};
}